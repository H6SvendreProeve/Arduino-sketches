#include "Helper.h"

void printArray(int arr[], int arrSize) {
  for(int i = 0; i < arrSize; i++) {
    Serial.print(arr[i]);
    Serial.print(" | ");
  }
  Serial.println();
}

bool doesThisIntArrayContain(int value, int* arr, int arrSize) {
  bool isIn = false;

  for(int i = 0; i < arrSize; i++) {
    if(arr[i] == value) {
      isIn = true;
    } 
  }
  
  Serial.println("-----------------------------------");
  Serial.print("Return isIn is: ");
  Serial.println(isIn);
  Serial.println("-----------------------------------");
  return isIn;
}
