#include "I2c_slave.h"


String instructionMessage = ""; 

void i2cSlaveSetup(){
  Wire.begin(0x08);             //to I2c_slave.h
  Wire.onReceive(receiveEvent); //to I2c_slave.h
}

///to I2c_slave
void receiveEvent(int bytes) {
  String message = "";
  while (Wire.available()) {
  char c = Wire.read();
  message += c;
 }
 instructionMessage = message;
}
