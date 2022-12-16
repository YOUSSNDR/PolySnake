#include <Servo.h>

Servo myServos[10]; //create 10 servos


void setup() {
  Serial.begin(9600);
  //The following code can be cleaned up in a single for-loop if you solder the wires in a more continuous pattern than I did
  //Order of servos is such that myServos[0]=tail segment, and myServos[9]=head segment
  myServos[0].attach(A0);
  myServos[1].attach(A1);
  myServos[2].attach(A2);
  myServos[3].attach(A3);
  myServos[4].attach(A4);
  myServos[5].attach(A5);
  myServos[6].attach(7);
  myServos[7].attach(6);
  myServos[8].attach(5);
  myServos[9].attach(4);

  //Initialise snake in a straight line
  for(int i=0; i<10; i++){  
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

void loop() {
  straightline();
}
