#ifndef RANDOMNUMGENERATOR_H
#define RANDOMNUMGENERATOR_H
#include <Arduino.h>
#include "Helper.h"

void randomNumGenertorSetup();
int* chooseRandomNum(int amountOfNumbers);
int* setallLims(int* arr, int arrLength);
int giveRandomNum(int minValue, int maxValue);

#endif
