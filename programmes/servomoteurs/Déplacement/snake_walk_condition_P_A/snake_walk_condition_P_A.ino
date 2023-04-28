#include <Servo.h>
Servo myServos[10];
#include <cvzone.h>

SerialData serialData(1,1);//(nombredevaleurs,chiffreparvalleur)
int condition[1]={0}; //tableau de la taille nombredevaleurs

float pi=3.14159;
int TotalNumberofServos=7; //change as required
float Shift = 2*pi/TotalNumberofServos; // Phase lag between segments
float Wavelengths, rads;
int  MaxAngleDisplacement;
int r=0; //angle en degré
 //si vrai on continue sinon on stop tout

void setup() {
  //Serial.begin(9600);
  serialData.begin();

  myServos[0].attach(13);
  myServos[1].attach(12);
  myServos[2].attach(11);
  myServos[3].attach(10);
  myServos[4].attach(9);
  myServos[5].attach(8);
  myServos[6].attach(7);
  myServos[7].attach(8);
  //myServos[7].attach(11);
  //myServos[8].attach();
  //myServos[9].attach();

  
  //initialisation des servos
  for(int i=0; i<8; i++){  
    myServos[i].write(90);
    delay(15); 
  }
  delay(2000);  
}
float teta(int offset, int Amplitude, int Speed, float Wavelengths, int j, float rads){
return 90+offset+Amplitude*sin(Speed*rads+j*Wavelengths*Shift);
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
  serialData.Get(condition);  
  while(condition[0]==0){
    if(r>=360){
      r=0;
    }
    r= r+1;
    rads=r*pi/180;
   for(int j=0; j<8; j++){ 
      myServos[j].write(teta(offset,Amplitude,Speed,Wavelengths,j,rads));
      
   }
   delay(10);
   serialData.Get(condition);
  }     
}
    
void loop() {
  slither(2,35,2,0.8);
}
