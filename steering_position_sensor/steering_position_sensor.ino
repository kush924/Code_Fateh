volatile long x , counter = 0; 
unsigned long mytime;
int z,l;
void setup() {
  Serial.begin (9600);
  pinMode(2, INPUT_PULLUP); 

  
  pinMode(3, INPUT_PULLUP); 
   
  attachInterrupt(digitalPinToInterrupt(2), A, RISING);
   
  attachInterrupt(digitalPinToInterrupt(3), B, RISING);
  }
  String a;
  void loop() {
  mytime = millis();
  if( counter != x ){
  z = counter;
  z =-z;
  x = counter;
  l=z*0.25;
  }
  if(mytime % 500 == 0){
  Serial.print(l);
  }
  }

  
  void A() {
  if(digitalRead(3)==LOW) {
  counter++;
  }else{
  counter--;
  }
  }
   
  void B() {
  if(digitalRead(2)==LOW) {
  counter--;
  }else{
  counter++;
  }
}
