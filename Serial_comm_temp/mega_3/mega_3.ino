String a;
unsigned long timer = 0;
void setup() {
Serial.begin(115200);
Serial2.begin(115200);
}

void loop() {
//if(Serial2.available()>0);
//    if(Serial2.read()==F){Serial.println();}
//     Serial.print(Serial2.read());
if((micros()-timer)>1000000){
  Serial2.write('G');
  timer = micros();
}
  if(Serial2.available()){
    a = Serial2.readStringUntil('F');
    Serial.println(a);
  }
}
