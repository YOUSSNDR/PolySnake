#include<Servo.h>
Servo servo;

void setup() {
  Serial.begin(9600);
  servo.attach(3);
  servo.write(90);
  delay(1000);
}

void loop() {
  servo.write(90);
  delay(1500);
  servo.write(45);
  delay(1500);
  servo.write(0);
  delay(1500);
  servo.write(45);
  delay(1500);
  servo.write(90);
  delay(1500);
  servo.write(135);
  delay(1500);
  servo.write(180);
  delay(1500);
  servo.write(135);
  delay(1500);
}
