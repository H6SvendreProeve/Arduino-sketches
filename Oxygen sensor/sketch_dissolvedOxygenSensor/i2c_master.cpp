/*
 * i2c_master
 * -----------------
 * Denne fil implementer de funtioner fra header 
 * filen i2c_mester.h
 *  i2cMasterSetup
 *  writeI2C
 *  writeNumberI2c
 */

#include "i2c_master.h"

void i2cMasterSetup(){
   Wire.begin();
}

void writeI2C(int address, char* content){
  Wire.beginTransmission(address);
  Wire.write(content);
  Wire.endTransmission();
}

void writeNumberI2c(int address, float number){
   byte buffer[sizeof(float)];
  memcpy(buffer, &number, sizeof(float));
  
  Wire.beginTransmission(address);
  Wire.write(buffer, sizeof(float));
  Wire.endTransmission();
}
