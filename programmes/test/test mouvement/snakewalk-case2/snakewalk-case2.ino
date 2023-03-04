#include <Servo.h>
#include <cvzone.h>
Servo myServos[10];


SerialData serialData(1, 2); //(numOfValsRec,digitsPerValRec)
int valsRec[1]; // array of int with size numOfValsRec 
//On récup 1 seul valeur a 2 digits

float pi=3.14159;
int TotalNumberofServos=7; //change as required
float Shift = 2*pi/TotalNumberofServos; // Phase lag between segments
float Wavelengths, rads;
int  MaxAngleDisplacement;
int O=0; // Le Offset permettant de tourner
int A=0; // l'amplitude
int S=0; //la vitesse

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
  valsRec[0]=0;
  
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

void stop(){
  while(valsRec[0]==16){
    serialData.Get(valsRec);
  } 
}
// fige le serpent dans son mouvement tant qu'il ne reçoit pas d'autre ordre

void slither(int offset, int Amplitude, int Speed, float Wavelengths){
  MaxAngleDisplacement=abs(offset)+abs(Amplitude); //amount servo can rotate from the SetpointAngle without going out of the [0,180] degree range
  while(MaxAngleDisplacement>90){ //prevents a setpoint angle outside the rage of[0,180]
    Amplitude=abs(Amplitude)-1;
    MaxAngleDisplacement=abs(offset)+Amplitude;
  }
  for(int i=0; i<360; i++){
   rads=i*pi/180.0;     //convert from degrees to radians
   for(int j=0; j<8; j++){  
      serialData.Get(valsRec);      
       if (valsRec[0]=!0){
         while(valsRec[0]=!0){
            Switch(valsRec[0]){
               case 0:
                break;
               case 1:
                straightline()
                serialData.Get(valsRec);
               case 2:
                O=0;
                A=30;
                S=2.5;      
               slither(O,A,S,1.5);
               serialData.Get(valsRec);
               case 4:
                O=0;
                A=30;
                S=2.5;      
               slither(O,A,S,1.5);
               serialData.Get(valsRec);
               case 8:
               case 17:
               case 18:
               case 20:
               case 24:
               default:

              }
          }
        }
      //   while(valsRec[0]==1){
      //     straightline();
      //     serialData.Get(valsRec);          
      //   }
    }
      myServos[j].write(90+offset+Amplitude*sin(Speed*rads+j*Wavelengths*Shift));
     }
     delay(10);
    }
}

void loop() {
   slither(O,A,S,1.5);
}