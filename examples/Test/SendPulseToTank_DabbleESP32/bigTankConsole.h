#ifndef bigTankConsole__H
#define bigTankConsole__H
#include "pinVar.h"
#include <Servo.h>

class bigTankConsole {
public:
  int val;        // variable to read the value from the analog pin
  Servo myservo;  // create servo object to control a servo
  Servo myservo2;

  void setup() {
    myservo.attach(PIN_CH_1);  // attaches the servo on pin 9 to the servo object
    myservo2.attach(PIN_CH_2);  // attaches the servo on pin 9 to the servo object
  }

  void checkPC(Stream* inSer) {
    if (inSer->available()) {
      String tempData = inSer->readStringUntil('\n');
      this->checkData(tempData);
    }
  }

  void checkData(String paData) {
    if(paData == "") return;
    paData.toUpperCase();
    String valueData = paData.substring(1);
    if (paData[0] == 'A') {
      // inSer->println("A value:" + valueData);
      val = valueData.toInt();
      this->myservo.writeMicroseconds(val);
    }

    else if (paData[0] == 'B') {
      // inSer->println("A value:" + valueData);
      val = valueData.toInt();
      this->myservo2.writeMicroseconds(val);
    }
  }
};
#endif