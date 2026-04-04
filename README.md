Truyền thông giữa Vietduino ESP32, Arduino Uno R3 SMD và Maixduino (K210) thông qua mạng Zigbee. Các module tham gia: Module DHT11, Module LDR, MOdule LCD I2C, cảm biến siêu âm SR04, ...

Vietduino ESP32 giao tiếp TTL 3v3. Uno giao tiếp TTL 5v. Zigbee CC2530 V1 giao tiếp TTL 3v3/5v (Tùy VCC). Vietduino ESP32, Arduino dùng Arduino IDE. K210 dùng platformIO IDE.

Zigbee giao tiếp UART với các vi điều khiển. Chọn baudrate: 19200, số kênh tùy theo chương trình mẫu, chế độ truyền tùy theo chương trình mẫu.

Tham khảo chương trình SoftwareSerialExample: Nếu Serial rảnh (sau khi đọc xong dữ liệu nhập vào ô nhập liệu), mySerial sẽ viết nội dung mà Serial "đã" đọc được.
