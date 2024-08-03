String command = "";  // Biến toàn cục để lưu chuỗi lệnh nhận được
class splitCommand_2 {
public:
  void setup() {
    Serial.begin(115200);  // Khởi động Serial với tốc độ 9600 bps
    Serial.println(F("Start"));
  }

  void loop() {
    if (Serial.available() > 0) {
      command = Serial.readStringUntil('\n');  // Đọc chuỗi lệnh đến khi gặp ký tự xuống dòng
      // parseCommand(command);
      Serial.println("kxn: " +getValFromIndex("ROBOTRUN", 1));
      Serial.println("kxn: " +getValFromIndex("ROBOTRUN", 2));
      if(getValFromIndex("ROBOTRUN", 3) == "OK"){
        Serial.println(getValFromIndex("ROBOTRUN", 3));
      }
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

    // Tách các giá trị dựa trên khoảng trắng
    int valueIndex = 1;
    while (values.length() > 0) {
      int spaceIndex = values.indexOf(' ');
      String value;
      if (spaceIndex == -1) {
        value = values;  // Nếu không còn khoảng trắng, lấy phần còn lại của chuỗi
        values = "";
      } else {
        value = values.substring(0, spaceIndex);    // Lấy giá trị tiếp theo
        values = values.substring(spaceIndex + 1);  // Cập nhật chuỗi giá trị
      }
      Serial.print("Value");
      Serial.print(valueIndex);
      Serial.print(": ");
      Serial.println(value);
      valueIndex++;
    }
  }

  String getValFromIndex(String keyword, int indexValue) {
    command.trim();                              // Loại bỏ khoảng trắng ở đầu và cuối chuỗi
    int firstSpaceIndex = command.indexOf(' ');  // Tìm vị trí khoảng trắng đầu tiên

    if (firstSpaceIndex == -1) {
      return "Invalid command";
    }

    String cmdKeyword = command.substring(0, firstSpaceIndex);  // Lấy từ khóa
    if (cmdKeyword != keyword) {
      return "Keyword not found";
    }

    String values = command.substring(firstSpaceIndex + 1);  // Lấy giá trị

    // Tách các giá trị dựa trên khoảng trắng
    int valueIndex = 1;
    while (values.length() > 0) {
      int spaceIndex = values.indexOf(' ');
      String value;
      if (spaceIndex == -1) {
        value = values;  // Nếu không còn khoảng trắng, lấy phần còn lại của chuỗi
        values = "";
      } else {
        value = values.substring(0, spaceIndex);    // Lấy giá trị tiếp theo
        values = values.substring(spaceIndex + 1);  // Cập nhật chuỗi giá trị
      }
      if (valueIndex == indexValue) {
        return value;
      }
      valueIndex++;
    }
    return "Index out of range";
  }
};