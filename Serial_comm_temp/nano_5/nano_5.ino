//nano
#include <SoftwareSerial.h>
SoftwareSerial softSerial(3,4);
int p1 = 2;
float a=50.2;
String b = "abc";
volatile unsigned long timer = 0 , duration = 0 ;

void setup() {
  Serial.begin(115200);
  softSerial.begin(115200);
  pinMode(p1,INPUT_PULLUP);
}

void loop() {
  duration = pulseIn(p1,HIGH);
  Serial.println(duration);

  
  if(softSerial.available()){
  if(softSerial.read()=='G'){
  softSerial.print(duration);
  softSerial.write('F'); 
  }
  }
}
