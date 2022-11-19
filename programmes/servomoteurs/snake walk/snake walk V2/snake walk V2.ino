 #include <servo.h>
Servo servo0;
Servo servo1;
Servo servo2;
int tet[3]=[45,90,135]; //ce sont les angles que prendont les servos
// essayer en parcourant letableau de droite a gauche et de gauche a droite
/* l'angle d'un servo va dépendre de celui du servo avant lui
etat sera lié avec tet chaque état définira une action des servo 0=45°  1=90°  2=135°
*/
int etat0; //etat du servo0
int etat1;
int etat2;
/* on utiliseras un système d'action passé et en cours pour déterminer la suivante
nxtangle sont les angles visés
*/
int nxtangle0; // prochains angles a atteindre pour servo0
int nxtangle1;
int nxtangle2;

void setup() {
Serial.begin(9600);
  servo0.attach(3);
  servo2.attach(5);
  servo3.attach(7);
  servo.write(90);
  servo2.write(90);
  servo3.write(90);

  nxtangle0=tet[0];
  etat0=1;
  etat1=1;
  etat2=1;
  delay(3000);

}
// on va d'abord s'occuper du servo0 et ensuite adapter les autres à celui-ci
void loop() {
  /*on fait une boucle qui si le servo et a un angle donné est que sa position suivante est a un autre angle
  demandera au servo d'aller a ce nouvel angle
  */
  if(etat0==1 && nxtangle==tet[0]){
    servo0.write(tet[0]);
    servo1.write(tet[1]);
    servo2.write(tet[2]);
    nxtangle0=tet[etat0];
    etat0=0

    delay(1000);
  }
  else if(etat0==1 && nxtangle==tet[2]){
    servo0.write(tet[2]);
    servo1.write(tet[1]);
    servo2.write(tet[0]);
    nxtangle0=tet[etat0];
    etat0=2;
    delay(1000);
  }
  else if (etat0=2){ //la condition sur nxtangle est inutile ici
    servo0.write(tet[1]);
    servo1.write(tet[2]);
    servo2.write(tet[1]);
    nxtangle0=tet[0];
    delay(1000);
  }
  else{
    servo0.write(tet[1]);
    servo1.write(tet[2]);
    servo2.write(tet[1]);
    nxtangle0=tet[2];
    delay(1000);
  } 
  
 // for(int i=0,i>len(tet),i++)
}



/* ce prgrm semble trop complexe pour seulement 3 servo il y aura in-fine 8 ou 9 servo il faut siplifié le prgrm
utilisation d'une boucle for pour gérer la vitesse de rotation et de if pour gérer les servos
