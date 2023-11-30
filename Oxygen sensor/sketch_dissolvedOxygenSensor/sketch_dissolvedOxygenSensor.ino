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


//void sendI2CMessagetoSlave(bool isDOGood, uint16_t i2cAddress){
//  if(isDOGood){
//    writeI2C(i2cAddress, "start");
//    Serial.println("start is send");
//  } else {
//    writeI2C(i2cAddress, "stop");
//    Serial.println("stop is send");
//  }
//}


bool isDissolvedOxygenMeasurementGood(int dissolvedOxygenMgPerL){
  int goodDissolvedOxygenValue = 4;

  if(dissolvedOxygenMgPerL < goodDissolvedOxygenValue){
    return true;
  }else {
    return false;
  }
}


//void sendI2CMessagetoApiSlave(float dissolvedOxygenMgPerL, uint16_t i2cAddress){
//    writeNumberI2c(i2cAddress, dissolvedOxygenMgPerL);
//    Serial.println("Dissolvd oxygen mesument is send to api microcontroller slave");
//}


void writeDissolvedOxygenMeasurementToDisplay(float measurement){ 
  writeToDisplay(1, 1, "Dissolved oxygen:");
  writeToDisplay(6, 2, String(measurement));
  writeToDisplay(11, 2, "mg/L");
}
