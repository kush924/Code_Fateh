/* Get tilt angles on X and Y, and rotation angle on Z
 * Angles are given in degrees
 * 
 * License: MIT
 */

#include "Wire.h"
#include <MPU6050_light.h>
#include <SoftwareSerial.h>
SoftwareSerial softSerial(2,3);

MPU6050 mpu(Wire);
unsigned long timer = 0;

void setup() {
  Serial.begin(9600);
  softSerial.begin(9600);
  Wire.begin();
  mpu.calcOffsets(); // gyro and accelero
}

void loop() {
  mpu.update();
  
  if((millis()-timer)>10){ // print data every 10ms
  Serial.println(mpu.getAngleX());
  softSerial.write(mpu.getAngleX());
  timer = millis();  
  }
}
