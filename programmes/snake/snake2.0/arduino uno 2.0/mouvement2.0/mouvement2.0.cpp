#include "mouvement2.0.h"
#include "Arduino.h"


mouvement::mouvement(){};


float mouvement::choose(int value){ //give the Condition, Offset, amplitude, speed and wavelength values depending on "value" 
  if(value==0){//forward
    condition=true;
    O, A, v, L = 2, 35, 2, 0.8;
    return(condition, O, A, v, L);
  }
  else if(value==1){//right turn
    condition=true;
    O, A, v, L = 32, 35, 2, 0.8;
    return(condition, O, A, v, L);
    //slither(30, 35, 2, 0.8);//right turn
    //read value
  }
  else if(value==2){//left turn
    condition=true;
    O, A, v, L = -32, 35, 2, 0.8;
    return(condition, O, A, v, L);
    //slither(-30, 35, 2, 0.8);//left turn
    //read value
}
  else if(value==3){//turn around
    condition=true;
    O, A, v, L = 62, 35, 2, 0.8;
    return(condition, O, A, v, L);
    //slither(60, 35, 2, 0.8);//bakward (négative amplitude?)
    //read value
  }
  else{//Stop
    condition=false;
    O, A, v, L = 0, 0, 2, 0.8;
    return(condition, O, A, v, L);
    //slither(0, 0, 2, 0.8);//stopp
    //read value
  }  
}


void mouvement::straightline(){ // give an angle of 90° to all the angle (initialisation)
  for(int i=0; i<10; i++){  
    myServos[i].write(90);
    delay(100); 
  }
}


float mouvement::teta(int offset, int Amplitude, int Speed, float Wavelengths, int j, float rads){
return 90+offset+Amplitude*sin(Speed*rads+j*Wavelengths*Shift);
 // calculating the angle of the servo j
}

void mouvement::slither(int offset, int Amplitude, int Speed, float wavelengths){
  MaxAngleDisplacement=abs(offset)+abs(Amplitude); //amount servo can rotate from the SetpointAngle without going out of the [0,180] degree range
  while(MaxAngleDisplacement>90){ //prevents a setpoint angle outside the rage of[0,180]
    Amplitude=abs(Amplitude)-1;
    MaxAngleDisplacement=abs(offset)+Amplitude;
  }
  while(condition){ // check the value sent by the raspberry and chose the direction
    x=Serial.readString().toInt(); //take the sent value
    condition, O, A, v, L= choose(x); //give the different value depending on "x"
    if(r>=360){ // to browse the circle
      r=0;
    }
    r= r+1;
    rads=r*pi/180; // from degree to rad
   for(int j=0; j<8; j++){ 
      myServos[j].write(teta(offset,Amplitude,Speed,Wavelengths,j,rads)); // calcul the angle for the servo j
   }
     delay(10); // let the time to reach the asked value
  }     
}
