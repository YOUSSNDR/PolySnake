#include <Servo.h>
#include <cvzone.h>
Servo myServos[10];


SerialData serialData(1, 1); //(numOfValsRec,digitsPerValRec)
int var[1]={0}; // array of int with size numOfValsRec 


float pi=3.14159;
int TotalNumberofServos=7; //change as required
float Shift = 2*pi/TotalNumberofServos; // Phase lag between segments
float Wavelengths, rads;
int  MaxAngleDisplacement;


void setup() {
  Serial.begin(9600);

  serialData.begin();

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
    //vérif
    serialData.Get(var);
    switch (var[0]){
  case 0: //ligne
    while(var==0){
      serialData.Get(var);
      straightline();
    }
    break;
    
  case 1: //avance 
    offset=0;
    Amplitude=35;
    Speed=2.5;
    break;
    
  case 2: //avance en tournant droite
   offset= 30;
   Amplitude=35;
   Speed=2.5;
   break;
   
  case 3: //avance en tournant gauche
   offset= -30;
   Amplitude=35;
   Speed=2.5;
   break;
  
  default :
    while(var!=0||var!=1||var!=2||var!=3){
      serialData.Get(var);
    }
   break; 
  }   
   rads=i*pi/180.0;     //convert from degrees to radians
   for(int j=0; j<8; j++){
    serialData.Get(var);
     //vérif 
   switch (var[0]){
  case 0: //ligne
    while(var==0){
      serialData.Get(var);
      straightline();
    }
    break;
    
  case 1: //avance 
    offset=0;
    Amplitude=35;
    Speed=2.5;
    break;
    
  case 2: //avance en tournant droite
   offset= 30;
   Amplitude=35;
   Speed=2.5;
   break;
   
  case 3: //avance en tournant gauche
   offset= -30;
   Amplitude=35;
   Speed=2.5;
   break;
  
  default :
    while(var!=0||var!=1||var!=2||var!=3){
      serialData.Get(var);
    }
   break; 
  }   
      myServos[j].write(90+offset+Amplitude*sin(Speed*rads+j*Wavelengths*Shift));

     }
     delay(10);
    }    
}

void loop() {
/*slither tant qu'il y a pas de problème
si obstacle --> stop le mouvement prise de décision en fonction de l'information
--> tout se passe dans le slither

//prise de la var
switch (var){
  case 0: //ligne
    while(var==0){
      serialData.Get(var);
      straightline();
    }
    break;
    
  case 1: //avance 
    offset=0
    Amplitude=35
    Speed=2.5
    Wavelenght=1
    break;
    
  case 2: //avance en tournant droite
   offset= 30
   amplitude=35
   Speed=2.5
   Wavelenght=1
   break;
   
  case 3: //avance en tournant gauche
   offset= -30
   Amplitude=35
   Speed=2.5
   Wavelenght=1
   break;
  
  default :
    while(var!=0||var!=1||var!=2||var!=3){
      serialData.Get(var);
    }
   break; 
  }
  */
slither(0,35,2,1);
}