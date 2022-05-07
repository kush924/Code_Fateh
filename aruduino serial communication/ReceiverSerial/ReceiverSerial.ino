//Receiver
int led = 13;
char message;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(led,OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
  message = Serial.read();
   if (message== '1')
    {
      digitalWrite(led, 1);
    }
  }
  delay(20);
  digitalWrite(led,0);
}
