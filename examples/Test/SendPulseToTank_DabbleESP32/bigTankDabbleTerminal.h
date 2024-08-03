#ifndef bigTankDabbleTerminal__H
#define bigTankDabbleTerminal__H

#define CUSTOM_SETTINGS
#define INCLUDE_TERMINAL_MODULE
#include <DabbleESP32.h>

class bigTankDabbleTerminal {
public:
  String Serialdata = "";

  String dabbleData = "";
  bool dataflag = 0;
  void setup() {
    // Serial.begin(115200);     // make sure your Serial Monitor is also set at this baud rate.
    Dabble.begin("BigTank");  //set bluetooth name of your device
  }

  void loop() {

    Dabble.processInput();  //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.
    while (Serial.available() != 0) {
      Serialdata = String(Serialdata + char(Serial.read()));
      dataflag = 1;
    }
    if (dataflag == 1) {
      Terminal.print(Serialdata);
      Serialdata = "";
      dataflag = 0;
    }
    if (Terminal.available() != 0) {
      this->dabbleData = "";
      while (Terminal.available() != 0) {
        // Serial.write(Terminal.read());
        this->dabbleData += Terminal.read();
      }
      Serial.print(this->dabbleData);
      Serial.println();
    }
  }

  void setDabbleDataString(String paSring) {
    this->dabbleData = paSring;
  }

  String getDabbleDataString() {
    String tempString = this->dabbleData;
    this->dabbleData = "";
    return tempString;
  }
};
#endif