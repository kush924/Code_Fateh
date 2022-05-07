
//Receiver
int led = 11;
int i;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial1.begin(9600);
pinMode(led,OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  if(Serial1.available())
  {
  i = Serial1.read();
   Serial.println(i);
  }
  delay(20);
 
}
