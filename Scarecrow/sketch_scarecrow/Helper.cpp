/*
 * Helper
 * -----------------
 * Her implementer jeg de funtioner i fra 
 * header filen Helper.h
 */

#include "Helper.h"

void Helper::printArray(int arr[], const int arrSize) {
  const int arrEmpty = 0;
  if (arrSize <= arrEmpty) {
    Serial.println("Invalid array size");
  }else {
    for(int i = 0; i < arrSize; i++) {
      Serial.print(arr[i]);
      Serial.print(" | ");
    }
    Serial.println();
  }

}

bool Helper::doesThisIntArrayContain(int value, int* arr, const int arrSize) {
  if (arrSize <= 0) {
    Serial.println("Invalid array size");
    return false;
  }else {
    for(int i = 0; i < arrSize; i++) {
      if(arr[i] == value) {
        return true;
      } else {
        return false;
      }
   }
 }
}
