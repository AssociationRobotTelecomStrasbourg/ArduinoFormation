# Formation Arduino

## Sommaire

<!-- TOC -->

- [Formation Arduino](#formation-arduino)
  - [Sommaire](#sommaire)
  - [Spécificités de programmation](#sp%C3%A9cificit%C3%A9s-de-programmation)
    - [Structure du code](#structure-du-code)
    - [Type des variables](#type-des-variables)
    - [Les différents pins](#les-diff%C3%A9rents-pins)
  - [Entrées/Sorties numériques (Digital Input/Output)](#entr%C3%A9essorties-num%C3%A9riques-digital-inputoutput)
    - [Challenge](#challenge)
  - [Gestion du temps](#gestion-du-temps)
    - [Challenges](#challenges)
  - [Analogique](#analogique)
  - [Communication Série](#communication-s%C3%A9rie)
  - [Fonctions diverses](#fonctions-diverses)
  - [Interruption](#interruption)
    - [Challenge](#challenge-1)
  - [Pour aller plus loin](#pour-aller-plus-loin)

<!-- /TOC -->

## Spécificités de programmation
### Structure du code
Un programme Arduino utilise le langage C/C++.
```c++
// Programme Arduino
void setup {
  // setup() est exécuté une fois au démarrage de l'Arduino.
}

void loop {
  // loop() est exécuté à l'infini après setup()
}

// Équivalent C/C++ standard
void main() {
  setup();
  while(true) {
    loop();
  }
}
```

### Type des variables
On n'utilise pas ici `int`, `long`, `short`, `unsigned` car les tailles en mémoire varie selon les systèmes choisis.

On utilise `intX_t`, `uintX_t` (e.g. `int8_t` pour un entier signé sur 8 bits, `uint32_t` pour un entier non signé sur 32 bits).

### Les différents pins
Dans le programme les pins D2, …, D13 sont appelées 2, …, 13 et A0, …, A7 ont utilise A0, …, A7.

## Entrées/Sorties numériques (Digital Input/Output)

Les signaux numériques sont des 0 et 1 représentés par GND (0V) et VCC (5V) pour Arduino Uno et Nano.

Les entrées numériques mesurent l'état de la pin.
Les sorties numériques contrôlent l'état de la pin.

On peut choisir le mode entrée ou sortie de la pin avec la fonctions [`pinMode(pin, mode)`](https://www.arduino.cc/reference/en/language/functions/digital-io/pinmode/).
Les deux modes sont :
- `OUTPUT`
- `INPUT`

L'état d'une pin peut être :
- `HIGH`
- `LOW`

On règle l'état d'une pin dans le mode `OUTPUT` avec
[`digitalWrite(pin, value)`](https://www.arduino.cc/reference/en/language/functions/digital-io/digitalwrite/).

On lit l'état d'une pin qui est dans le mode `INPUT` avec
[`digitalRead(pin)`](https://www.arduino.cc/reference/en/language/functions/digital-io/digitalread/) qui retourne l'état commme précédemment.


![led](resources/led.png)
```c++
const uint8_t LED 13;

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
}

void loop() {

}
```

![button_extern_pullup](resources/button_extern_pullup.png)
```c++
const uint8_t LED 13;
const uint8_t BUTTON 2;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  digitalWrite(LED, digitalRead(BUTTON));
}
```

![button_intern_pullup](resources/button_intern_pullup.png)
```c++
pinMode(BUTTON, INPUT_PULLUP);
```

### Challenge
- Inverse la position du bouton pour allumer la led par rapport au programme précédent.

## Gestion du temps
Sur Arduino, deux méthodes principales existent pour interagir avec le temps.

[`delay(ms)`](https://www.arduino.cc/reference/en/language/functions/time/delay/) arrête le programme pendant un certain temps donné en millisecondes. On appel ce mode de fonctionnement bloquant car on ne peut faire autre chose à côté.

On peut ainsi faire clignoter une led.

```c++
const uint8_t LED 13;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  delay(500);
}
```

[`millis()`](https://www.arduino.cc/reference/en/language/functions/time/millis/) renvoie le temps écoulé le démarrage de l'arduino en millisecondes.

```c++
const uint8_t LED 13;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  if (millis() % 1000 < 500)
    digitalWrite(LED, HIGH);
  else
    digitalWrite(LED, LOW);
}
```

Les équivalents de `delay(ms)` et `millis()` pour manipuler le temps en microsecondes sont respectivement [`delayMicroseconds(us)`](https://www.arduino.cc/reference/en/language/functions/time/delaymicroseconds/) et [`micros()`](https://www.arduino.cc/reference/en/language/functions/time/micros/)

### Challenges
1. Fait clignoter une led irrégulièrement.
2. Fait clignoter deux leds à différentes fréquences.
3. Allume la led pendant un certain temps après avoir appuyer sur le bouton.
4. Change l'état de la led à chaque appuie du bouton.

## Analogique
Pour lire la tension d'une pin, on utilise [`analogRead(pin)`](https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/). Cette fonction renvoie une valeur entre 0 et 1023 (CAN 10 bits).

L'Arduino ne peut pas générer de tension entre 0V et 5V. Mais, [`analogWrite(pin, value)`](https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/) peut générer un signal rectangulaire avec un rapport cyclique variable qui a en moyenne la tension voulu. La tension générer est proportionelle à la valeur passé en argument entre 0 et 255.

## Communication Série
La communication série relie un ordinateur à l'Arduino.

Pour initialiser la communication il faut utiliser [`Serial.begin(speed)`](https://www.arduino.cc/reference/en/language/functions/communication/serial/begin/)
en choisissant la vitesse de communication (baud rate) généralement réglé à 9600.

Pour envoyer un message de l'arduino on peut utiliser
[`Serial.print(val)`](https://www.arduino.cc/reference/en/language/functions/communication/serial/print/)
ou
[`Serial.println(val)`](https://www.arduino.cc/reference/en/language/functions/communication/serial/println/) qui revient à la ligne.
La valeur envoyer peut être un entier, un flottant, un caractère ou une chaîne de caractères.

[`Serial.available()`](https://www.arduino.cc/reference/en/language/functions/communication/serial/available/) renvoie le nombre d'octets à lire. On peut s'en servir pour savoir si un message est arrivé.
```c++
if (Serial.available() > 0) {
   // Do something
}
```

[`Serial.parseInt()`](https://www.arduino.cc/reference/en/language/functions/communication/serial/parseint/) interprète le message pour renvoyer le premier entier dans le message.

[`Serial.parseFloat()`](https://www.arduino.cc/reference/en/language/functions/communication/serial/parsefloat/) interprète le message pour renvoyer le premier flottant dans le message.

[`Serial.readString()`](https://www.arduino.cc/reference/en/language/functions/communication/serial/readstring/) interprète le message pour renvoyer le premier mot dans le message.

## Fonctions diverses
Voici diverses fonctions Arduino qu'il est intéressant de connaître.

Pour générer des nombres aléatoires:
- [`random(min, max)`](https://www.arduino.cc/reference/en/language/functions/random-numbers/random/)
- [`randomSeed(seed)`](https://www.arduino.cc/reference/en/language/functions/random-numbers/randomseed/)

Pour borner une valeur dans un intervalle:
[`constrain(x, a, b)`](https://www.arduino.cc/reference/en/language/functions/math/constrain/)

Pour appliquer une fonction affine sur une valeur sans se tirer les cheveux:
[`map(value, fromLow, fromHigh, toLow, toHigh)`](https://www.arduino.cc/reference/en/language/functions/math/map/)

## Interruption
Une interruption Arduino permet d'exécuter une fonction quand l'état d'une pin change.

Les différents changements possible sont:
- `LOW`
- `CHANGE`
- `RISING`
- `FALLING`

Juste les pins 2 et 3 peuvent être utilisé pour les interruptions.

[`attachInterrupt(digitalPinToInterrupt(pin), ISR, mode)`](https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/)

```c++
const uint8_t LED 13;
const uint8_t BUTTON 2;

uint16_t counter = 0;

void increment() {
  counter++;
}

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2), increment, RISING);
}

void loop() {
  Serial.println(counter);
  delay(500);
}
```

### Challenge
- Faire un anti-rebond.

## Pour aller plus loin
N'hésite pas à regarder la [documentation Arduino](https://www.arduino.cc/reference/en/) cette formation n'a fait que aborder les fonctions les plus utilisé.
Tu peux aussi regarder les codes des bibliothèques utilisées.
