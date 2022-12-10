#include<Servo.h>
Servo serv1;

void setup() {
Serial.begin(9600);
serv1.attach(3);
serv1.write(90);
delay(1000);


}
  int conv(int angle){
    return int(500+((1000*angle)/90));
 /*bouge(servo serv,float angle){
  angle1=angle-23;
  for(int i=0;i>23;i++){
  angle1=angle1+1
  serv.writemicroseconds(conv(angle1))
  }*/

}

void loop() {
/* int tempsmillis=44;
  int angle=113;
  int angle1=angle-23;
  for(int i=0;i>23;i++){
    Serial.println("angle +1");
    int t=millis();
    int T=0;
    while(T<tempsmillis){
      serv1.write(angle1+i);
      T=millis()-t;
    }
  }*/
  int i=0;
  /*while ( i<23){
    serv1.writeMicroseconds(conv(90+i));
    delay(44);
    i=i+1;
  }*/
  serv1.writeMicroseconds(500);
  delay(1000);
  serv1.writeMicroseconds(750);
  delay(1000);
  serv1.writeMicroseconds(1000);
  delay(1000);
  serv1.writeMicroseconds(1250);
  delay(1000);
  serv1.writeMicroseconds(1500);
  Serial.println("90° atteint");
  delay(3000);
  serv1.writeMicroseconds(1750);
  delay(1000);
  serv1.writeMicroseconds(2000);
  delay(1000);
  serv1.writeMicroseconds(2250);
  delay(1000);
  serv1.writeMicroseconds(2500);
  delay(1000);
}
