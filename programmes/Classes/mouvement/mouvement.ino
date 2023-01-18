#include"mouvement.h"
#include <Servo.h>

mouvement mymove;

void setup() {
  Serial.begin(9600);
  mymove.myServos[0].attach(2);
  mymove.myServos[1].attach(3);
  mymove.myServos[2].attach(4);
  mymove.myServos[3].attach(8);
  mymove.myServos[4].attach(9);
  mymove.myServos[5].attach(12);
  mymove.myServos[6].attach(13);
  mymove.myServos[7].attach(7);
  mymove.myServos[8].attach(8);
  mymove.myServos[9].attach(5);

  
  //initialisation des servos formant une ligne droite
  mymove.straightline();
  delay(2000);
}

void loop(){
  //mymove.slither(0, 30, 3, 1.5);
  mymove.straightline();
}