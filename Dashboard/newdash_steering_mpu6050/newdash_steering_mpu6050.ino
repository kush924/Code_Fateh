//new 1 (not tested)
#include <SD.h>
#include <SPI.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <MPU6050_light.h>  //steer

MPU6050 mpu(Wire);          //steer
unsigned long timer = 0;    //steer

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

Wire.begin();

  //steer
  byte status = mpu.begin();
  Serial.print(F("MPU6050 status: "));
  Serial.println(status);
  while(status!=0){ } // stop everything if could not connect to MPU6050
  
  Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(1000);
  // mpu.upsideDownMounting = true; // uncomment this line if the MPU6050 is mounted upside-down
  mpu.calcOffsets(); // gyro and accelero
  Serial.println("Done!\n");
  //steer
  
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
  mpu.update();
  
//  if((millis()-timer)>10){ // print data every 10ms
//  Serial.print("X : ");
//  Serial.println(mpu.getAngleX());  //steer
//  /*Serial.print("\tY : ");
//  Serial.print(mpu.getAngleY());
//  Serial.print("\tZ : ");
//  Serial.println(mpu.getAngleZ());*/
//  timer = millis();  
//  }
  //steer
  
    
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
  Serial.print(",");
  Serial.print(mpu.getAngleX());  //steer
  Serial.println();
    lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("speed");
  lcd.setCursor(10,0);
  lcd.print(speedkmh);
  lcd.setCursor(3,1);
  lcd.print("angle");
  lcd.setCursor(10,1);
  lcd.print(mpu.getAngleX()); //steer



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
    sdcard_file.print(",");
    sdcard_file.println(mpu.getAngleX());  //steer
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
  Serial.print(mpu.getAngleX());//steer
  Serial.println();

  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("speed");
  lcd.setCursor(10,0);
  lcd.print("0");
  lcd.setCursor(3,1);
  lcd.print("angle");
  lcd.setCursor(10,1);
  lcd.print(mpu.getAngleX());//steer

  
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
    sdcard_file.print(",");
    sdcard_file.println(mpu.getAngleX()); //steer
    sdcard_file.close(); // close the file
 
  }
  else {
    Serial.println("error opening test.txt");
  }
  
  }
}
