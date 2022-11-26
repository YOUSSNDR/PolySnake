#include<Servo.h>
Servo serv1;
Servo serv2;
Servo serv3;
int tet[9]=[];

void setup() {
  Serial.begin(9600);
  serv1.attach(3);
  serv2.attach(5);
  serv2.attach(7);
  serv1.write(90);
  serv2.write(90);
  serv3.write(90);
  delay(3000);
}

void loop() {
  for()

}
