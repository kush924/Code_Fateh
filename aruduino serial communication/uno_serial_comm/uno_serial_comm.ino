//Uno

int kmhold=45;
char kmh[]={"50"};
char message = "";
void setup(){
  Serial.begin(9600);
}

void loop(){
  if(Serial.available())
  {
    message = Serial.read();
    if (message == 's')
    Serial.write(kmh);
    Serial.write('n');   
  }
delay(100);
}
