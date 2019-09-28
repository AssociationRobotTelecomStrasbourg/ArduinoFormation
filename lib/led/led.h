#ifndef LED_H
#define LED_H

class Led{
public:
  Led(int pin);
  void allume() const; //Allume la led
  void eteint() const; //Éteint la led
  void clignote(int temps = -1) const;
  //Fait clignoter la led pendant une certaine durée
  //Indéfiniment si le temps n'est pas spécifié
  
private:
  int _pin; //Pin de la led
};

#endif
