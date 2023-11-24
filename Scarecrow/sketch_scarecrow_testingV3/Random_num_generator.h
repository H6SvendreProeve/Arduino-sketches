#ifndef RANDOMNUMGENERATOR_H
#define RANDOMNUMGENERATOR_H
#include <Arduino.h>


extern int randomAmountOfLims;


void randomNumGenertorSetup();
///to Random_num_generator.h
void setRandomLimPos2(int caseValue);
///to Random_num_generator.h
void chooceRandomLim(int amountOfLims);
///to Random_num_generator.h
int giveRandomNum(int minValue, int maxValue);
#endif
