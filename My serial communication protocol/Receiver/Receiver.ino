void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
}
int i;

void loop() {
Serial1.print('s');
delay(1);
if (Serial1.available())
{
  i=Serial1.read();
  Serial.println(i);
}


}
