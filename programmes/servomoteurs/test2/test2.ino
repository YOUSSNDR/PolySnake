#include<Servo.h> //bibliothèque servo
 Servo servo1; //on défini servo1 comme sevomoteur
 Servo servo2;
 void setup() {
  Serial.begin(9600);
  servo1.attach(9);
  servo2.attach(4);
 }
void loop(){
  servo1.writeMicroseconds(1972);
  servo2.writeMicroseconds(1972);

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
