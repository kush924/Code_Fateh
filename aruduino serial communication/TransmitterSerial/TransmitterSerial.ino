//Transmitter

int button = 2;

void setup(){
  Serial.begin(9600);
  pinMode(button,INPUT_PULLUP);
  
}

void loop(){
  if(digitalRead(button)==0)
  {
    Serial.write("1");
  }
  delay(20);
}
