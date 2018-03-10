// keycode checker for Pro Micro

#include "Keyboard.h"

void setup() {
	Keyboard.begin();

	int kc = 0;
	Serial.println("START");
	for (int kc = 0; kc < 255; kc++) {
		Keyboard.press(kc);
		delay(100);
		Keyboard.release(kc);
		delay(100);
	}
	Serial.println("END");
}

void loop() {
}


