/*
 * I2c_slave
 * -----------------
 * Denne file er indeholder i2c håndtergen
 * så man kan til gå det 
 */

#ifndef I2CSLAVE_H
#define I2CSLAVE_H
#include <Arduino.h>
#include <Wire.h> 

#define i2cSlaveAddress 0x09

extern float receivedFloat;

void i2cSlaveSetup();
void receiveEvent(int bytes);

#endif
