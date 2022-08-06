#include<CAN.h>
#include<SD.h>
#include<SPI.h>

#define cs 10
#define in 2
#define clockFreq 8E6
#define canFreq   500E3

unsigned long RPM;
float temp;


void setup(){
  
    Serial.begin(9600);
    canSetup(cs,in,clockFreq,canFreq);



    
}
    
void loop(){
   getCAN(&RPM,&temp);
      
    




}
