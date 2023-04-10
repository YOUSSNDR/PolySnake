
int x;

void setup() {
Serial.begin(115200);
Serial.setTimeout(1);
pinMode(LED_BUILTIN, OUTPUT);
}

void blink(float t){
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(t*500);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(t*500);                      // wait for a second
}


void loop() {
  while(!Serial.available());
    x=Serial.readString().toInt();
    if(x<10){
    while(x<10){
      blink(1);
      x=Serial.readString().toInt();
      }
    }
    else if (10<=x<20){
      while(10<=x<20){
        blink(0.5);
        x=Serial.readString().toInt();
      }
    }
    else if (x>=20){
      while(x>=20){
        digitalWrite(LED_BUILTIN,HIGH);
        x=Serial.readString().toInt();
      }
    }



}
