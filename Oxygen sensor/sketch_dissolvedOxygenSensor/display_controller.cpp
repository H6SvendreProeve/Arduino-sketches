/*
 * dissolved_oxygen_sensor
 * -----------------
 * Denne fil implementerer funktionerne og et object af displayed 
 * filen display_controller.h
 * Objecter:
 *  lcd
 * funtioner:
 *  displayControllerSetup
 *  writeToDisplay
 */


#include "display_controller.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

void displayControllerSetup(){
  Serial.println("test display 1");
  lcd.init();
  Serial.println("test display 2");
  lcd.backlight();
  Serial.println("test display 3");
}

  void writeToDisplay(int rowIndex, int columIndex, String text){
  // lcd.setCursor(1,0); | lcd.setCursor(row index, colum index) 
  lcd.setCursor(rowIndex,columIndex);
  lcd.print(text);
}
