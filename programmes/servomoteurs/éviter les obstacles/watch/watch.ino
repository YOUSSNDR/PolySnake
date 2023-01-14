#include <Servo.h>

Servo head;

int pinTrig = 3;
int pinEcho = 2;

long temps;
int distance;
//float vson= 340.29; //(m/s) error can come from here as it depends on the temperature
int liste[60]={}; //cette liste contiendra les 60 distances mesurées
int vue[]={90,135,180,90,45,0};//les différents angles de vues
void setup() {
  Serial.begin(9600);
  pinMode(A1,OUTPUT);
  head.attach(2);

  //define the Pin of the ultrasound sensor
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
    
  //initialise head and sensor
  head.write(90);
  digitalWrite(pinTrig, LOW);
  delay(2000);

}
float pulse(){

  digitalWrite(pinTrig, HIGH);        
  delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);

  temps = pulseIn(pinEcho, HIGH);    
//soit le temps durant  lequel dure l'écho
  if (temps > 25000) {              
    Serial.println("Echec de la mesure");
  }

  else {
    temps = temps/2;
    distance = (temps*340)/10000.0;                  
   //Serial.print("Distance: ");
    //Serial.print(distance);
    //Serial.println(" cm");
  }

}

void loop() {
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
