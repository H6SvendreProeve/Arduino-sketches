#ifndef I2CSLAVE_H
#define I2CSLAVE_H
#include <Arduino.h>
#include <Wire.h>  //to I2c_slave.h

extern String instructionMessage; //to I2c_slave.h

void i2cSlaveSetup();
///to I2c_slave
void receiveEvent(int bytes);

#endif
