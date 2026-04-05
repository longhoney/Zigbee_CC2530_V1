/*Vietduino ESP32 - CC2530v1A - CC2530v1B - USB to UART*/

/*========Define UART========*/
// Define the RX and TX pins for Serial 2
#define RXD2 16  //D2-IO16
#define TXD2 17  //D3-IO17
// Define Baudrate for UART
#define CC2530_BAUD 19200
// Create an instance of the HardwareSerial class for Serial 2
HardwareSerial zigbeeSerial(2);

/*========Define Counter========*/
const int ledPin = 18;  // the number of the LED pin
// Variables will change:
int ledState = LOW;  // ledState used to set the LED
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;  // will store last time LED was updated
// constants won't change:
const long interval = 1000;  // interval at which to blink (milliseconds)

/*========Define for Sensor========*/
// Đặt tên cho chân kết nối cảm biến
#define analogInPin 34  // IO34-A1 on Vietduino ESP32 (A1 on MakerEdu Shield)
// Tạo biến số nguyên lưu giá trị cảm biến
int sensorValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);
  while (!Serial) {
    ;  // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Esp32 start");
  pinMode(ledPin, OUTPUT);
  // Start Serial 2 with the defined RX and TX pins and a baud rate of 9600
  zigbeeSerial.begin(CC2530_BAUD, SERIAL_8N1, RXD2, TXD2);
  //zigbeeSerial.println("CH340E start to receive");
}

void loop() {
  // put your main code here, to run repeatedly:
  // Đọc giá trị cảm biến
  sensorValue = analogRead(analogInPin);
  
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
      //Truyen du lieu den Uno
      if (zigbeeSerial.availableForWrite()){    //Neu chon ham while, ESP32 se gui du lieu lien tuc trong 1 giay
        zigbeeSerial.print("Value: "); zigbeeSerial.println(sensorValue);
      }
    } else {
      ledState = LOW;
      //Nhan du lieu tu Uno
      while (zigbeeSerial.available() > 0) {
        char inByte = zigbeeSerial.read();
        Serial.write(inByte);
      }
    }
    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }
}
