//Zigbee CC2530 V1 vs Arduino Uno

#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

int timer = 1000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin(19200); //Baudrate của Zigbee CC2530V1
  delay(500);
  mySerial.write("Start send");
  //Serial.println("Start send");
  for (int i = 1; i < 6; i++){
    mySerial.write("Hello, world?");
    //Serial.println("Hello, world?");
    delay(timer);
  }
  mySerial.write("Stop send");
  //Serial.println("Stop send");
}

void loop() {
  // put your main code here, to run repeatedly:

}
