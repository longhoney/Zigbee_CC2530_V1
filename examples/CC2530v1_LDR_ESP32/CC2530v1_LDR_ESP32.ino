//Vietduino ESP32 truyen du lieu LDR qua Zigbee CC2530 V1

#include <SoftwareSerial.h>

SoftwareSerial mySerial(19, 18); // RX-D12-IO19, TX-D13-IO18
// Đặt tên cho chân kết nối cảm biến
const int analogInPin = 34;  // IO34-A1 on Vietduino ESP32 (A1 on MakerEdu Shield)
// Tạo biến số nguyên lưu giá trị cảm biến
int sensorValue = 0;  

void setup() {// put your setup code here, to run once:
  //Serial.begin(19200);
  mySerial.begin(19200); //Baudrate của Zigbee CC2530V1
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  mySerial.write("Start send");
  //Serial.println("Start send");
  
}

void loop() { // put your main code here, to run repeatedly:
  // Đọc giá trị cảm biến
  sensorValue = analogRead(analogInPin);
  /*
  // Hiển thị giá trị đo được của cảm biến lên máy tính.
  Serial.print("Value: ");
  Serial.println(sensorValue)

  if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
  */
  mySerial.write("Value: "); mySerial.write(sensorValue);  mySerial.write('\n');
  //Nghỉ 2s
  delay(2000);
}
