Truyền thông giữa Vietduino ESP32, Arduino Uno R3 SMD và Maixduino (ESP32) thông qua mạng Zigbee. Các module tham gia: Module DHT11, Module LDR, MOdule LCD I2C, cảm biến siêu âm SR04, ...

Vietduino ESP32, Maixduino (ESP32) giao tiếp TTL 3v3. Uno giao tiếp TTL 5v. Zigbee CC2530 V1 giao tiếp TTL 3v3/5v (Tùy VCC). Vietduino ESP32, Arduino, Maixduino (ESP32) dùng Arduino IDE.

Zigbee giao tiếp UART với các vi điều khiển. Chọn baudrate: 19200, số kênh tùy theo chương trình mẫu, chế độ truyền tùy theo chương trình mẫu.

Tham khảo chương trình SoftwareSerialExample: Nếu Serial rảnh (sau khi đọc xong dữ liệu nhập vào ô nhập liệu), mySerial sẽ viết nội dung mà Serial "đã" đọc được.

Chương trình Point to Point: baudrate: 19200, kênh 2, Vietduino ESP32 - Point A & Maixduino ESP32 - Point B.
  - Vietduino ESP32 kết nối Module LDR và Zigbee. Maixduino ESP32 kết nối Module LED và Zigbee
  - Module LDR giao tiếp Analog. Module LED giao tiếp Digital. Zigbee giao tiếp UART, baudrate 19200.
  - a. Truyền dữ liệu thô
  - b. So sánh dữ liệu để bật Module LED

Chương trình Broadcast: baudrate: 19200, kênh 3, Tất cả module chọn broadcast.
  - Vietduino ESP32 kết nối Module LDR và Zigbee. Maixduino ESP32 kết nối Module LED, Module nút nhấn và Zigbee. Arduino kết nối Module DHT11.
  - Module LDR giao tiếp Analog. Module LED và Module nút nhấn giao tiếp Digital. Module DHT11 giao tiếp OneWire. Zigbee giao tiếp UART, baudrate 19200.
  - a. Truyền dữ liệu thô
  - b. Chỉ khi bấm nút, mới nhận dữ liệu DHT11. So sánh dữ liệu để bật Module LED
