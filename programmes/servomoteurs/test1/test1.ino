
#include<Servo.h> //bibliothèque servo
 Servo servo1; //on défini servo1 comme sevomoteur
 Servo servo2;
void setup() {
  servo1.attach(9);
  servo2.attach(4);
  servo1.write(0);
  servo2.write(0);
  delay(2000);
  }
void loop() {
   servo1.writeMicroseconds(544);
   servo2.writeMicroseconds(544);
   delay(2000);
   servo1.writeMicroseconds(2400);
   servo2.writeMicroseconds(2400);
   delay(2000);
   servo1.writeMicroseconds(3000);
   servo2.writeMicroseconds(3000);
   delay(2000);
//  servo1.write(45);
//  delay(3000);
//  servo1.write(90);
//  delay(3000);
//  servo1.detach();
//  delay(2000);
//  servo1.attach(8);
//  servo1.write(0);
//  delay(1000);

  
}
