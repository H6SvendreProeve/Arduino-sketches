#ifndef I2CMASTER_H
#define I2CMASTER_H
#include <Wire.h> 
#include <Arduino.h>

#define slaveAddressToScarcrow 0x08
#define slaveAddressToApiHandler 0x09

void i2cMasterSetup();
void writeI2C(int address, char* content);
void writeNumberI2c(int address, float number);

 #endif
