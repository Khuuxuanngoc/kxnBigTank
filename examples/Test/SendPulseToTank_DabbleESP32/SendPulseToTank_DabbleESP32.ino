#include "bigTankConsole.h"
#include "bigTankDabbleTerminal.h"

bigTankConsole  myTank;
bigTankDabbleTerminal myTermial;

void setup() {
  Serial.begin(115200);
  Serial.println(F("Start"));
  myTank.setup();
  myTermial.setup();

}

void loop() {

  // myTank.checkPC(&Serial);
  myTermial.loop();
  myTank.checkData(myTermial.getDabbleDataString());
}

