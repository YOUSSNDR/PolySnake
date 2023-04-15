#include <Servo.h>
Servo myServos[10];



float pi=3.14159;
int TotalNumberofServos=7; //change as required
float Shift = 2*pi/TotalNumberofServos; // Phase lag between segments
float Wavelengths, rads;
int  MaxAngleDisplacement;

void setup() {
  Serial.begin(9600);


  myServos[0].attach(2);
  myServos[1].attach(3);
  myServos[2].attach(4);
  myServos[3].attach(6);
  myServos[4].attach(7);
  myServos[5].attach(8);
  myServos[6].attach(10);
  myServos[7].attach(11);
  myServos[8].attach(8);
  myServos[9].attach(5);

  
  //initialisation des servos formant une ligne droite
   for(int i=0; i<8; i++){  
    myServos[i].write(90);
    delay(15); 
  }
  delay(2000);

}


void straightline(){
  for(int i=0; i<10; i++){  
    myServos[i].write(90);
    delay(100); 
  }

}

void slither(int offset, int Amplitude, int Speed, float Wavelengths){
  MaxAngleDisplacement=abs(offset)+abs(Amplitude); //amount servo can rotate from the SetpointAngle without going out of the [0,180] degree range
  while(MaxAngleDisplacement>90){ //prevents a setpoint angle outside the rage of[0,180]
    Amplitude=abs(Amplitude)-1;
    MaxAngleDisplacement=abs(offset)+Amplitude;
  }
  for(int i=0; i<360; i++){
   rads=i*pi/180.0;     //convert from degrees to radians
   int j=5; 
      myServos[j].write(90+offset+Amplitude*sin(Speed*rads+j*Wavelengths*Shift));

     delay(1000);
    }    
}


void loop() {
 /*la fonction slither est le "snakewalk" 
 jouer sur le ofset permet une rotation du serpent
jouer sur l'amplitude fera varier la place prise lors du mouvement
speed joue sur la vitesse du mouvement
wavelenght joue sur la longueur d'onde des oscillations
le shift permet une différence de phase entre les servos

*/

 /* for(int i=0;i<45;){  
    slither(i, 30, 3, 1); //avance
    i=i+5;
}*/
  
  slither(2,30,2,1.5);
  //traightline();
  //slither(20, 35, 3, 1); //avance et tourne légèrement (droite)
  //slither(-20, 35, 2, 1.5);//avance et tourne légèrement (gauche)

}