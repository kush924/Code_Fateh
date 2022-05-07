//#include <SPI.h>
//#include <LoRa.h> //Libraries for LoRa

//#include <Adafruit_MPU6050.h>
//#include <Adafruit_Sensor.h>
//#include <Wire.h>
//
//Adafruit_MPU6050 mpu;

int pinR=4;   //Pin for magnetic sensor 
int Brake= A0;
unsigned long duration; // 
float AngularSpeed=0;
float speedkmh=0;
float speedms=0;
float WheelRadius= 0.26;
float Circum = 2*3.14159*WheelRadius;
float Dist=0;
long unsigned int counter=0;
void setup() {
// pinMode(Brake, INPUT) ;
 pinMode(pinR,INPUT_PULLUP);
 Serial.begin(115200);

//  if (!LoRa.begin(433E6)) {
//    Serial.println("Starting LoRa failed!");
//    while (1);
  }

 // LoRa.setTxPower(20);
//
//    if (!mpu.begin()) {
//    Serial.println("Failed to find MPU6050 chip");
//    while (1) {
//      delay(10);
//    }
//  }

    // set accelerometer range to +-8G
 // mpu.setAccelerometerRange(MPU6050_RANGE_8_G);

  // set gyro range to +- 500 deg/s
 // mpu.setGyroRange(MPU6050_RANGE_500_DEG);

  // set filter bandwidth to 21 Hz
 // mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
   
}

void loop() {

//  sensors_event_t a, g, temp;
//  mpu.getEvent(&a, &g, &temp);

//  int sensorValue = analogRead(Brake);

//  float voltage = sensorValue * (5.0 / 1023.0);

  duration = pulseIn(pinR, HIGH,500000);
  if (duration>1000){
  AngularSpeed= (3.14159*1000000)/duration;
  speedms=(AngularSpeed*WheelRadius);
  speedkmh=(speedms*3.6);
  counter=counter+1;
  Dist = counter*Circum;
//  Serial.print(a.acceleration.x);
//  Serial.print(",");
//  Serial.print(a.acceleration.y);
//  Serial.print(",");
//  Serial.print(a.acceleration.z);
//  Serial.print("   ,   ");
  Serial.print(speedkmh);
  Serial.print(" km/hr");
  Serial.print("   ,   ");
  Serial.print(Dist);
  Serial.print(" m");  
  Serial.println();
  
    
//  LoRa.beginPacket();
//  LoRa.print(a.acceleration.x);
//  LoRa.print(",");
//  LoRa.print(a.acceleration.y);
//  LoRa.print(",");
//  LoRa.print(a.acceleration.z);
//  LoRa.print(",");
  LoRa.print(speedkmh);
  LoRa.print(",");
  LoRa.print(Dist);
  LoRa.print(",");
 // LoRa.print(voltage);

  LoRa.endPacket();

  }
//  
  else{
//  Serial.print(a.acceleration.x);
//  Serial.print(",");
//  Serial.print(a.acceleration.y);
//  Serial.print(",");
//  Serial.print(a.acceleration.z);
//  Serial.print("   ,   ");
  Serial.print(0);
  Serial.print(" km/hr");
  Serial.print("   ,   ");
  Serial.print(Dist);
  Serial.print(" m");  
//  Serial.print(voltage);
  Serial.println();
//  
//    
//  LoRa.beginPacket();
//  LoRa.print(a.acceleration.x);
//  LoRa.print(",");
//  LoRa.print(a.acceleration.y);
//  LoRa.print(",");
//  LoRa.print(a.acceleration.z);
//  LoRa.print(",");
  LoRa.print(0);
  LoRa.print(",");
  LoRa.print(Dist);  
  LoRa.print(",");
  //LoRa.print(voltage);
  LoRa.print(",");
  LoRa.endPacket();
//
   }
}
