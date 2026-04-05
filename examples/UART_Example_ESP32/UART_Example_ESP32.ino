/*
  Vietduino ESP32 - CC2530v1A - CC2530v1B - USB to UART
*/

// Define the RX and TX pins for Serial 2
#define RXD2 16  //D2-IO16
#define TXD2 17  //D3-IO17
// Define Baudrate for UART
#define CC2530_BAUD 19200

// Đặt tên cho chân kết nối cảm biến
#define analogInPin 34  // IO34-A1 on Vietduino ESP32 (A1 on MakerEdu Shield)
// Tạo biến số nguyên lưu giá trị cảm biến
int sensorValue = 0;

// Create an instance of the HardwareSerial class for Serial 2
HardwareSerial zigbeeSerial(2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);
  while (!Serial) {
    ;  // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Esp32 start");
  // Start Serial 2 with the defined RX and TX pins and a baud rate of 9600
  zigbeeSerial.begin(CC2530_BAUD, SERIAL_8N1, RXD2, TXD2);
  //zigbeeSerial.println("CH340E start to receive");
}

void loop() {
  // put your main code here, to run repeatedly:
  // Đọc giá trị cảm biến
  sensorValue = analogRead(analogInPin);
  //In ra serial monitor
  //Serial.print("Value: "); Serial.println(sensorValue);
  //Truyen du lieu den Uno
  zigbeeSerial.print("Value: ");
  zigbeeSerial.println(sensorValue);
  /*
  delay(100);
  //Nhan du lieu tu Uno   //Chua nhan duoc du lieu tu Uno
  if (zigbeeSerial.available()) {
    Serial.print(zigbeeSerial.read());
  }

  */
  delay(2000);
}
