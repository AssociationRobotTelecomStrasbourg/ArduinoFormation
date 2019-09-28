#include <Servo.h>

//Initialisation des Servomoteurs
Servo claw, left, right, middle;

void setup() {
  //Initialisation de la liaison série
  Serial.begin(9600);
  
  //Assignation des pins pouvant faire du pwm
  claw.attach(6);
  left.attach(9);
  right.attach(10);
  middle.attach(11);

  //Différentes commandes avec des délais
  //entre chacunes d'elles pour laisser les
  //servomoteurs atteindre leur positions.
  claw.write(20);
  delay(2000);
  claw.write(100); //0-100
  left.write(90); //90-180
  right.write(45); //45-130
  middle.write(0); //0-165
  delay(2000);
  middle.write(80);
  left.write(180);
  claw.write(20);
  delay(1000);
  left.write(135);
  right.write(110);
  delay(1000);
  claw.write(100);
  delay(1000);
  left.write(130); //90-180
  right.write(45); //45-130
  delay(1000);
  middle.write(0);
  delay(1000);
  left.write(135);
  right.write(110);
  delay(1000);
  claw.write(20);
  
  //Test
}

void loop() {
}

