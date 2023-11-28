#include "I2c_slave.h"

String instructionMessage = ""; 

void i2cSlaveSetup(){
  Wire.begin(i2cSlaveAddress); 
  Wire.onReceive(receiveEvent); 
}

void receiveEvent(int bytes) {
  if (bytes <= 0) {
    Serial.println("No bytes received"); //TODO: move to logger file
  }else {
    String message = "";
    while (Wire.available()) {
      char c = Wire.read();
      message += c;
    }
    instructionMessage = message;
  }

}
