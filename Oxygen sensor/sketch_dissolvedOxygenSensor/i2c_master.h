#ifndef I2CMASTER_H
#define I2CMASTER_H
#include <Wire.h> 
#include <Arduino.h>

#define slaveAddressToScarcrow 0x08

void i2cMasterSetup();
void writeI2C(int address, char* content);

 #endif
