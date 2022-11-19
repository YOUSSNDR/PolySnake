#include<Servo.h> //bibliothèque servo
 //Servo servo1; //on défini servo1 comme sevomoteur
const int tr=6; //temps de rotation
 const int R=11; //led Rouge
 const int J=10;// ... Jaune
 const int B=9;// ... Bleu
 const int tet=0;// ... angle defini
 const int alph=1500;// ....
 const int bet=180;// ....
 int t=0;
 int T;
 Servo servo;
 void setup() {
  Serial.begin(9600);
  //servo1.attach(9);
  servo.attach(4);
  servo.writeMicroseconds(500);
  delay(4000);
  pinMode(R,OUTPUT);
  pinMode(J,OUTPUT);
  pinMode(B,OUTPUT);
  digitalWrite(R,LOW);
  digitalWrite(J,LOW);
  digitalWrite(B,LOW);
 }
void loop(){
  T=millis();
for (float i=tet;i>alph;i=i+7,4){
  if (i=alph){digitalWrite(R,HIGH);break;}//si lang
  while(t<tr){
  servo.writeMicroseconds(i);
  t=millis()-T;
  }
t,T=0,0;

}

}