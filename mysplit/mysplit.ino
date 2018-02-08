// MySplit

#define HOST_SIDE

#include "Keyboard.h"
#include "keymap.h"

const int rowPins[ROW_NUM] = { 2, 3, 4, 5, 6 }; // OUTPUTのピン。走査ピン
const int colPins[COL_NUM] = { 7, 8, 9, 10, 14, 15 }; // INPUT_PULLUPのピン。

bool currentState[ROW_NUM][COL_NUM_2]; // 現在のループでの押下状態
bool beforeState[ROW_NUM][COL_NUM_2];  // 前のループでの押下状態
byte pressedKeyCode[ROW_NUM][COL_NUM_2]; // 押下したキー

int i;
int j;

void setup() {
	for (i = 0; i < ROW_NUM; i++) {
		int pin = rowPins[i];
		pinMode(pin, OUTPUT);
		digitalWrite(pin, HIGH);
	}
	for (i = 0; i < COL_NUM; i++) {
		int pin = colPins[i];
		pinMode(pin, INPUT_PULLUP);
	}

	for (i = 0; i < ROW_NUM; i++) {
		for (j = 0; j < COL_NUM_2; j++) {
			currentState[i][j] = HIGH;
			beforeState[i][j] = HIGH;
		}
	}

	Serial.begin(9600);
	Serial1.begin(9600);
#ifdef HOST_SIDE
	Keyboard.begin();
#endif
}

void loop() {
	getThisSideState();
#ifdef HOST_SIDE
	getOtherSideState();
	applyKeyState();
#else
	sendThisSideState();
#endif
}

void getThisSideState() {
	for (i = 0; i < ROW_NUM; i++) {
		int rowPin = rowPins[i];
		digitalWrite(rowPin, LOW);
		for (j = 0; j < COL_NUM; j++)  {
			int colPin = colPins[j];
			currentState[i][j] = digitalRead(colPin);
		}
		digitalWrite(rowPin, HIGH);
	}
}

#ifdef HOST_SIDE
void getOtherSideState() {
	// if (!Serial1.available()) {
	// 	// サブ側と通信できていない場合は、サブ側をすべて未押下にしておく。
	// 	// そうでないと、何かの拍子に通信できなくなったとき、
	// 	// キーが押しっぱなしになる可能性がある。
	// 	for (i = 0; i < ROW_NUM; i++) {
	// 		for (j = 0; j < COL_NUM; j++) {
	// 			currentState[i][j + COL_NUM] = HIGH;
	// 		}
	// 	}
	// 	return;
	// }

	while (true) {
		if (!Serial1.available()) break;

		byte readData = Serial1.read();
		if (readData == -1) break;

		// 通信方式について
		// 0bABCDEFGH
		// A   ... 1のとき、後続データなし（終了）
		// B   ... Press時は0、Release時は1
		// CDE ... rowPinの番号（右手用の範囲内で。したがって0～5）
		// FGH ... colPinの番号（右手用の範囲内で。したがって0～6）

		bool eof     = (bool) ((readData & 0b10000000) == 0b10000000);
		bool isPress = (bool) ((readData & 0b01000000) == 0b00000000);
		int rowPin   = (int)  ((readData & 0b00111000) >> 3);
		int colPin   = (int)  ( readData & 0b00000111 );

		if (eof) { break; }

		Serial.print("Receive: ");
		Serial.print(readData, BIN);
		Serial.print(" r=");
		Serial.print(rowPin);
		Serial.print(" c=");
		Serial.print(colPin);
		Serial.print("  ->  ");

		printKeyEvent(rowPin, colPin, isPress);
		// ホスト：左手、サブ：右手
		currentState[rowPin][colPin + COL_NUM] = isPress ? LOW : HIGH;
	}
}

void applyKeyState() {
	// Upper Layer、Lower Layer が押されているかを取得
	int layer = 0; // -1: Lower  0: Base  1: Upper
	for (i = 0; i < ROW_NUM; i++) {
		for (j = 0; j < COL_NUM_2; j++)  {
			if (keyMap[i][j] == KC_ULAY && currentState[i][j] == LOW) {
				layer++;
			}
			if (keyMap[i][j] == KC_LLAY && currentState[i][j] == LOW) {
				layer--;
			}
		}
	}
	// byte **currentMap = keyMap;
	byte currentMap[ROW_NUM][COL_NUM_2] = keyMap;
	if (layer > 0) currentMap = keyMapUpper;
	if (layer < 0) currentMap = keyMapLower;

	// キーを送る
	byte keyCode;
	for (i = 0; i < ROW_NUM; i++) {
		for (j = 0; j < COL_NUM_2; j++)  {
			if (currentState[i][j] != beforeState[i][j]) {
				if (currentState[i][j] == LOW) {
					keyCode = currentMap[i][j];
					Keyboard.press(keyCode);
					pressedKeyCode[i][j] = keyCode;
					printKeyEvent(i, j, true);
				} else {
					keyCode = pressedKeyCode[i][j];
					Keyboard.release(keyCode);
					pressedKeyCode[i][j] = KC_NULL;
					printKeyEvent(i, j, false);
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

	bool sended = false;
	int isPress;
	byte sendData = 0b00000000;

	for (i = 0; i < ROW_NUM; i++) {
		for (j = 0; j < COL_NUM; j++) {
			if (currentState[i][j] != beforeState[i][j]) {
				if (currentState[i][j] == LOW) {
					printKeyEvent(i, j, true);
					isPress = 0;
				} else {
					printKeyEvent(i, j, false);
					isPress = 1;
				}
				sendData = (byte) (0b00000000 | isPress << 6 | i << 3 | j);
				sended = true;
				Serial.print("Send: ");
				Serial.println(sendData);
				Serial1.write(sendData);
			}
			beforeState[i][j] = currentState[i][j];
		}
	}
	if (sended) Serial1.write(0b10000001);	// 後続データなしを送信
}
#endif

void printKeyEvent(int row, int col, bool isPress) {
	if (isPress) {
		Serial.print("PRESS   (");
	} else {
		Serial.print("RELEASE (");
	}
	Serial.print(i);
	Serial.print(", ");
	Serial.print(j);
	Serial.println(")");
}

void printPressedKey(byte keyCode) {
	Serial.print("    KEYCODE: ");
	Serial.println(keyCode);
}

