#include "LettreMorseV3.h"
#include <string.h>
#include <Arduino.h>
using namespace std;

LettreMorse lm; //on appelle la classe LettreMorse avec lm
int tti= 250; //temps d'un ti
int code; 
char phrase[]="c3c1 3s7 un3 phr4s3"; //phrase a traduire
int n;//taille de la liste
int i;//entier parcourant la liste
int t;// variable de temps =millis()
int T;// différence de temps =millis()-t

void setup() {
  Serial.begin(9600);   //initialisation du moniteur série
  pinMode(LED_BUILTIN, OUTPUT); //initialisation de la led
  Serial.println("I am ready...");
}

void loop() {
  //utilisation de phrase[]
  n= sizeof(phrase);
  while(i<n){
    code=phrase[i];
    code=verif(code); //on transforme les majuscules en miniscules
    lm.morsetr(code);  // application de la fonction morsetr appartenant à la classe LettreMorse
    Serial.print(char(code)); //affiche la lettre traduite
    if(lm.morse==""){}
    else if(lm.morse==" "){
      t=millis();
      T=0;
      while (T<7*tti){
        T=millis()-t;
      } 
    }
    else{
      Serial.println(lm.morse); // affiche le code morse de la lettre
      Serial.print(" ");
      trad2(); //traduit le code morse en clignotement
      //delay(tti*3); // pause entre chaque mots
      t=millis();
      T=0;
      while (T<3*tti){
        T=millis()-t;
      } 
    }
      i++;
  }
  //utilisation du moniteur série
  /*if (Serial.available()){ //si la machine reçoit quelque chose
    code=Serial.read(); // le message et lu lettre par lettre et on attribue a chaque fois une lettre a code 
    code=verif(code); //on transforme les majuscules en miniscules
    lm.morsetr(code);  // application de la fonction morsetr appartenant à la classe LettreMorse
    Serial.print(char(code)); //affiche la lettre traduite
    if(lm.morse==""){}
    else if(lm.morse==" "){
      t=millis();
      T=0;
      while (T<7*tti){
        T=millis()-t;
      } 
    }
    else{
      Serial.println(lm.morse); // affiche le code morse de la lettre
      Serial.print(" ");
      trad2(); //traduit le code morse en clignotement
      t=millis();
      T=0;
      while (T<3*tti){
        T=millis()-t;
      }
    }
  }*/

}


    void trad2(){
      for (int i=0;true;i++){
        if (lm.morse[i] == '.' ){ //on parcourt les caractères morse si on a un point on applique la fonction point
          point();
        }
            else if (lm.morse[i] == '-'){ //si on a un tiret on applique la fonction tiret
              tiret();
            }
            else { // sinon on sort de trad2
            break;
            }
          }
    }
    void point(){
      digitalWrite(LED_BUILTIN, HIGH);
      t=millis();
      T=0;
      while (T<tti){
        T=millis()-t;
      } 
      digitalWrite(LED_BUILTIN, LOW);
      t=millis();
      T=0;
      while (T<tti){
        T=millis()-t;
      }
      /*digitalWrite(LED_BUILTIN, HIGH);//led allumée
      delay(tti); //attante de 250ms pour les points
      digitalWrite(LED_BUILTIN, LOW);//led éteinte
      delay(tti);*/
    }
    void tiret(){
      digitalWrite(LED_BUILTIN, HIGH);
      t=millis();
      T=0;
      while (T<3*tti){
        T=millis()-t;
      } 
      digitalWrite(LED_BUILTIN, LOW);
      t=millis();
      T=0;
      while (T<tti){
        T=millis()-t;
      }
          /*digitalWrite(LED_BUILTIN, HIGH);//led allumée
          delay(tti * 3); //attente de 750ms pour les tirets
          digitalWrite(LED_BUILTIN, LOW);//led éteinte
          delay(tti);*/
    }
    int verif(int code){
      if (code>=65 && code<=90){
        return code+32; //entre les majuscules les les miniscules en ascii(dec) il y a une différence de 32.
      }
      return code; // si c'est déjà une minuscule alors on y touche pas
    }