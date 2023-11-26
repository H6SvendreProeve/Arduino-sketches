#include "i2c_master.h"

void i2cMasterSetup(){
   Wire.begin();
}

void writeI2C(int address, char* content){
  Wire.beginTransmission(address);
  Wire.write(content);
  Wire.endTransmission();
}
