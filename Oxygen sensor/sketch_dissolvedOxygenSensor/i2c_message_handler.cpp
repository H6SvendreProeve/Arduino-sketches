#include "i2c_message_handler.h"

void sendI2CMessagetoSlave(bool isDOGood, uint16_t i2cAddress){
  if(isDOGood){
    writeI2C(i2cAddress, "start");
    Serial.println("start is send");
  } else {
    writeI2C(i2cAddress, "stop");
    Serial.println("stop is send");
  }
}

void sendI2CMessagetoApiSlave(float dissolvedOxygenMgPerL, uint16_t i2cAddress){
    writeNumberI2c(i2cAddress, dissolvedOxygenMgPerL);
    Serial.println("Dissolvd oxygen mesument is send to api microcontroller slave");
}
