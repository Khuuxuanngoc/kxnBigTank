#include <Servo.h>

Servo myservo;  // create servo object to control a servo

// int potpin = A0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

void setup() {
  myservo.attach(14);  // attaches the servo on pin 9 to the servo object
  Serial.begin(115200);
  Serial.println(F("Start"));
}

void loop() {
//   val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
//   val = map(val, 0, 1023, 0, 180);     // scale it for use with the servo (value between 0 and 180)
  // myservo.write(val);                  // sets the servo position according to the scaled value
//   delay(15);                           // waits for the servo to get there

  checkPC(&Serial);
}

void checkPC(Stream * inSer){
    if(inSer->available()){
        String tempData = inSer->readStringUntil('\n');
        String valueData= tempData.substring(1);
        if(tempData[0] == 'A'){
            inSer->println("A value:" + valueData);
            val = valueData.toInt();
            myservo.writeMicroseconds(val);
        }
    }
}