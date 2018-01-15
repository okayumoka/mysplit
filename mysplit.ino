// MySplit
// ホスト（左手側）用
#include "Keyboard.h"
#include "keymap.h"

const int rowPins[ROW_NUM] = { 2, 3, 4, 5, 6 }; // OUTPUTのピン。走査ピン
const int colPins[COL_NUM] = { 7, 8, 9, 10, 11, 12 }; // INPUT_PULLUPのピン。

bool currentState[ROW_NUM][COL_NUM_2];
bool beforeState[ROW_NUM][COL_NUM_2];

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
	Keyboard.begin();
}

void loop() {
	getHostState();
	getSubState();
	applyKeyState();
}

void getHostState() {
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

void getSubState() {
	if (!Serial1.available()) return;

	int readData = Serial1.read();
	if (readData == -1) return;

	// 通信方式について
	// 0bABCDEFGH
	// A   ... 未使用
	// B   ... Press時は0、Release時は1
	// CDE ... rowPinの番号（右手用の範囲内で。したがって0～5）
	// FGH ... colPinの番号（右手用の範囲内で。したがって0～6）

	bool isPress = (bool) ((readData & 0x10000000 >> 7) == 0);
	bool isLeft  = (bool) ((readData & 0x01000000 >> 6) == 0);
	int rowPin   = (int)  (readData & 0x00111000 >> 3);
	int colPin   = (int)  (readData & 0x00000111);

	// 右手用
	currentState[rowPin][colPin + COL_NUM] = isPress ? LOW : HIGH;
}

void applyKeyState() {
	for (i = 0; i < ROW_NUM; i++) {
		for (j = 0; j < COL_NUM_2; j++)  {
			if (currentState[i][j] != beforeState[i][j]) {
				if (currentState[i][j] == LOW) {
					Serial.print("PRESS   ");
					Keyboard.press(keyMap[i][j]);
				} else {
					Serial.print("RELEASE ");
					Keyboard.release(keyMap[i][j]);
				}
				Serial.print(i);
				Serial.print(", ");
				Serial.println(j);
			}
			beforeState[i][j] = currentState[i][j];
		}
	}
}




