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
  Serial.println("i2c test 1");
  Wire.beginTransmission(address);
  Serial.println("i2c test 2");
  Wire.write(content);
  Serial.println("i2c test 3");
  Wire.endTransmission();
  Serial.println("i2c test 4");
}

void writeNumberI2c(int address, float number){
   byte buffer[sizeof(float)];
  memcpy(buffer, &number, sizeof(float));
  
  Wire.beginTransmission(address);
  Wire.write(buffer, sizeof(float));
  Wire.endTransmission();
}
