/*
 * dissolved_oxygen_sensor
 * -----------------
 * Denne fil håndterer forbindelsen mellem 
 * sensor og microcontrolleren og 
 * beregner mg per liter
 * Koden i denne fil (dissolved_oxygen_sensor.h) og 
 * i dissolved_oxygen_sensor.cpp er taget fra 
 * DF-Robots dokumentation om denne 
 * analoge dissolved oxygen sensor.
 * Link til DF-Robots dokmention: 
 * https://wiki.dfrobot.com/Gravity__Analog_Dissolved_Oxygen_Sensor_SKU_SEN0237
 */

#ifndef DISSOLVEDOXYGENSENSOR_H
#define DISSOLVEDOXYGENSENSOR_H
#include <Arduino.h>

#define DO_PIN A1    // Input pin
#define VREF 5000    //Voltage Reference (mv)
#define ADC_RES 1024 //ADC Resolution

//calibration temperture
#define READ_TEMP (25) //℃
#define CAL1_V (1206) //(mv) skift denne værdi skal ud med voltage(mv) fra kalibrering 
#define CAL1_T (25)   //℃

#define DO_TABLE_SIZE 41

extern uint8_t Temperaturet;
extern uint16_t ADC_Raw;
extern uint16_t ADC_Voltage;
extern uint16_t DO;
extern const uint16_t DO_Table[DO_TABLE_SIZE];

int16_t readDO(uint32_t voltage_mv, uint8_t temperature_c);
float getMgPerLMeasurement();

#endif
