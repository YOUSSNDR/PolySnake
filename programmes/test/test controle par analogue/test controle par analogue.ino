#include <Servo.h>  

const int xPin = A0;  
const int servoPin = 4;  // Pin de commande du servomoteur

Servo servo;  

void setup() {
  Serial.begin(9600);

  // Attache le servomoteur au pin de commande
  servo.attach(servoPin);
}

void loop() {
  // Lit la valeur de l'axe X du joystick
  int xValue = analogRead(xPin);

  // Convertit la valeur lue (qui est un entier compris entre 0 et 1023) en un angle (qui est un entier compris entre 0 et 180 degrés)
  int angle = map(xValue, 0, 1023, 0, 180);

  // Envoie l'angle au servomoteur
  servo.write(angle);

  // Affiche l'angle sur la console série
  Serial.println(angle);

  // Attend 20 millisecondes avant de relire l'angle
  delay(20);
}