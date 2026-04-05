/*
  Uno - CC2530v1A - CC2530v1B - USBtoUART2
 */
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3);  // RX, TX

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(19200);
  while (!Serial) {
    ;  // wait for serial port to connect. Needed for native USB port only
  }

  Serial.println("Uno start");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(19200);
  //mySerial.println("CH340E start to receive");
}

void loop() {  // run over and over
  //Nhan du lieu tu ESP32
  if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
  //delay(100);
  //Truyen du lieu den ESP32
  
  //mySerial.write(Serial.read()); //bat dong nay se khien du lieu bi loan di
}
