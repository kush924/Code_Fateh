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


void sd(){
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  }

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.clear();         
  lcd.backlight(); 
  pinMode(pinR,INPUT);
  pinMode(CS_pin, OUTPUT);
 pinMode(A0,INPUT);
}

sd();
   if (SD.begin(CS_pin))
  {
    Serial.println("SD card is ready to use.");
  } else
  {
    Serial.println("SD card initialization failed");
  }
 sd();
  sdcard_file = SD.open("data.txt", FILE_WRITE);

  if (sdcard_file) { 
    sdcard_file.print(",Time in (ms),RPM,TEMP,Speed,Distance,Brake");   
    sdcard_file.println();
    sdcard_file.close();
  }
  else {
    Serial.println("error opening test.txt");
  }
 
