#ifndef I2CMESSAGEHANDLER_H
#define I2CMESSAGEHANDLER_H
#include <Arduino.h>
#include "i2c_master.h"

void sendI2CMessagetoSlave(bool isDOGood, uint16_t i2cAddress);
void sendI2CMessagetoApiSlave(float dissolvedOxygenMgPerL, uint16_t i2cAddress);

#endif