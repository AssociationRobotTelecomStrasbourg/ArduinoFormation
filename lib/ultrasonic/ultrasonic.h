#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

// Classe pour utiliser le capteur ultrason HC-SR04
class Ultrasonic {
public:
	Ultrasonic(uint8_t trigPin, uint8_t echoPin); // Constructeur
	uint32_t distance() const; // Renvoie la distance en cm

private:
	uint8_t _trigPin; // pin de trigger
	uint8_t _echoPin; // pin de echo
};

#endif
