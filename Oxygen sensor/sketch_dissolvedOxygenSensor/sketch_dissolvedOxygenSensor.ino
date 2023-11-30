#include "dissolved_oxygen_sensor.h"
#include "display_controller.h"
#include "i2c_message_handler.h"

void setup(){
  Serial.begin(115200);
  displayControllerSetup();
  i2cMasterSetup();
}

void loop(){
  float mgPerLiter = getMgPerLMeasurement();
  Serial.println("mg per liter variable:");
  Serial.println(mgPerLiter);

  writeDissolvedOxygenMeasurementToDisplay(mgPerLiter);
  
  sendI2CMessagetoApiSlave(mgPerLiter, slaveAddressToApiHandler);
  sendI2CMessagetoSlave(mgPerLiter, slaveAddressToScarcrow);
  
  delay(1000);
}


bool isDissolvedOxygenMeasurementGood(int dissolvedOxygenMgPerL){
  int goodDissolvedOxygenValue = 4;

  if(dissolvedOxygenMgPerL < goodDissolvedOxygenValue){
    return true;
  }else {
    return false;
  }
}


void writeDissolvedOxygenMeasurementToDisplay(float measurement){ 
  // Dispaly index X(row): 1, 6, 11 Y(column): 1, 2, 2 Axis
  writeToDisplay(1, 1, "Dissolved oxygen:");
  writeToDisplay(6, 2, String(measurement));
  writeToDisplay(11, 2, "mg/L");
}
