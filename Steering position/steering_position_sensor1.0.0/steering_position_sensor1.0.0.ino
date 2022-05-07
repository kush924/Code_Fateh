volatile long x , counter = 0; 
int z;
void setup() {
  Serial.begin (9600);
  pinMode(2, INPUT_PULLUP); 

  
  pinMode(3, INPUT_PULLUP); 
   
  attachInterrupt(0, A, RISING);
   
  attachInterrupt(1, B, RISING);
  }
  String a;
  void loop() {
  // Send the value of counter
  if(counter>x){
    a = "CCW";
  }
  else if(counter<x){
    a = "CW";
  }
  
  if( counter != x ){
  z = counter;
  if (z >0){
    z=z;
  }
  else if (z<0){
    z = -z;
  }
  Serial.print(z*0.5);
  Serial.print(" ");
  Serial.print(a);
  Serial.print("\n");
  //Serial.print(counter);
  //Serial.print("\n");
  x = counter;
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
