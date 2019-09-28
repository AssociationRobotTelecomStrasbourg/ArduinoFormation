#ifndef MOTEUR_H
#define MOTEUR_H

class Moteur{
public:
  Moteur(int pin1, int pin2);
  void tourner(int pwm) const; //Actionne le moteur au pwm attendu
  
private:
  //Pins du moteur
  int _pin1;
  int _pin2;
};

#endif
