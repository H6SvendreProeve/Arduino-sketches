/*
 * i2c_message_handler
 * -----------------
 * Denne fil er til at generere beskeder, som bliver sendt via I2C-protokollen.
 */

#ifndef I2CMESSAGEHANDLER_H
#define I2CMESSAGEHANDLER_H
#include <Arduino.h>
#include "i2c_master.h"

void sendI2CMessageToSlave(bool isDONotGood, uint16_t i2cAddress);
void sendI2CMessageToApiSlave(float dissolvedOxygenMgPerL, uint16_t i2cAddress);

#endif
