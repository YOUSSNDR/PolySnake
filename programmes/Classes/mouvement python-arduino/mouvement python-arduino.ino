#include"mouvement.h"
#include <Servo.h>
#include <cvzone.h>

mouvement mymove;

SerialData serialData(1,1);//(nombredevaleurs,chiffreparvalleur)
int valsRec[1]; //tableau de la taille nombredevaleurs

void setup() {
  Serial.begin(9600);
  serialData.begin();
  mymove.myServos[0].attach(2);
  mymove.myServos[1].attach(3);
  mymove.myServos[2].attach(4);
  mymove.myServos[3].attach(6);
  mymove.myServos[4].attach(7);
  mymove.myServos[5].attach(8);
  mymove.myServos[6].attach(10);
  mymove.myServos[7].attach(11);
  mymove.myServos[8].attach(8);
  mymove.myServos[9].attach(5);

  
  //initialisation des servos formant une ligne droite
  mymove.straightline();
  delay(2000);
}

void loop(){
//mymove.slither(0, 45, 2, 1);
mymove.straightline();

 /*int K1=35;
  int K2=K1;
  int v=2;
while(K1>1){
  mymove.slither(0,K1,v,1);
  K1=K1-10;
  if(K1<K2-10){
    v=v+2;
    K2=K2-10;
  }
  Serial.print(K1);
  Serial.print("   ");
  Serial.println(v);
  }
  for(int m=0;m>21;m++){
    mymove.slither(m,K1,v,1);
    delay(200);
  }
while(K1<35){
  mymove.slither(20,K1,v,1);
  K1=K1+10;
  if(K1>K2){
    v=v-2;
    K2=K2+10;
  }
  Serial.print(K1);
  Serial.print("   ");
  Serial.println(v);
}  
 for(int m=20;m<0;m--){
    mymove.slither(m,K1,v,1);
    delay(200);
 }*/
}