//Receiver
String i;
void setup() {
Serial.begin(9600);
Serial1.begin(9600);
}

void loop() 
{
  if(Serial1.available())
  {
  i = Serial1.readStringUntil('5');
  Serial.println(i);
  }
  
  delay(600);
  
}
