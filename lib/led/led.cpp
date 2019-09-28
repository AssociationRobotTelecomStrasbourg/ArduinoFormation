#include <Arduino.h>
#include "led.h"

Led::Led(int pin) : _pin(pin) {
  pinMode(_pin, OUTPUT); //Régler le mode sortie sur le pin 13
  digitalWrite(_pin, LOW); //Éteint la led si elle est allumé
}

void Led::allume() const{
  digitalWrite(_pin, HIGH); //Allume la led
}

void Led::eteint() const{
  digitalWrite(_pin, LOW);
}

void Led::clignote(int temps) const{
  /*
   * À compléter
   * Reste dans la fonction et fait clignoter la led toute les secondes
   * pendant tant de "temps" milliseconde ou l'infinie si "temps" est -1
   */
}
