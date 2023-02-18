#include<Servo.h> //bibliothèque servo
 //Servo servo1; //on défini servo1 comme sevomoteur
 const int R=11;
 const int J=10;
 const int B=9;
 int t=0;
 int T;
 Servo servo2;
 void setup() {
  Serial.begin(9600);
  //servo1.attach(9);
  servo2.attach(4);
  servo2.writeMicroseconds(500);
  delay(4000);
  pinMode(R,OUTPUT);
  pinMode(J,OUTPUT);
  pinMode(B,OUTPUT);
  digitalWrite(R,LOW);
  digitalWrite(J,LOW);
  digitalWrite(B,LOW);
 }
void loop(){
 // servo1.writeMicroseconds(1972);
servo2.writeMicroseconds(1500);
//delay(960);
digitalWrite(J,HIGH);
delay(3000);
digitalWrite(J,LOW);
servo2.writeMicroseconds(2500);
//delay(960);
digitalWrite(R,HIGH);
delay(3000);
digitalWrite(R,LOW);
servo2.writeMicroseconds(1500);
//delay(960);
digitalWrite(J,HIGH);
delay(3000);
digitalWrite(J,LOW);
servo2.writeMicroseconds(0);
//delay(960);
digitalWrite(B,HIGH);
delay(3000);
digitalWrite(B,LOW);
//  delay(3000);
//   servo1.write(45);
//   servo2.write(45);
//   delay(2000);
//   servo1.write(90);
//   servo2.write(90);
//   delay(2000);
//   servo1.write(135);
//   servo2.write(135);
//   delay(1000);
//   servo1.write(180);
//   servo2.write(180);
//   delay(1000);
//   servo1.write(225);
//   servo2.write(225);
//   delay(1000);
//   servo1.write(270);
//   servo2.write(270);
//   delay(1000);
//   servo1.write(90);
//   servo2.write(90);
  
}
