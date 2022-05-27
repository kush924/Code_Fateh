#include <SoftwareSerial.h>
SoftwareSerial softSerial(2,3);
float a=0;
unsigned long timer = 0;

void setup() {
  Serial.begin(9600);
  softSerial.begin(9600);
}

void loop() {
  
  if((millis()-timer)>10){ // print data every 10ms
  Serial.println(a);
  softSerial.write(a);
  timer = millis();  
  a++;
  }
}
