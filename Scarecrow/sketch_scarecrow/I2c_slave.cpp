/*
 * I2c_slave
 * -----------------
 * Her implementer jeg de funtioner i fra 
 * header filen 12c_slave.h
 */

#include "I2c_slave.h"

/*Denne linje er skrevet for at sikre, at man kan aflæse værdien der, 
hvor den skal anvendes. Dette skyldes, at 'receiveEvent()' funktionen 
bliver kaldt af I2C-bussen og ikke et bestemt sted i koden. 
Af denne grund er denne variabel defineret som global.*/
String instructionMessage = ""; 

void i2cSlaveSetup(){
  Wire.begin(i2cSlaveAddress); 
  Wire.onReceive(receiveEvent); 
}

void receiveEvent(int bytes) {
  if (bytes <= 0) {
    Serial.println("No bytes received");
  }else {
    String message = "";
    while (Wire.available()) {
      char c = Wire.read();
      message += c;
    }
    instructionMessage = message;
  }

}
