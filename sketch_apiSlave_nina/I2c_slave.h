/*
 * I2c_slave
 * -----------------
 * Denne fil er til at modtage 
 * beskeder over I2C.
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
