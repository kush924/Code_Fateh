#include <SoftwareSerial.h>
SoftwareSerial softSerial(3,4);
float a=50.2;
String b = "abc";
unsigned long timer = 0;

void setup() {
  Serial.begin(115200);
  softSerial.begin(115200);
}

void loop() {
  
  if(softSerial.available()){
  if(softSerial.read()=='G'){
  softSerial.print(a);
  softSerial.write('F'); 
  }
  }
}
