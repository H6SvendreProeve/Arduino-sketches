#include "Webclient.h"
#include "I2c_slave.h"

void setup() {
  Serial.begin(9600);
  i2cSlaveSetup();
  
  webclientSetup();
  printWiFiStatus();
}

void loop() {
  makePostRequest(receivedFloat);
  delay(10000);
}
