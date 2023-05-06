int pinTrig = 3;
int pinEcho = 2;

long temps;
int distance;

void setup() {
  Serial.begin(9600);
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
}

float pulse(){

  digitalWrite(pinTrig, HIGH);        
  delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);

  temps = pulseIn(pinEcho, HIGH);   //time of the echo
  
  if (temps > 25000) {              
    Serial.println(999);
  }

  else {
    temps = temps/2;//as the soud go to the obstacle and come back
    distance = (temps*340)/10000.0;// in constant speed speed=distance/times
   //Serial.print("Distance: ");
    Serial.print(distance);
    //Serial.println(" cm");
  }

}

void loop() {
  pulse();

}
