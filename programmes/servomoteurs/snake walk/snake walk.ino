#include<Servo.h>
Servo servo;
Servo servo2;
void setup() {
  Serial.begin(9600);
  servo.attach(3);
  servo2.attach(4);
  servo.write(90);
  servo2.write(90);
  delay(3000);
}

void loop() {
  servo.write(103);
  servo2.write(83);
  delay(1200);
  servo.write(103);
  servo2.write(103);
  delay(1200);
servo.write(83)
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
