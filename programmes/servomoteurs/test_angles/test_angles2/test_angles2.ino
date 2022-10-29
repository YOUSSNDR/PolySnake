#include<Servo.h> //bibliothèque servo
 Servo servo; //on défini servo comme sevomoteur
 int tet1=0; //angle demandé
 int tet2=90;
 int tet3=180;
 float t;
 float T;
 void setup() {
  Serial.begin(9600);
  servo.attach(4);
  servo.write(0);
    }
void loop()
{
  for(int i=0;i>tet2;i++){
    t=0;
    T=millis();
    while(t<6){
      t=millis()-T;
      Serial.println(t);
      servo.write(i);
    }
    T=0;
    
    }
  }
/*    for(int i=tet1;i>tet2;i++){
    t=0;
    T=millis();
    while(t<6){
      t=millis()-T;
      Serial.println(t);
      servo.write(i);
    }
    T=0;
    if(i=tet2){
      break;
    }
  }
    for(int i=tet2;i>tet3;i++){
    t=0;
    T=millis();
    while(t<6){
      t=millis()-T;
      Serial.println(t);
      servo.write(i);
    }
    T=0;
    if(i=tet3){
      break;
    }
  }
*/

