#include <SoftwareSerial.h>
SoftwareSerial softSerial(3,4);
String a="abc";
unsigned long timer = 0;

void setup() {
  Serial.begin(9600);
  softSerial.begin(9600);
}

void loop() {
  
  if((millis()-timer)>1000){ // print data every 10ms
  softSerial.print(a);
 // softSerial.write(F);
  timer = millis();  
  
  }
}
