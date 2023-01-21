#include <Servo.h>

Servo head;

int pinTrig = 3;
int pinEcho = 2;

long temps;
int distance;
//float vson= 340.29; //(m/s) error can come from here as it depends on the temperature
int liste[60]={}; //this list will contain the 60 values measured
int vue[]={90,135,180,90,45,0};//the diffrents vision angle (might be reduct later)
void setup() {
  Serial.begin(9600);
  head.attach(2);

  //define the Pin of the ultrasound sensor
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
    
  //initialise head and sensor
  head.write(90);
  digitalWrite(pinTrig, LOW);
  delay(2000);

}
//the function allowing to take the measure
float pulse(){

  digitalWrite(pinTrig, HIGH);        
  delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);

  temps = pulseIn(pinEcho, HIGH);   //time of the echo
  
  if (temps > 25000) {              
    Serial.println("Echec de la mesure");
  }

  else {
    temps = temps/2;//as the soud go to the obstacle and come back
    distance = (temps*340)/10000.0;// in constant speed speed=distance/times
   //Serial.print("Distance: ");
    //Serial.print(distance);
    //Serial.println(" cm");
  }

}

void loop() {
//the function to look around and take the measure
for (int i=0;i<6;i++){
  head.write(vue[i]);
  delay(1000);
  for(int j=0;j>10;j++){
  pulse();
  liste[i*10+j]=distance;
  delay(500);
  }
}
for(int k=0;k<60;k++){
  Serial.print(liste[k]);
  Serial.print("-");
}
Serial.println();
delay(20);
}
