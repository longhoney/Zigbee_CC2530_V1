/*
  Uno - CC2530v1A - CC2530v1B - USBtoUART2
 */
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(19200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.write("Uno start to send");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(19200);
  mySerial.write("Uno tx");
}

void loop() { // run over and over
  if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
  if (Serial.available()) {
    mySerial.write(Serial.read()); mySerial.write('\n');
  }
}
