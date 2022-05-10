int Rf =11;
int Rb =10;
int Lf =6;
int Lb =5;
int Mop =9;

int Speed = 180;
char command;

void setup() {
  pinMode(Rf, OUTPUT);
  pinMode(Rb, OUTPUT);
  pinMode(Lf, OUTPUT);
  pinMode(Lb, OUTPUT);
  pinMode(Mop, OUTPUT);

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
  analogWrite(Mop, Speed);
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
      case'C':
      Stop();  Clean();
        break;
      case'S':
        Stop();
        break;
       
      
    }
  }


  

}
