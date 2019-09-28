#ifndef BOUTON_H
#define BOUTON_H

class Bouton{
public:
  Bouton(int pin);
  bool etat() const; //Etat du bouton
  
private:
  int _pin; //Pin du bouton
};

#endif
