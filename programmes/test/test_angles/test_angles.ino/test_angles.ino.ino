#include <Servo.h>  //bibliothèque servo
Servo servo;        //on défini servo comme sevomoteur
int angle;

void setup() {
  Serial.begin(9600);
  servo.attach(11);
  servo.write(90);
  delay(1000);
  Serial.println("debut");
}
void loop() {
  servo.write(90);
  Serial.println("fait1");
  delay(1000);
  servo.write(180);
  Serial.println("fait2");
  delay(1000);
  servo.write(90);
  Serial.println("fait3");
  delay(1000);
  servo.write(0);
  Serial.println("fait4");
  delay(1000);
}