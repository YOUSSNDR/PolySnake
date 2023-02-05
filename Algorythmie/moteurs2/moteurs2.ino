#include "moteurs.h"

moteurs mymoteur(5,6); //on fait appel à la fonction moteur en initilisant les variables a leurs pins propres

void setup() {//on initialise le moniturs séries et défini pins comme sorties
  Serial.begin(9600);
  pinMode(mymoteur.vAvance,OUTPUT); 
  pinMode(mymoteur.vRecul,OUTPUT);
  mymoteur.fArret();
delay(1000);
}

void loop(){
//mymoteur.fMarche_avant(155); //on fait tourner les roues vers l'avant à la vitesse attribuer à la valeur analogique 155
//mymoteur.fMarche_arriere(155);// on fait tourner les roues vers l'rrière à la vitesse attribuer à la valeur analogique 155
mymoteur.fArret();//on arrête le moteur
}