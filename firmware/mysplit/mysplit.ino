// MySplit

#define HOST_SIDE

#include "Keyboard.h"
#include "keymap.h"

const int rowPins[ROW_NUM] = { 2, 3, 4, 5 }; // OUTPUTのピン。走査ピン
const int colPins[COL_NUM] = { 6, 7, 8, 9, 10, 14, 15 }; // INPUT_PULLUPのピン。

bool currentState[ROW_NUM][COL_NUM_2]; // 現在のループでの押下状態
bool beforeState[ROW_NUM][COL_NUM_2];  // 前のループでの押下状態
int pressedKeyCode[ROW_NUM][COL_NUM_2]; // 押下したキー
unsigned long pressedKeyTime[ROW_NUM][COL_NUM_2]; // 押下してからの経過時間（マイクロ秒）
bool raiseLayerKey = 0;
bool lowerLayerKey = 0;

#define IGNORE_TIME_MICROS 16000 // 押下状態の変化を無視する時間（マイクロ秒）

void setup() {
    for (int i = 0; i < ROW_NUM; i++) {
        int pin = rowPins[i];
        pinMode(pin, OUTPUT);
        digitalWrite(pin, HIGH);
    }
    for (int i = 0; i < COL_NUM; i++) {
        int pin = colPins[i];
        pinMode(pin, INPUT_PULLUP);
    }

    for (int i = 0; i < ROW_NUM; i++) {
        for (int j = 0; j < COL_NUM_2; j++) {
            currentState[i][j] = HIGH;
            beforeState[i][j] = HIGH;
            pressedKeyCode[i][j] = KC_NULL;
            pressedKeyTime[i][j] = 0;
        }
    }

    Serial.begin(9600);
    Serial1.begin(9600);
#ifdef HOST_SIDE
    Keyboard.begin();
#endif
}

#ifdef HOST_SIDE
void loop() {
    getThisSideState();
    getOtherSideState();
    applyKeyState();
}
#else
void loop() {
    getThisSideState();
    sendThisSideState();
}
#endif

void getThisSideState() {
    for (int i = 0; i < ROW_NUM; i++) {
        int rowPin = rowPins[i];
        digitalWrite(rowPin, LOW);
        for (int j = 0; j < COL_NUM; j++)  {
            int colPin = colPins[j];
            currentState[i][j] = digitalRead(colPin);
        }
        digitalWrite(rowPin, HIGH);
    }
}

#ifdef HOST_SIDE
void getOtherSideState() {
    while (true) {
        if (!Serial1.available()) break;

        byte readData = Serial1.read();
        if (readData == -1) break;

        // 通信方式について
        // 0bABCDEFGH
        // AB  ... 状態。00:無効 01:Press 10:Release 11:後続データなし
        // CDE ... rowPinの番号（右手用の範囲内で。したがって0～5）
        // FGH ... colPinの番号（右手用の範囲内で。したがって0～6）

        // bool eof     = (bool) ((readData & 0b10000000) == 0b10000000);
        // bool isPress = (bool) ((readData & 0b01000000) == 0b00000000);
        int state    = (int)  ((readData & 0b11000000) >> 6);
        int rowPin   = (int)  ((readData & 0b00111000) >> 3);
        int colPin   = (int)  ( readData & 0b00000111 );

        bool eof = (state == 0b11) || (state == 0b00);
        bool isPress = state == 0b01;
        if (rowPin >= ROW_NUM) rowPin = ROW_NUM - 1;
        if (colPin >= COL_NUM) colPin = COL_NUM - 1;

        if (eof) { break; }

        // Serial.print("Receive: ");
        // Serial.print(readData, BIN);
        // Serial.print(" r=");
        // Serial.print(rowPin);
        // Serial.print(" c=");
        // Serial.print(colPin);
        // Serial.print("  ->  ");

        // printKeyEvent(rowPin, colPin, isPress, 0);
        // ホスト：左手、サブ：右手
        currentState[rowPin][colPin + COL_NUM] = isPress ? LOW : HIGH;
    }
}
void applyKeyState() {
    // Raise Layer、Lower Layer が押されているかを取得
    for (int i = 0; i < ROW_NUM; i++) {
        for (int j = 0; j < COL_NUM_2; j++)  {
            if (currentState[i][j] != beforeState[i][j]) {
                if (keyMap[i][j] == KC_RISE) {
                    raiseLayerKey = currentState[i][j] == LOW;
                    beforeState[i][j] = currentState[i][j];
                }
                if (keyMap[i][j] == KC_LOWR) {
                    lowerLayerKey = currentState[i][j] == LOW;
                    beforeState[i][j] = currentState[i][j];
                }
            }
        }
    }
    int layer = 0; // -1: Lower  0: Base  1: Raise
    if (raiseLayerKey) layer++;
    if (lowerLayerKey) layer--;

    // キーを送る
    int keyCode;
    for (int i = 0; i < ROW_NUM; i++) {
        for (int j = 0; j < COL_NUM_2; j++)  {
            // チャタリング防止のための待ち処理
            if (pressedKeyTime[i][j] > 0) {
                unsigned long elapsed = micros() - pressedKeyTime[i][j];
                if (elapsed < IGNORE_TIME_MICROS) {
                    continue;
                } else {
                    pressedKeyTime[i][j] = 0;
                }
            }
            // 押下状態の変化を検出してキーを送る
            if (currentState[i][j] != beforeState[i][j]) {
                if (currentState[i][j] == LOW) {
                    if (layer == 0) keyCode = keyMap[i][j];
                    else if (layer > 0) keyCode = keyMapRaise[i][j];
                    else if (layer < 0) keyCode = keyMapLower[i][j];
                    // keyCode = currentMap[i][j];
                    if (keyCode == KC_NULL) keyCode = keyMap[i][j];
                    if (keyCode == KC_RISE) continue;
                    if (keyCode == KC_LOWR) continue;

                    pressedKeyCode[i][j] = keyCode;
                    pressedKeyTime[i][j] = micros();

                    if (keyCode == KC_CTSP)  {
                        // 特殊キー Ctrl+Space の押下
                        Keyboard.press((char) KC_LCTL);
                        Keyboard.press((char) KC_SPC);
                        // 特殊キー Ctrl+Space の即時リリース
                        Keyboard.release((char) KC_SPC);
                        Keyboard.release((char) KC_LCTL);
                        delay(1);
                    } else {
                        // 通常キーの押下
                        Keyboard.press((char) keyCode);
                    }
                    // printKeyEvent(i, j, true, layer);
                    // printPressedKey(keyCode);
                } else {
                    keyCode = pressedKeyCode[i][j];
                    pressedKeyCode[i][j] = KC_NULL;

                    if (keyCode == KC_CTSP)  {
                        // 特殊キー Ctrl+Space のリリース
                        // 即時リリース扱いでリリースされているので処理不要
                    } else {
                        // 通常キーのリリース
                        Keyboard.release((char) keyCode);
                    }
                    // printKeyEvent(i, j, false, layer);
                    // printPressedKey(keyCode);
                }
            }
            beforeState[i][j] = currentState[i][j];
        }
    }
}
#endif

#ifndef HOST_SIDE
void sendThisSideState() {
    if (!Serial1.availableForWrite()) return;

    bool sentFlag = false;
    int state;
    byte sendData = 0b00000000;

    for (int i = 0; i < ROW_NUM; i++) {
        for (int j = 0; j < COL_NUM; j++) {
            if (currentState[i][j] != beforeState[i][j]) {
                if (currentState[i][j] == LOW) {
                    // printKeyEvent(i, j, true, 0);
                    state = 0b01000000;
                } else {
                    // printKeyEvent(i, j, false, 0);
                    state = 0b10000000;
                }
                sendData = (byte) (state | i << 3 | j);
                sentFlag = true;
                // Serial.print("Send: ");
                // Serial.println(sendData);
                Serial1.write(sendData);
            }
            beforeState[i][j] = currentState[i][j];
        }
    }
    if (sentFlag) Serial1.write(0b11111111); // 後続データなしを送信
}
#endif

void printKeyEvent(int row, int col, bool isPress, int layer) {
    if (isPress) {
        Serial.print("PRESS   (");
    } else {
        Serial.print("RELEASE (");
    }
    Serial.print(row);
    Serial.print(", ");
    Serial.print(col);
    Serial.print(", ");
    Serial.print(layer);
    Serial.println(")");
}

void printPressedKey(byte keyCode) {
    Serial.print("    KEYCODE: ");
    Serial.println(keyCode);
}

