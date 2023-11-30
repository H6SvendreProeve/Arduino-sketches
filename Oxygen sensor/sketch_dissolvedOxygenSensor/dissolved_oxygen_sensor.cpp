/*
 * dissolved_oxygen_sensor
 * -----------------
 * Denne fil implementerer funktionerne og globale variabler fra header. 
 * filen dissolved_oxygen_sensor.h
 * globale variabler:
 *  Temperaturet
 *  ADC_Raw
 *  ADC_Voltage
 *  DO
 * funtioner:
 *  readDO
 *  getMgPerLMeasurement
 */

#include "dissolved_oxygen_sensor.h"

uint8_t Temperaturet;
uint16_t ADC_Raw;
uint16_t ADC_Voltage;
uint16_t DO;

// Denne er et "temperature based oxygen calibration table"
const uint16_t DO_Table[DO_TABLE_SIZE] = {
    14460, 14220, 13820, 13440, 13090, 12740, 12420, 12110, 11810, 11530,
    11260, 11010, 10770, 10530, 10300, 10080, 9860, 9660, 9460, 9270,
    9080, 8900, 8730, 8570, 8410, 8250, 8110, 7960, 7820, 7690,
    7560, 7430, 7300, 7180, 7070, 6950, 6840, 6730, 6630, 6530, 6410};


int16_t readDO(uint32_t voltage_mv, uint8_t temperature_c)
{
  // 35 er defult tal man fra fabrikanten side siger at det er man bruger som udgangs puknkt når bruger en single point kalibrering
  uint16_t V_saturation = (uint32_t)CAL1_V + (uint32_t)35 * temperature_c - (uint32_t)CAL1_T * 35;
  return (voltage_mv * DO_Table[temperature_c] / V_saturation);
}

float getMgPerLMeasurement(){
  Temperaturet = (uint8_t)READ_TEMP;
  ADC_Raw = analogRead(DO_PIN);
  ADC_Voltage = uint32_t(VREF) * ADC_Raw / ADC_RES;

  Serial.println("Dissolved oxygen:");
  // for at få mg/l skal tage DO outputtet (microgram)/ 1000 så får man mg/l
  float mgPerLiter = static_cast<float>(readDO(ADC_Voltage, Temperaturet))/1000;
  Serial.print(mgPerLiter);
  Serial.println(" mg/l");
  
  return mgPerLiter;
}
