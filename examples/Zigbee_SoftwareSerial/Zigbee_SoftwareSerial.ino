//Zigbee CC2530 V1 vs Arduino Uno

#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  // put your setup code here, to run once:
  mySerial.begin(19200); //Baudrate của Zigbee CC2530V1
}

void loop() {
  // put your main code here, to run repeatedly:
  mySerial.write("Hello, world?");
  delay(1000);
}
