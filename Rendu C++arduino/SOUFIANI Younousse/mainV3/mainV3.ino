#include "LettreMorseV3.h"
#include <string.h>
#include <Arduino.h>
using namespace std;

LettreMorse lm; //on appelle la classe LettreMorse avec lm
int ttap= 250; //temps d"un tap(bip) court
int code;



void setup() {
  Serial.begin(9600);   //initialisation du moniteur série
  pinMode(LED_BUILTIN, OUTPUT); //initialisation de la led
  Serial.println("I am ready...");
}

void loop() {
  if (Serial.available()){ //si la machine reçoit quelque chose
    code=Serial.read(); // le message et lu lettre par lettre et on attribue a chag=que fois une lettre a code 
    code=verif(code); //on transforme les majuscule en miniscule
    lm.morsetr(code);  // application de la fonction morsetr appartenant à la classe LettreMorse
    Serial.println(char(code)); //affiche la lettre traduite
    Serial.println(lm.morse); // affiche le code morse de la lettre
    trad2(); //traduit le code morse en clignotement
    delay(ttap*3); // pause entre chaque mots
  }
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
      float t=millis();
      float T=0;
      while (T<250){
        digitalWrite(LED_BUILTIN, HIGH);
        T=millis()-t;
      }
      digitalWrite(LED_BUILTIN,LOW);
      t=millis();
      while(T<250){
        T=millis()-t;
      }
      //digitalWrite(LED_BUILTIN, HIGH);//led allumée
      //delay(ttap); //attante de 250ms pour les points
      //digitalWrite(LED_BUILTIN, LOW);//led éteinte
      //delay(ttap);
    }

    void tiret(){
    float t=millis();
    float T=0;
    while (T<500){
        digitalWrite(LED_BUILTIN, HIGH);
        T=millis()-t;
      }
      digitalWrite(LED_BUILTIN,LOW);
      t=millis();
      while(T<250){
        T=millis()-t;
      }
    //  digitalWrite(LED_BUILTIN, HIGH);//led allumée
    //  delay(ttap * 3); //attente de 750ms pour les tirets
    //  digitalWrite(LED_BUILTIN, LOW);//led éteinte
    //  delay(ttap);
    }
    int verif(int code){
      if (code>=65 && code<=90){
        return code+32; //entre les majuscules les les miniscules en ascii(html) il y a une différence de 32.
      }
      return code; // si c'est déjà une minuscule alors on y touche pas
    }