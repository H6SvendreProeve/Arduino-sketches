#include "dissolved_oxygen_sensor.h"
#include "display_controller.h"
#include "i2c_master.h"

void setup(){
  Serial.begin(115200);
  displayControllerSetup();
  i2cMasterSetup();
}

void loop(){
  float mgPerLiter = getMgPerLMeasurement();
  writeDissolvedOxygenMeasurementToDisplay(mgPerLiter);

  sendI2CMessagetoSlave(mgPerLiter, slaveAddressToScarcrow);
  delay(1000);
}

void sendI2CMessagetoSlave(int dissolvedOxygenMgPerL, uint16_t i2cAddress){
  int goodDisolvedOxygenValue = 4;
  
    if(dissolvedOxygenMgPerL < goodDisolvedOxygenValue){
    writeI2C(i2cAddress, "start");
    Serial.println("start is send to scarcrow");
  } else {
    writeI2C(i2cAddress, "stop");
    Serial.println("stop is send to scarcrow");
  }
}

void writeDissolvedOxygenMeasurementToDisplay(float measurement){ 
  writeToDisplay(1, 1, "Dissolved oxygen:");
  writeToDisplay(6, 2, String(measurement));
  writeToDisplay(11, 2, "mg/L");
}
