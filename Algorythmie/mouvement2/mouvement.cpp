#include "mouvement.h"
#include "Arduino.h"


mouvement::mouvement(){}; //on fait appel a la classe mouvement

void mouvement::fOndulation(int vDecallage, int vAmplitude, int vVitesse, float vLongueur_d_onde){
  vAnglemaximal=abs(vDecallage)+abs(vAmplitude); //l'angle max que peut prendre le serpent en restant dans l'intervalle [0,180] degré
  while(vAnglemaximal>90){ //empèche un angle endehors de l'intervalle[0,180]
    vAmplitude=abs(vAmplitude)-1; //on rabaisse l'angle de 1 degré
    vAnglemaximal=abs(vDecallage)+vAmplitude; //on donne une nouvelle valeur a l'angle maximal
  }
  for(int i=0; i<360; i++){ //on parcour 360°
   this->rads=i*pi/180.0;     //convertis l'angle en degré en un angle en radiant
   for(int j=0; j< this->vNombre_total_de_servo +1; j++){  //on parcourt les servos pour leur donner leurs angles respectifs
      myServos[j].write(90+vDecallage+vAmplitude*sin(vVitesse*this->rads+j*vLongueur_d_onde*vDephasage)); //on rentre une fonction (sinusoîdale pour controler les ondulation) dans le write ce qui nous permet de donner un ordre aux servo
     }
   delay(10); //attente de 10 miliseconde pour laisser le temps aux servos d'atteindre les angles demandés
  }
}

void mouvement::fLigne(){
  for(int i=0; i<vNombre_total_de_servo +1; i++){  //on parcourt les servos
    myServos[i].write(90);// ils prennent la valeurs de 90° chacun (correspond à l'angle pour lequel on les initialise)
    delay(100); // attente pour laisser le temps a chaque servos d'atteindre l'angle demandé
  }
}