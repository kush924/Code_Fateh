//Transmitter


void setup(){
  Serial.begin(9600);
  
}
int i=10;

void loop(){
  
 
if(Serial.available()){
    Serial.write('i');
  
    delay(200);
}
}
