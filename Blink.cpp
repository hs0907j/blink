#include "Blink.h"

Blink::Blink(int input) {
	pinNumber = input;
	pinMode(pinNumber, OUTPUT);
}

void Blink::on(int onTime) {
	digitalWrite(pinNumber, LOW); 
	delay(onTime);
}

void Blink::off(int offTime) {
	digitalWrite(pinNumber, HIGH);
	delay(offTime);
}
