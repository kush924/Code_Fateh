//A basic template for an Arduino Board sending data to another one using the Serial Ports.
//Sender code for an Arduino Nano

/* Working
   1) Receiver Sends a Query
   2) The Query is matched to a case 
   3) Sender sends the data to the Receiver*/

void setup() {
  Serial.begin(9600);
}
int i=96;
void loop() {

if (Serial.available())
{
 if(Serial.read()=='s');
 {
  Serial.write(i);
 }  
  }
 
   
}
