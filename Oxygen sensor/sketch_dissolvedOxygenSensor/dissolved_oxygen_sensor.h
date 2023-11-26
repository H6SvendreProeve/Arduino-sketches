#ifndef DISSOLVEDOXYGENSENSOR_H
#define DISSOLVEDOXYGENSENSOR_H
#include <Arduino.h>

#define DO_PIN A1
#define VREF 5000    //Voltage Reference (mv)
#define ADC_RES 1024 //ADC Resolution

//#define TWO_POINT_CALIBRATION 0

//Single-point calibration Mode=0
#define TWO_POINT_CALIBRATION 0

//calibration temperture
#define READ_TEMP (25) //℃


//Single point calibration needs to be filled CAL1_V and CAL1_T
#define CAL1_V (1206) //(mv) denne værdi skal ud med voltage(mv) fra kalibrering 
#define CAL1_T (25)   //℃

#define DO_TABLE_SIZE 41

extern uint8_t Temperaturet;
extern uint16_t ADC_Raw;
extern uint16_t ADC_Voltage;
extern uint16_t DO;

// dette er et "temperature based oxygen calibration table"
extern const uint16_t DO_Table[DO_TABLE_SIZE];



int16_t readDO(uint32_t voltage_mv, uint8_t temperature_c);

float getMgPerLMeasurement();

#endif
