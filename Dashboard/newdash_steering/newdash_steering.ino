//new 1 (not tested)
#include <SD.h>
#include <SPI.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
File sdcard_file;
LiquidCrystal_I2C lcd(0x27,16,2);

volatile long x , count = 0; //steer
unsigned long mytime;//steer
int z,l; //steer
String a;//steer
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
    pinMode(2, INPUT_PULLUP);//steer 

  
  pinMode(3, INPUT_PULLUP); //steer
   
  attachInterrupt(digitalPinToInterrupt(2), A, RISING);//steer
   
  attachInterrupt(digitalPinToInterrupt(3), B, RISING);//steer
  
  Serial.begin(9600);
  lcd.init();
  lcd.clear();         
  lcd.backlight(); 
  pinMode(pinR,INPUT);
  pinMode(CS_pin, OUTPUT);
 pinMode(A0,INPUT);


sd();
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
 sd();
  sdcard_file = SD.open("data.txt", FILE_WRITE);

  if (sdcard_file) { 
    sdcard_file.print(",Time in (ms),Speed,Distance,Brake,steer");   
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

 //steer
  mytime = millis();
  if( count != x ){
  z = count;
  z =-z;
  x = count;
  l=z*0.25;
  }
  

lcd.init();
  lcd.clear();         
  lcd.backlight(); 
  lcd.setCursor(0,0); 
voltage = analogRead(A0);
  voltage = voltage*(5.0 / 1023.0);
  float brake = (voltage-0.5)*25;
  duration = pulseIn(pinR,HIGH);
  Serial.println(duration);
  if (duration>500){
  AngularSpeed= (0.8377*1000000)/duration;
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
  Serial.print(",");
  Serial.print(l);
  Serial.println();

     sd();
     sdcard_file = SD.open("data.txt", FILE_WRITE);
   if (sdcard_file) { 
    sdcard_file.print(",");  
    sdcard_file.print(millis());
    sdcard_file.print(",");
    sdcard_file.print(speedkmh);
    sdcard_file.print(",");
    sdcard_file.print(Dist);
    sdcard_file.print(",");
    sdcard_file.println(brake);  
    sdcard_file.print(",");
    sdcard_file.println(l);  
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
  Serial.print(",");
  Serial.print(l);
  Serial.println();
  sd();
  sdcard_file = SD.open("data.txt", FILE_WRITE);
   if (sdcard_file) {    
    sdcard_file.print(","); 
    sdcard_file.print(millis());
    sdcard_file.print(",");
    sdcard_file.print("0");
    sdcard_file.print(",");
    sdcard_file.print(Dist);
    sdcard_file.print(",");
    sdcard_file.println(brake);
    sdcard_file.print(",");
    sdcard_file.println(l);
    sdcard_file.close(); // close the file
  }
  else {
    Serial.println("error opening test.txt");
  }
  
  }
}


//steer
void A() {
  if(digitalRead(3)==LOW) {
  count++;
  }else{
  count--;
  }
  }
   
  void B() {
  if(digitalRead(2)==LOW) {
  count--;
  }else{
  count++;
  }
}
