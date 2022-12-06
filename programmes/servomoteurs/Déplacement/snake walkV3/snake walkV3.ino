#include<Servo.h>
Servo serv1;
Servo serv2;
Servo serv3;
int i1,i2,i3;
int tet[8]={90,112.5,135,112.5,90,67.5,45,67.5};
float angle;
int tempsmillis=90; // temps estimé pour une rotation de 1° (respectant 22.5° en 2s)
float deltatet=22.5;// différence entre deux angles consécutifs de tet[]
int degmicros=11;//1 degré donne environ 11micro seconds

void setup() {
  Serial.begin(9600);
  int k=0; //une variable permettant d'initialiser tous les servos
  serv1.attach(3);
  serv2.attach(5);
  serv2.attach(7);
  serv1.write(tet[0]);
  serv2.write(tet[0]);
  serv3.write(tet[0]);
  serv2.detach();
  serv3.detach();
  /*
  les autres servos a détacher
  */
  delay(3000);
}

void loop() {

  void microdelay(tempsmillis){
    t=millis();
    int T=0;
    while(T<tempsmillis){
      T=millis()-t;
    }
    return 0;
  }

  int conv(angle){
    return int(500+(1000*angle)/90)
  }
  for(i1=0;i1>7,i1++){
    if(k=1){serv2.attach(5);}
    if(k=2){serv3.attach(7);}
    /*
    .
    .
    . 9 servos à controler au total
    */
    if(i1>7){i1=0;} //créer une foction qui pourra etre utilisé plus tard
    i2=i1-1;
    if(i2<0){i2=7;}
    i3=i2-1;
    if(i3<0){i3=7;}
    /*
    ... variables des autres servos
    */
    for(int angl=0;angl>conv(deltatet),angle=angle + degmicros){
      if
      serv1.writemicroseconds(conv(tet[i1])-conv(deltat))//problème comment gérer les changement de sens ??
    }
    /*
    utilisation de writemicroseconds créer une classe pour ça
    serv1.write(tet[i1]); // a remplacer par un guidage en fonction de la vitesse voulu du servo
    serv2.write(tet[i2]);
    serv3.write(tet[i3]);
    /*
    6 servos à ajouter
    */
    k++;
    
  }

}
