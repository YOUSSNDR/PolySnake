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

void test(){
  for(int pos = 0; pos < 45; pos +=  1){
    myServos[0].write(90-pos);
    myServos[1].write(90+2*pos);
    myServos[2].write(90-pos);
    delay(10);
  }    

  for(int i=0; i<7; i+= 1){
    for(int pos = 0; pos < 45; pos +=  1){  
      myServos[i].write(45+pos);
      myServos[i+1].write(180-3*pos);
      myServos[i+2].write(45+3*pos);
      myServos[i+3].write(90-pos);
      delay(10);
    }    
  }
 
  for(int pos = 0; pos < 45; pos +=  1){  
    myServos[7].write(45+pos);
    myServos[8].write(180-2*pos);
    myServos[9].write(45+pos);
    delay(10);
  }  
}

void loop() {
  test();
}