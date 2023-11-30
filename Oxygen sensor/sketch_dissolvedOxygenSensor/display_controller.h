/*
 * display_controller
 * -----------------
 * Denne fil håndterer forbindelsen mellem 
 * lcd 20x4 display og microcontrolleren
 */
 
#ifndef DISPLAYCONTRLLER_H
#define DISPLAYCONTRLLER_H
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>

extern LiquidCrystal_I2C lcd;

void displayControllerSetup();
void writeToDisplay(int rowIndex, int columIndex, String text);

#endif
