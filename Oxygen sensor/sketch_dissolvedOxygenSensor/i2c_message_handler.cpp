/*
 * i2c_message_handler
 * -----------------
 * Denne fil implementer de funtioner fra header 
 * filen i2c_message_handler.h
 *  sendI2CMessagetoSlave
 *  sendI2CMessagetoApiSlave
 */

#include "i2c_message_handler.h"

void sendI2CMessageToSlave(bool isDONotGood, uint16_t i2cAddress){
  if(isDONotGood){
    writeI2C(i2cAddress, "start");
    Serial.println("start is send");
  } else {
    writeI2C(i2cAddress, "stop");
    Serial.println("stop is send");
  }
}

void sendI2CMessageToApiSlave(float dissolvedOxygenMgPerL, uint16_t i2cAddress){
    writeNumberI2c(i2cAddress, dissolvedOxygenMgPerL);
    Serial.println("Dissolvd oxygen mesument is send to api microcontroller slave");
}
