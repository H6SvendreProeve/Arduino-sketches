/*
 * I2c_slave
 * -----------------
 * Her implementer jeg de funtioner i fra 
 * header filen 12c_slave.h
 */

#include "I2c_slave.h"

/*Denne linje er skrevet for at sikre, at man kan aflæse værdien der, 
hvor den skal anvendes. Dette skyldes, at "receiveEvent()" funktionen 
bliver kaldt af I2C-bussen og ikke et bestemt sted i koden. 
Af denne grund er denne variabel defineret som global.*/
float receivedFloat; 


void i2cSlaveSetup(){
  Wire.begin(i2cSlaveAddress); 
  Wire.onReceive(receiveEvent); 
}


void receiveEvent(int bytes) {
  if (bytes <= 0) {
    Serial.println("No bytes received");
  }else {
    int dataSize = Wire.available();
    byte buffer[dataSize];

    for (int i = 0; i < dataSize; i++) {
      buffer[i] = Wire.read();
    }

    // Rekonstruer float fra de modtagne bytes
    memcpy(&receivedFloat, buffer, sizeof(float));
    Serial.println("i2c output:");
    Serial.println(String(receivedFloat));
  }
}
