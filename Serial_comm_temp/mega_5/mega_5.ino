//mega
String a;
unsigned long timer = 0;
int i = 0;
void setup() {
Serial.begin(115200);
Serial2.begin(115200);
}

void loop() {

if((micros()-timer)>20000){
  Serial2.write('G');
  if(Serial2.available()){
    a = Serial2.readStringUntil('F');
    Serial.println(a);
    Serial.println(i);
    i++;
  }
  timer = micros();
  
}
  
}
