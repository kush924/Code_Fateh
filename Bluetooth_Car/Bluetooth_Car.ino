#include <Servo.h>
int Rf =11;
int Rb =3;
int Lf =6;
int Lb =5;
int Mop =10;
int servoPin =12;
volatile int val;

int Speed = 180;
char command;

Servo Servo1;
void setup() {
   Servo1.attach(servoPin); 
   Servo1.write(0);
  pinMode(Rf, OUTPUT);
  pinMode(Rb, OUTPUT);
  pinMode(Lf, OUTPUT);
  pinMode(Lb, OUTPUT);
  pinMode(Mop, OUTPUT);
  digitalWrite(Mop, HIGH);

  Serial.begin(9600);
}

void forward(){
  analogWrite(Rf, Speed);
  analogWrite(Lf, Speed);
}
void back(){
  analogWrite(Rb, Speed);
  analogWrite(Lb, Speed);
}
void left(){
  analogWrite(Rf, Speed);
  analogWrite(Lb, Speed);
}
void right(){
  analogWrite(Rb, Speed);
  analogWrite(Lf, Speed);
}

void Stop(){
  analogWrite(Rf, 0);
  analogWrite(Rb, 0);
  analogWrite(Lf, 0);
  analogWrite(Lb, 0);
}
void Clean(){
  digitalWrite(Mop, LOW);
}
void CleanStop(){
  digitalWrite(Mop, HIGH);
}
void ServoUp(){
  Servo1.write(0);
}
void ServoDown(){
  Servo1.write(90);
}

void loop() {
  if(Serial.available()){
    command = Serial.read(); 

    switch (command)
    {
      case 'F':
      Stop();  forward();
        break;
      case 'B':
      Stop();  back();
        break;
      case'R':
      Stop();  right();
        break;
      case'L':
      Stop();  left();
        break;
      case'W':
       Clean();
        break;
      case'w':
        CleanStop();
        break;
      case'U':
        ServoDown();
        break;
      case'u':
        ServoUp();
        break;
      case'S':
        Stop();
        break;
       
      
    }
  }


  

}
