//Transmitter

float i=123.45;

String j=String(i);

void setup(){
  Serial.begin(9600);

}

void loop(){
 

  
   Serial.print(j);
  
    

  delay(500);
}
