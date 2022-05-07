//Transmitter

int i=1;
int k=1;


void setup(){
  Serial.begin(9600);
 
  
}

void loop(){

   Serial.print(i);
   Serial.print('n');
    
 i++;
  delay(100);
}
