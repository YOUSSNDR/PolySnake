int Ma=5;
int Mr=6;
float tps=0;
float tpsp;
void setup() {
  Serial.begin(9600);
  pinMode(Ma,OUTPUT);
  pinMode(Mr, OUTPUT);
  digitalWrite(Ma,LOW);
  digitalWrite(Mr,LOW);

delay(1000);
}

void loop() {
  /*tps=millis();
    tpsp=0;
while (tpsp-tps<2000){
  tpsp=millis();
  digitalWrite(Ma,HIGH);
  digitalWrite(Mr,LOW);
}
digitalWrite(Ma,LOW);
digitalWrite(Mr,LOW);
delay(2000);
tps=millis();
while (tpsp-tps<2000){
  tpsp=millis();
  digitalWrite(Ma,LOW);
  digitalWrite(Mr,HIGH);
}
digitalWrite(Ma,LOW);
digitalWrite(Mr,LOW);
delay(10000);*/
for(int i=0;i<256;i++){
tps=millis();
Serial.println(i);
while(tpsp-tps<500){
tpsp=millis();
analogWrite(Ma,i);
analogWrite(Mr,LOW);
}
}
delay(5000);
analogWrite(Ma,LOW);
analogWrite(Mr,LOW);
}



