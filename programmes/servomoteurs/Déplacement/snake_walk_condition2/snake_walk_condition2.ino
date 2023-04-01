#include <Servo.h>
Servo myServos[10];



float pi=3.14159;
int TotalNumberofServos=7; //change as required
float Shift = 2*pi/TotalNumberofServos; // Phase lag between segments
float Wavelengths, rads;
int  MaxAngleDisplacement;
int r=0; //angle en degré
bool condition= true; //si vrai on continue sinon on stope tout

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
  //myServos[8].attach();
  //myServos[9].attach();

  
  //servos initialisation
  for(int i=0; i<8; i++){  
    myServos[i].write(90);
    delay(15); 
  }
  delay(2000);  
}

// calcul of the angle
float teta(int offset, int Amplitude, int Speed, float Wavelengths, int j, float rads){
return 90+offset+Amplitude*sin(Speed*rads+j*Wavelengths*Shift);
}

//align servos
void straightline(){
  for(int i=0; i<10; i++){  
    myServos[i].write(90);
    delay(100); 
  }
}

//the snake motion
void slither(int offset, int Amplitude, int Speed, float Wavelengths){
  MaxAngleDisplacement=abs(offset)+abs(Amplitude); //amount servo can rotate from the SetpointAngle without going out of the [0,180] degree range
  while(MaxAngleDisplacement>90){ //prevents a setpoint angle outside the rage of[0,180]
    Amplitude=abs(Amplitude)-1;
    MaxAngleDisplacement=abs(offset)+Amplitude;
  }
  while(condition){
    if(r>=360){
      r=0;
    }
    r= r+1;
    rads=r*pi/180;
   for(int j=0; j<8; j++){ 
      myServos[j].write(teta(offset,Amplitude,Speed,Wavelengths,j,rads));
      //Serial.println(rads);      
      /*Serial.print("servo ");
      Serial.print(j);
      Serial.print("angle= ");
      Serial.println(teta(offset,Amplitude,Speed,Wavelengths,j,rads));
   */
   }
     delay(10);
  }     
}

// choose the direction
void choose(int value){
  if(value==0){
    while(value==0){
      slither(2,35,2,0.8);//forward
      //read value
    }
  }
  else if(value==1){
    while(value==1){
      slither();//right turn
      //read value
    }
  }
  else if(value==2){
    while(value==2){
      slither();//left turn
      //read value
    }
}
  else if(value==3){
    while(value==3){
      slither();//bakward (négative amplitude?)
      //read value
    }
  }
  else{
    condition=false;
    while(value>3){
      slither();//stopp
      //read value
    }
  }  
}
    
void loop() {
  //slither(2,35,2,0.8);
  //ajouter les calls pour la modif de value
}
