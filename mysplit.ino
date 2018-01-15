// MySplit
// ホスト（左手側）用

#include "Keyboard.h"

const int rowNum = 5;
const int colNum = 6;
const int colNum2 = 12;

#include "keymap.h"

const int[rowNum] rowPins = { 3, 4, 5, 6, 7 };
const int[colNum] colPins = { 8, 9, 10, 11, 12 };

bool currentState[rowNum][colNum2];
bool prevState[rowNum][colNum2];

// 初期化
void setup() {
	int i;
	int j;

	// デバッグ用のメッセージに使用
	Serial.begin(9600);

	// 左右の通信に使用
	Serial1.begin(9600);

	// ピンの初期化
	for (i = 0; i < rowNum; i++) {
		int rowPin = rowPins[i];
		pinMode(rowPin, OUTPUT);
		digitalWrite(rowPin, HIGH);
	}
	for (i = 0; i < colNum; i++) {
		int colPin = colPins[i];
		pinMode(colPin, INPUT_PULLUP);
		digitalWrite(colPin, HIGH);
	}

	// 状態の初期化
	for (i = 0; i < rowNum; i++) {
		for (j = 0; j < colNum2; j++) {
			currentState[i][j] = HIGH;
			prevState[i][j] = HIGH;
		}
	}

	// キーボード処理開始
	Keyboard.begin();
}

void loop() {
	// ホストの押下状態を取得
	getHostState();
	// サブの押下状態を取得
	getSubState();
	// キー押下処理
	applyKeyState();
}

void getHostState() {
	int i;
	int j;
	for (i = 0; i < rowNum; i++) {
		int rowPin = rowPins[i];
		digitalWrite(rowPin, LOW);
		for (j = 0; i < colNum; j++) {
			int colPin = colPins[i];
			currentState[i][j] = digitalRead(colPin);
		}
	}
}

void getSubState() {
	if (!Serial1.available()) return;

	int readData = Serial1.read();
	if (readData == -1) return;

	// 通信方式について
	// 0bABCDEFGH
	// FGH ... colPinの番号
	// CDE ... rowPinの番号
	// B   ... Press時は0、Release時は1
	// A   ... 未使用

	bool isPress = (bool) ((readData & 0x10000000 >> 7) == 0);
	bool isLeft  = (bool) ((readData & 0x01000000 >> 6) == 0);
	int rowPin   = (int)  (readData & 0x00111000 >> 3);
	int colPin   = (int)  (readData & 0x00000111);

	// 右手用
	currentState[rowPin][colPin + colNum] = isPress ? LOW : HIGH;
}

void applyKeyState() {
	int i;
	int j;
	for (i = 0; i < rowNum; i++) {
		for (j = 0; j < colNum2; j++) {
			if (currentState[i][j] != prevState[i][j]) {
				if (currentState[i][j] == LOW) {
					Keyboard.press(keyMap[i][j]);
				} else {
					Keyboard.release(keyMap[i][j]);
				}
			}
			prevState[i][j] = currentState[i][j];
		}
	}
}

