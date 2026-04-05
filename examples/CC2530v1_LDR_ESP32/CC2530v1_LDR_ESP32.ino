/*********
  Rui Santos & Sara Santos - Random Nerd Tutorials
  Complete instructions at https://RandomNerdTutorials.com/esp32-neo-6m-gps-module-arduino/
  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files.
  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
*********/

// Define the RX and TX pins for Serial 2
#define RXD2 16   //D2-IO16
#define TXD2 17   //D3-IO17
// Define Baudrate for UART
#define CC2530_BAUD 19200

// Đặt tên cho chân kết nối cảm biến
#define analogInPin 34  // IO34-A1 on Vietduino ESP32 (A1 on MakerEdu Shield)
// Tạo biến số nguyên lưu giá trị cảm biến
int sensorValue = 0;

// Create an instance of the HardwareSerial class for Serial 2
HardwareSerial zigbeeSerial(2);

void setup() {
  // Serial Monitor
  Serial.begin(19200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  // Start Serial 2 with the defined RX and TX pins and a baud rate of 9600
  zigbeeSerial.begin(CC2530_BAUD, SERIAL_8N1, RXD2, TXD2);
  while (!zigbeeSerial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  zigbeeSerial.println("ESP32 sent at 19200 baud rate");
}

void loop() {
  // Đọc giá trị cảm biến
  sensorValue = analogRead(analogInPin);
  //Truyền dữ liệu qua Zigbee
  zigbeeSerial.print("Value: "); zigbeeSerial.println(sensorValue);
  delay(2000);
}