#ifndef HELPER_H
#define HELPER_H
#include <Arduino.h>

class Helper {
  public:
    void printArray(int arr[], int arrSize);
    bool doesThisIntArrayContain(int value, int* arr, int arrSize);
};

#endif
