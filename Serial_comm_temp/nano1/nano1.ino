#include <SoftwareSerial.h>
SoftwareSerial softSerial(3,4);
float a=50.2;
String b = "abc";
unsigned long timer = 0;

void setup() {
  Serial.begin(9600);
  softSerial.begin(9600);
}

void loop() {
  
  if((millis()-timer)>1000){ // print data every 10ms
  softSerial.print(a);
  softSerial.print(b);
 // softSerial.write(F);
  timer = millis();  
  
  }
}
