#include "Random_num_generator.h"

void randomNumGenertorSetup(){
  randomSeed(analogRead(0));
}

int* chooseRandomNum(int amountOfNumbers) {
  int *tempArr = new int[amountOfNumbers];
  int arrLength = amountOfNumbers;
  Serial.print("tempArr length is: "); //TODO: move to logger file
  Serial.println(arrLength);           //TODO: move to logger file
  
  const int allLims = 4;
  if(arrLength == allLims){
      //for (int i = 0; i < arrLength; ++i) {
      //  tempArr[i] = i + 1;
      //}
      setallLims(tempArr, arrLength);
  } else{
    //for(int i = 0; i < arrLength; i++) {
    //  int randomValue;
    //do{
    //  const int minRandomValue = 1;
    //  const int maxRandomValue = 5;
    //  randomValue = random(minRandomValue, maxRandomValue);
    //}while(doesThisIntArrayContain(randomValue, tempArr, arrLength));
    
    //tempArr[i] = randomValue;
    setSomeLims(tempArr, arrLength);
   }
  }
  return tempArr;
}

int* setallLims(int* arr, int arrLength){
  for (int i = 0; i < arrLength; ++i) {
    arr[i] = i + 1;
  }
}

int* setSomeLims(int* arr, int arrLength){
    for(int i = 0; i < arrLength; i++) {
      int randomValue;
    do{
      const int minRandomValue = 1;
      const int maxRandomValue = 5;
      randomValue = random(minRandomValue, maxRandomValue);
    }while(doesThisIntArrayContain(randomValue, tempArr, arrLength));
    
    tempArr[i] = randomValue;
}

int giveRandomNum(int minValue, int maxValue){
  return random(minValue, maxValue);
}
