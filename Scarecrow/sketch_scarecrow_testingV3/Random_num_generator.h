/*
 * Random_num_generator
 * -----------------
 * Denne klasse er til at generaer random tal til rasten af systemet
 * som fx. random tal til servo motererne så de kan bevæge sig tilfæltigt
 */

#ifndef RANDOMNUMGENERATOR_H
#define RANDOMNUMGENERATOR_H
#include <Arduino.h>
#include "Helper.h"

class RandomNumGenerator{
  public: 
    void randomNumGenertorSetup();
    int* chooseRandomNum(int amountOfNumbers);
    int giveRandomNum(int minValue, int maxValue);
    
  private:
    int* setallLims(int* arr, int arrLength);
    int* setSomeLims(int* arr, int arrLength);
    Helper helper;
};

#endif
