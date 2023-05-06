#include "mouvement2.0.h"
#include "Arduino.h"


mouvement::mouvement(){};

float mouvement::teta(int offset, int Amplitude, int Speed, float Wavelengths, int j, float rads){
return 90+offset+Amplitude*sin(Speed*rads+j*Wavelengths*Shift);
}

float mouvement::choose(int value){
  if(value==0){
    condition=true;
    O, A, v, L = 2, 35, 2, 0.8;
    return(condition, O, A, v, L);
    //slither(2,35,2,0.8);//forward
    //read value
  }
  else if(value==1){
    condition=true;
    O, A, v, L = 32, 35, 2, 0.8;
    return(condition, O, A, v, L);
    //slither(30, 35, 2, 0.8);//right turn
    //read value
  }
  else if(value==2){
    condition=true;
    O, A, v, L = -32, 35, 2, 0.8;
    return(condition, O, A, v, L);
    //slither(-30, 35, 2, 0.8);//left turn
    //read value
}
  else if(value==3){
    condition=true;
    O, A, v, L = 62, 35, 2, 0.8;
    return(condition, O, A, v, L);
    //slither(60, 35, 2, 0.8);//bakward (négative amplitude?)
    //read value
  }
  else{
    condition=false;
    O, A, v, L = 0, 0, 2, 0.8;
    return(condition, O, A, v, L);
    //slither(0, 0, 2, 0.8);//stopp
    //read value
  }  
}

void mouvement::slither(int offset, int Amplitude, int Speed, float wavelengths){
  MaxAngleDisplacement=abs(offset)+abs(Amplitude); //amount servo can rotate from the SetpointAngle without going out of the [0,180] degree range
  while(MaxAngleDisplacement>90){ //prevents a setpoint angle outside the rage of[0,180]
    Amplitude=abs(Amplitude)-1;
    MaxAngleDisplacement=abs(offset)+Amplitude;
  }
  while(condition){
    x=Serial.readString().toInt();
    condition, O, A, v, L= choose(x);
    if(r>=360){
      r=0;
    }
    r= r+1;
    rads=r*pi/180;
   for(int j=0; j<8; j++){ 
      myServos[j].write(teta(offset,Amplitude,Speed,Wavelengths,j,rads));
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