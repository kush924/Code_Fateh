#include <SPI.h>
#include <LoRa.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("CLEARDATA,LABEL,CLOCK,X,Y,Z,SPEED,DISTANCE");

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("DATA,");

    // read packet
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
      Serial.print("");
    }
    
     //print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
    
  }
}
