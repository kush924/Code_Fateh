#include <SPI.h>
#include <LoRa.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("CLEARDATA");
  Serial.println("LABEL,CLOCK,X,Y,Z,SPEED,DISTANCE,VOLTAGE,PACKETRSSI");

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
    Serial.print("DATA,TIME,");

    // read packet
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }

    // print RSSI of packet
    
    Serial.println(LoRa.packetRssi());
    
  }
}
