#ifndef MOTEUR_H
#define MOTEUR_H

class SuiviLigne {
public:
  SuiviLigne(int pin, int seuil);
  void reglerSeuil(int seuil); //Règle le seuil
  int brut() const; //Renvoie les données brut du capteur
  bool etat() const; //Renvoie l'état du capteur (blanc/noir)
  
private:
  int _pin; //Pin du suivi de ligne
  int _seuil; //Seuil de distinction entre blanc et noir
};

#endif
