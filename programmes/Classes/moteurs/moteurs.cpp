#include"moteurs.h"
#include"Arduino.h"

moteurs::moteurs(int a, int b){
  this->Ma=a;
  this->Mr=b;
};

void moteurs::marche_avant(int speed){
  analogWrite(this->Ma,speed);
  analogWrite(this->Mr,LOW);
}

void moteurs::marche_arriere(int speed){
  analogWrite(this->Ma,LOW);
  analogWrite(this->Mr,speed);
}

void moteurs::stop(){
  analogWrite(this->Ma,LOW);
  analogWrite(this->Mr,LOW);
}
