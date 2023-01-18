#include <Servo.h>

Servo myServos[10]; //create 10 servos

float pi=3.14159;
int TotalNumberofServos=6; //change as required
float Shift = 2*pi/TotalNumberofServos; // Phase lag between segments
float Wavelengths, rads;
int InteriorAngle, SetpointAngle, MaxAngleDisplacement;

void setup() {
  Serial.begin(9600);
  //The following code can be cleaned up in a single for-loop if you solder the wires in a more continuous pattern than I did
  //Order of servos is such that myServos[0]=tail segment, and myServos[9]=head segment
  myServos[0].attach(2);
  myServos[1].attach(3);
  myServos[2].attach(8);
  myServos[3].attach(9);
  myServos[4].attach(12);
  myServos[5].attach(13);
  //myServos[6].attach(4);
  //myServos[7].attach(3);
  //myServos[8].attach(8);
  //myServos[9].attach(7);

  //Initialise snake in a straight line
  for(int i=0; i<10; i++){  
    myServos[i].write(90);
    delay(15); 
  }
  delay(2000);
}

void ring(){
  InteriorAngle=180-360/(TotalNumberofServos+1); //general formula for a polygon with 3 or more vertices, +1 vertice between tail and head segment
  SetpointAngle=abs(InteriorAngle-90); //Offset the angle from the initial position of 90 degrees. 
  for(int i=0; i<10; i++){  
    myServos[i].write(SetpointAngle);
    delay(100); 
  }
}

void loop(){
  ring();
}