
#include<Servo.h> //bibliothèque servo
 Servo servo1; //on défini servo1 comme sevomoteur
 Servo servo2;
 int potentio=0;
 float tension=0;
 float var=255/5;
 int pos;
void setup() {
  Serial.begin(9600);
  servo1.attach(9);
  servo2.attach(4);
  //servo1.writeMicroseconds(1500);
  //servo2.writeMicroseconds(1500);
  //delay(2000);
  }
void loop() {
 // Serial.println(potentio);
  potentio=analogRead(0);
  tension=potentio/204,6 ;
  //Serial.print("tension= ");
  Serial.println(potentio/4);
  pos=500+400*tension;
  servo1.write(potentio/4);
  servo2.write(potentio/4);
  delay(1000);
   /*delay(1000);
   servo1.writeMicroseconds(1000);
   servo2.writeMicroseconds(1000);
   delay(2000);
   servo1.writeMicroseconds(1500);
   servo2.writeMicroseconds(1500);
   delay(2000);
   servo1.writeMicroseconds(2000);
   servo2.writeMicroseconds(2000);
   delay(2000);
   servo1.writeMicroseconds(2500);
   servo2.writeMicroseconds(2500);
   delay(2000);
   servo1.writeMicroseconds(500);
   servo2.writeMicroseconds(500);
   */
   
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
