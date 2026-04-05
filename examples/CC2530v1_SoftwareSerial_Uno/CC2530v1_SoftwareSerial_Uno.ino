//Zigbee CC2530 V1 vs Arduino Uno

#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);
  mySerial.begin(19200); //Baudrate của Zigbee CC2530V1
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  while (!mySerial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Uno received at 19200 baud rate")
}

void loop() {
  // put your main code here, to run repeatedly:
  if (mySerial.available()) {
    Serial.println(mySerial.read());
  }
  delay(100);
}
