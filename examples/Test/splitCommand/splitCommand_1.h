#include "Arduino.h"

class splitCommand_1 {
public:
  void setup() {
    Serial.begin(115200);  // Khởi động Serial với tốc độ 9600 bps
  }

  void loop() {
    if (Serial.available() > 0) {
      String command = Serial.readStringUntil('\n');  // Đọc chuỗi lệnh đến khi gặp ký tự xuống dòng
      parseCommand(command);
    }
  }

  void parseCommand(String command) {
    command.trim();                              // Loại bỏ khoảng trắng ở đầu và cuối chuỗi
    int firstSpaceIndex = command.indexOf(' ');  // Tìm vị trí khoảng trắng đầu tiên

    if (firstSpaceIndex == -1) {
      Serial.println("Invalid command");
      return;
    }

    String keyword = command.substring(0, firstSpaceIndex);  // Lấy từ khóa
    String values = command.substring(firstSpaceIndex + 1);  // Lấy giá trị

    Serial.print("Keyword: ");
    Serial.println(keyword);

    if (keyword == "ROBOTRUN") {
      int secondSpaceIndex = values.indexOf(' ');  // Tìm vị trí khoảng trắng thứ hai
      if (secondSpaceIndex == -1) {
        Serial.println("Invalid ROBOTRUN command");
        return;
      }
      String value1 = values.substring(0, secondSpaceIndex);   // Lấy giá trị đầu tiên
      String value2 = values.substring(secondSpaceIndex + 1);  // Lấy giá trị thứ hai
      Serial.print("Value1: ");
      Serial.println(value1);
      Serial.print("Value2: ");
      Serial.println(value2);
    } else {
      Serial.print("Value: ");
      Serial.println(values);
    }
  }
};
