#include"moteurs.h"
#include"Arduino.h"

moteurs::moteurs(int a, int b){ //on fait appel à la fonction moteur
  this->vAvance=a; //attribue la valeur a à la variable (this-> nous permet de bien sélectionner la variable liée à la classe moteur)
  this->vRecul=b; //attribue la valeur b à la variable
};

void moteurs::fMarche_avant(int vitesse){ //on utilise la fonction marche avant et on sélectionne une vitesse(en valeur analogique[0,255]) pour les roues
  analogWrite(this->vAvance,vitesse); //on donne la vitesse voulu au pin attribuer à l'avancée des roues
  analogWrite(this->vRecul,LOW); //on donne la valeur LOW(0) au pin attribuer au recul du moteur
}

void moteurs::fMarche_arriere(int vitesse){//on utilise la fonction marche arriere et on sélectionne une vitesse(en valeur analogique[0,255]) pour les roues
  analogWrite(this->vAvance,LOW); //on donne la valeur LOW(0) au pin attribuer a l'avancée du moteur
  analogWrite(this->vRecul,vitesse); //on donne la vitesse voulu au pin attribuer au recul des roues
}

void moteurs::fArret(){// on utilise cette fonction pour stoper les roues: pour ça on donne la valeur LOW(0) aux deux pins
  analogWrite(this->vAvance,LOW);
  analogWrite(this->vRecul,LOW);
}
