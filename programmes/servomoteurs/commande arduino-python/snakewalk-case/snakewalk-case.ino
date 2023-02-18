#include <Servo.h>
#include <cvzone.h>
Servo myServos[10];


SerialData serialData(1, 1); //(numOfValsRec,digitsPerValRec)
int valsRec[1]; // array of int with size numOfValsRec 


float pi=3.14159;
int TotalNumberofServos=7; //change as required
float Shift = 2*pi/TotalNumberofServos; // Phase lag between segments
float Wavelengths, rads;
int  MaxAngleDisplacement;
bool arret=false;
int O=0;
int A=0;
int S=0;
int firstval;

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
   rads=i*pi/180.0;     //convert from degrees to radians
   serialData.Get(valsRec);
   if(valsRec[0]=!firstval){
     break;
   }
   for(int j=0; j<8; j++){  
      myServos[j].write(90+offset+Amplitude*sin(Speed*rads+j*Wavelengths*Shift));
     }
     delay(10);
     if (arret==true){
       break;
     }
     if (arret==true){
       break;
     }
    }
   
}



void loop() {
  
    while(true){
    switch (valsRec[0]){
     case 0:
      while(valsRec[0]==0 || valsRec[0]==18 || valsRec[0]==20 || valsRec[0]==24){
        serialData.Get(valsRec);
        firstval==valsRec[0];
      }
     case 1:
      straightline();
      serialData.Get(valsRec);
      firstval==valsRec[0];
     case 2:
     arret=false;
      O=0;
      A=30;
      S=2.5;      
      slither(O,A,S,1.5);
      serialData.Get(valsRec);
      firstval==valsRec[0];
     case 4:
     arret=false;
      O=45;
      A=30;
      S=2.5;      
      slither(O,A,S,1.5);
      serialData.Get(valsRec);
      firstval==valsRec[0];
     case 8:
     arret=false;
      O=-45;
      A=30;
      S=2.5;      
      slither(O,A,S,1.5);
      serialData.Get(valsRec);
      firstval==valsRec[0];
     case 17:
      valsRec[0]=1;
     case 18:
      arret=true;      
      O=0;
      A=30;
      S=2.5;      
      slither(O,A,S,1.5);
      valsRec[0]=0;
     case 20:
     arret=true;      
      O=45;
      A=30;
      S=2.5;      
      slither(O,A,S,1.5);
      valsRec[0]=0;
     case 24:
     arret=true;      
      O=-45;
      A=30;
      S=2.5;      
      slither(O,A,S,1.5);
      valsRec[0]=0;
            }
        }
}