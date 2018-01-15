#include "Keyboard.h"
#include "keycode.h"

const int rowNum = 5;
const int colNum = 6;

#include "keymap.h"

const int[rowNum] rowPins = { 3, 4, 5, 6, 7 };
const int[colNum] colPins = { 8, 9, 10, 11, 12 };

bool currentState[rowNum][colNum];
bool prevState[rowNum][colNum];

int i;
int j;

// 初期化
void setup() {
	// デバッグ用のメッセージに使用
	Serial.begin(9600);

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
		for (j = 0; j < colNum; j++) {
			currentState[i][j] = HIGH;
			prevState[i][j] = HIGH;
		}
	}
}

void loop() {
	for (i = 0; i < rowNum; i++) {
		for (j = 0; i < colNum; j++) {
		}
	}
}

