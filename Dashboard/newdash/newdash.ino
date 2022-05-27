//new 1 (not tested)
#include <SD.h>
#include <SPI.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
File sdcard_file;
LiquidCrystal_I2C lcd(0x27,16,2);

int CS_pin = 9; // sd card ss pin
int pinR=4;   //speed sensor
unsigned long duration; // 
float AngularSpeed=0;
float speedkmh=0;
float speedms=0;
float WheelRadius= 0.26 ;
float Circum = 16.6;
float Dist=0;
float brake=0;
float voltage=0;
long unsigned int counter=0; 




void setup() {
  
  Serial.begin(9600);
  lcd.init();        
  lcd.backlight(); 
  pinMode(pinR,INPUT);
  pinMode(CS_pin, OUTPUT);
 pinMode(A0,INPUT);


  if (SD.begin(CS_pin))
  {
    Serial.println("SD card is ready to use.");
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("sd ready");
  } else
  {
    Serial.println("SD card initialization failed");
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("sd fail");
  }
 sdcard_file = SD.open("data.txt", FILE_WRITE);

  if (sdcard_file) { 
    sdcard_file.print(",Time in (ms),Speed,Distance,Brake");   
    sdcard_file.println();
    sdcard_file.close();
  }
  else {
    Serial.println("error opening test.txt");
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("sd open fail");
  }
}


void loop() {

  
    
 voltage = analogRead(A0);
  voltage = voltage*(5.0 / 1023.0);
  float brake = (voltage-0.5)*25;
  duration = pulseIn(pinR,HIGH);
  Serial.println(duration);
  if (duration>1500){
  AngularSpeed= (0.4377*1000000)/duration;
  speedms=(AngularSpeed*WheelRadius);
  speedkmh=(speedms*3.6);
  counter=counter+1;
  
  Dist = counter*Circum;

  Serial.print(",");
  Serial.print(millis());
  Serial.print(",");
  Serial.print(speedkmh);
  Serial.print(",");
  Serial.print(Dist);  
  Serial.print(",");
  Serial.print(brake);
  Serial.println();
    lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("speed");
  lcd.setCursor(10,0);
  lcd.print(speedkmh);
  lcd.setCursor(3,1);
  lcd.print("angle");



    sdcard_file = SD.open("data.txt", FILE_WRITE);
    if (sdcard_file) { 
    sdcard_file.print(",");  
    sdcard_file.print(millis());
    sdcard_file.print(",");
    sdcard_file.print(speedkmh);
    sdcard_file.print(",");
    sdcard_file.print(Dist);
    sdcard_file.print(",");
    sdcard_file.print(brake);  
    sdcard_file.close(); // close the file

  }
  // if the file didn't open, print an error:
  else {
    Serial.println("error opening test.txt");
  }

  }
  
  else{
 
  Serial.print(",");
  Serial.print(millis());
  Serial.print(",");
  Serial.print(0);
  Serial.print(",");
  Serial.print(Dist); 
  Serial.print(",");
  Serial.print(brake);
  Serial.println();

  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("speed");
  lcd.setCursor(10,0);
  lcd.print("0");

  
  sdcard_file = SD.open("data.txt", FILE_WRITE);
   if (sdcard_file) {    
    sdcard_file.print(","); 
    sdcard_file.print(millis());
    sdcard_file.print(",");
    sdcard_file.print("0");
    sdcard_file.print(",");
    sdcard_file.print(Dist);
    sdcard_file.print(",");
    sdcard_file.print(brake);
    sdcard_file.close(); // close the file
 
  }
  else {
    Serial.println("error opening test.txt");
  }
  
  }
}
