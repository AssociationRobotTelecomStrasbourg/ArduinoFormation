#include <Arduino.h>
#include "moteur.h"

Moteur::Moteur(int pin1, int pin2) : _pin1(pin1), _pin2(pin2) {
  //initialise le pwm des pins à 0
  analogWrite(_pin1, 0);
  analogWrite(_pin2, 0);
}

void Moteur::tourner(int pwm) const {
  //le signe de pwm détermine le sens de rotation du moteur
  analogWrite(_pin1, 0);
  analogWrite(_pin2, 0);
  pwm = constrain(pwm, -255, 255); //explication de constrain sur arduino.cc
  if (pwm < 0)
    analogWrite(_pin1, -pwm);
  else
    analogWrite(_pin2, pwm);
}
