/*
 * Random_num_generator
 * -----------------
 * Her implementer jeg de funtioner i klassen RandomNumGenerator
 * public:
   * randomNumGenertorSetup
   * chooseRandomNum
   * giveRandomNum
 * private:
   * setallLims
   * setSomeLims
 */

#include "Random_num_generator.h"

void RandomNumGenerator::randomNumGenertorSetup(){
  /*Denne linje bruges almindeligvis til at "seed" generatoren 
  af tilfældige tal med en værdi baseret på 
  aflæsningen fra en analog pin.*/
  randomSeed(analogRead(0));
}


int* RandomNumGenerator::chooseRandomNum(int amountOfNumbers) {
  int *tempArr = new int[amountOfNumbers];
  int arrLength = amountOfNumbers;
  Serial.print("Array length is: ");
  Serial.println(arrLength);

  const int allLims = 4;
  if(arrLength == allLims){
    setallLims(tempArr, arrLength);
  } else{
    setSomeLims(tempArr, arrLength);
  }
  
  return tempArr;
}


int* RandomNumGenerator::setallLims(int* arr, int arrLength){
  for (int i = 0; i < arrLength; ++i) {
    arr[i] = i + 1;
  }
}


int* RandomNumGenerator::setSomeLims(int* arr, int arrLength){
  for(int i = 0; i < arrLength; i++) {
    int randomValue;
    do{
      const int minRandomValue = 1;
      const int maxRandomValue = 5;
      randomValue = random(minRandomValue, maxRandomValue);
    }while(helper.doesThisIntArrayContain(randomValue, arr, arrLength));
    
    arr[i] = randomValue;
  }
}


int RandomNumGenerator::giveRandomNum(int minValue, int maxValue){
  return random(minValue, maxValue);
}
