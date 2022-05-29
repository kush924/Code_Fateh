char a;
void setup() {
Serial.begin(9600);
Serial2.begin(9600);
}

void loop() {
//if(Serial2.available()>0);
//    if(Serial2.read()==F){Serial.println();}
//     Serial.print(Serial2.read());

  if(Serial2.available()){
    a = Serial2.read();
    Serial.print(a);
  }
}
