#ifndef RANDOMNUMGENERATOR_H
#define RANDOMNUMGENERATOR_H
#include <Arduino.h>
#include "Helper.h"

void randomNumGenertorSetup();
int* chooceRandomNum(int amountOfNumbers);
int giveRandomNum(int minValue, int maxValue);

#endif
