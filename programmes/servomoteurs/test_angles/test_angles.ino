#include<Servo.h> //bibliothèque servo
 Servo servo; //on défini servo comme sevomoteur
 void setup() {
  Serial.begin(9600);
  servo.attach(4);
 }
void loop(){
  servo.write(90);
}
