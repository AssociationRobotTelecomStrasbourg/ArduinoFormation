#include <Arduino.h>
#include "ultrason.h"

Ultrason::Ultrason(int pinTrig, int pinEcho) : _pinTrig(pinTrig), _pinEcho(pinEcho){
	pinMode(_pinTrig, OUTPUT);
	pinMode(_pinEcho, INPUT);
}

int Ultrason::distance() const{
	// Impulse
	digitalWrite(_pinTrig, LOW);
	delayMicroseconds(2);

	digitalWrite(_pinTrig, HIGH);
	delayMicroseconds(10);

	digitalWrite(_pinTrig, LOW);

	// Get the time of flight and apply ratio to get the distance.
	return (int) (pulseIn(_pinEcho, HIGH)/58);
}
