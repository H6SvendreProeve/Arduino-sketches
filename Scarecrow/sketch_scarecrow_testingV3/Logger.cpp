/*
 * Logger
 * -----------------
 * Her implementer jeg de funtioner i klassen Logger
 * public:
   * printArrLength
   * printNoBytes
   * printInvalidArrSize
   * printRandomNumber
 */

#include "Logger.h"

  void Logger::printArrLength(int arrLength){
    Serial.print("Array length is: ");
    Serial.println(arrLength);
  }
  
  void Logger::printNoBytes(){
    Serial.println("No bytes received");
  }
  
  void Logger::printInvalidArrSize(){
    Serial.println("Invalid array size");
  }
  

   
