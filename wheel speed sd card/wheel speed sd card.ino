int pinR=2;
#include <SD.h> //load sd card library
#include <SPI.h> // load the spi communication library
unsigned long duration;
float AngularSpeed=0;
int speedkmh=0;
float speedms=0;
float WheelRadius= 0.26;
File myFile; //variable for tachometer data
 

void setup() {
 pinMode(pinR,INPUT_PULLUP);
 Serial.begin(9600);

while (!Serial) {
; // wait for serial port to connect. Needed for native USB port only
} 
  Serial.print("Initializing SD card...");
  if (!SD.begin(10)) {
  Serial.println("initialization failed!");
  while (1);
}
Serial.println("initialization done.");
myFile = SD.open("test.txt", FILE_WRITE);
if (myFile) {
Serial.print("Writing to test.txt...");
myFile.println("Wheel Speed");
}

myFile.close();

}

void loop() {
  
    duration = pulseIn(pinR, HIGH,500000);
    if (duration>10000){
    AngularSpeed= (3.14159*1000000)/duration;
    speedms=(AngularSpeed*WheelRadius);
    speedkmh=(speedms*3.6);
    Serial.print(speedkmh);
    Serial.println(" km/hr");
    Serial.println();
    }

    else{
    Serial.print(0);
    Serial.println(" km/hr");
    Serial.println();
      }
    

}
