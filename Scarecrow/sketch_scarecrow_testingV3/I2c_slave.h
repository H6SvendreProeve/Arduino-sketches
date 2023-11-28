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

#define i2cSlaveAddress 0x08

extern String instructionMessage;

void i2cSlaveSetup();
void receiveEvent(int bytes);

#endif
