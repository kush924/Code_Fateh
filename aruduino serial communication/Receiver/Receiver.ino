//
char i;
void setup() {
Serial.begin(9600);
Serial1.begin(9600);
}

void loop() 
{
  
  if(Serial1.available())
  {
  i = Serial1.read();
  }
  if(i='n')
  Serial.println("");
  else
  Serial.print(i);
  delay(100);
  
}
