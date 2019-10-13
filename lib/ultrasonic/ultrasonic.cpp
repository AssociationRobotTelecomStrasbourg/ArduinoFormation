#include "ultrasonic.h"

Ultrasonic::Ultrasonic(uint8_t trigPin, uint8_t echoPin) : _trigPin(trigPin), _echoPin(echoPin){
	// Règle le mode des pins
	pinMode(_trigPin, OUTPUT); // Mode sortie
	pinMode(_echoPin, INPUT); // Mode entrée
}

uint32_t Ultrasonic::distance() const{
	// Génère une impulsion de 10 microsecondes
	digitalWrite(_trigPin, LOW); // Règle la pin à l'état bas
	delayMicroseconds(2); // Attend que la pin passe à l'état bas

	digitalWrite(_trigPin, HIGH); // Règle la pin à l'état haut
	delayMicroseconds(10); // Attend 10 microsecondes

	digitalWrite(_trigPin, LOW); // Règle la pin à l'état bas

	return pulseIn(_echoPin, HIGH) / 58; // Mesure le temps d'aller retour et calcule la distance
}
