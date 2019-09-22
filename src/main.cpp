#include <Arduino.h>

#include <ultrason.h>

#define LED 13
#define LED_PWM 9
#define BUTTON 2
#define POTENTIOMETER A5
#define TRIG 4
#define ECHO 5

unsigned long time = 100;
int potentiometer;

Ultrason ultrason(TRIG, ECHO);

void setup() {
  Serial.begin(9600);

  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  potentiometer = analogRead(POTENTIOMETER);

  analogWrite(LED_PWM, map(potentiometer, 0, 1023, 0, 255));

  Serial.println(ultrason.distance());

  digitalWrite(LED, digitalRead(BUTTON));
  delay(time);
  digitalWrite(LED, LOW);
  delay(time);
}
