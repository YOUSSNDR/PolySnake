#include "moteurs.h"

moteurs mymoteur(5,6);

void setup() {
  Serial.begin(9600);
  pinMode(mymoteur.Ma,OUTPUT);
  pinMode(mymoteur.Mr,OUTPUT);
  mymoteur.stop();
delay(1000);
}

void loop(){
//mymoteur.marche_avant(155);
//mymoteur.marche_arriere(155);
mymoteur.stop();
}