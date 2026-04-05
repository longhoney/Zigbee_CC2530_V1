/*
  Uno - CC2530v1A - CC2530v1B - USBtoUART2
 */
#include <SoftwareSerial.h>

/*========Define for UART========*/
SoftwareSerial mySerial(2, 3);  // RX, TX

/*========Define Counter========*/
// constants won't change. Used here to set a pin number:
const int ledPin = LED_BUILTIN;  // the number of the LED pin
// Variables will change:
int ledState = LOW;  // ledState used to set the LED
// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;  // will store last time LED was updated
// constants won't change:
const long interval = 1000;  // interval at which to blink (milliseconds)

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(19200);
  while (!Serial) {
    ;  // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Uno start");
  pinMode(ledPin, OUTPUT);
  // set the data rate for the SoftwareSerial port
  mySerial.begin(19200);
}

void loop() {  // run over and over
  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
      //Nhan du lieu tu ESP32
      while (mySerial.available() > 0) {
        char inByte1 = mySerial.read();
        Serial.write(inByte1);
      }
    } else {
      ledState = LOW;
      //Truyen du lieu den ESP32
      mySerial.write(Serial.read());
    }

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }
}
