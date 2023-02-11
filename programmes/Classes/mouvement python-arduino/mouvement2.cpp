#include "mouvement.h"
#include "Arduino.h"
#include <cvzone.h>

mouvement::mouvement(){};

void mouvement::slither(int offset, int Amplitude, int Speed, float wavelengths){
  MaxAngleDisplacement=abs(offset)+abs(Amplitude); //amount servo can rotate from the SetpointAngle without going out of the [0,180] degree range
  while(MaxAngleDisplacement>90){ //prevents a setpoint angle outside the rage of[0,180]
    Amplitude=abs(Amplitude)-1;
    MaxAngleDisplacement=abs(offset)+Amplitude;
  }
  for(int i=0; i<360; i++){
   this->rads=i*pi/180.0;     //convert from degrees to radians le this nous permet de selectionner la variable rads de la class mouvement
   for(int j=0; j<9; j++){  
      myServos[j].write(90+offset+Amplitude*sin(Speed*this->rads+j*wavelengths*Shift));
     }
   delay(10);
  }
}

void mouvement::straightline(){
  for(int i=0; i<10; i++){  
    myServos[i].write(90);
    delay(100); 
  }
}