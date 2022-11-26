#include<Servo.h>
Servo servo;
Servo servo1;
Servo servo2;
void setup() {
  Serial.begin(9600);
  servo.attach(3);
  servo1.attach(5);
  servo2.attach(7);
  servo.write(90);
  servo2.write(90);
  delay(3000);
}

void loop() {
  servo.write(135);
  servo1.write(90);
  servo2.write(45);
  delay(1200);
  servo.write(90);
  servo1.write(135);
  servo2.write(90);
  delay(1200);
  servo.write(45);
  servo1.write(90);
  servo2.write(135);
  delay(1200);
  servo.write(90);
  servo1.write(45);
  servo2.write(90);
  delay(1200);
  // for(int i=0;i>90;i++){
  //   float T=millis();
  //   float t=0;
  //   while(t<9){
  //     servo.write(i);
  //     t=millis()-T;
  //     Serial.println(t);
  //   }
  // }

}
