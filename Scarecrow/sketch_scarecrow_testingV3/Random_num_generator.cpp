#include "Random_num_generator.h"

void randomNumGenertorSetup(){
  randomSeed(analogRead(0));
}

int* chooceRandomNum(int amountOfNumbers) {
  int *tempArr = new int[amountOfNumbers];
  int arrLength = amountOfNumbers;
  Serial.print("tempArr length is: ");
  Serial.println(arrLength);
  
  Serial.println("Commemented chooceRandomLim temperary");
  int allLims = 4;
  if(amountOfNumbers == allLims){
      for (int i = 0; i < amountOfNumbers; ++i) {
        tempArr[i] = i + 1;
      }
  } else{
    for(int i = 0; i < amountOfNumbers; i++) {
      int randomValue;
    do{
      randomValue = random(1,5);
    }while(doesThisIntArrayContain(randomValue, tempArr, arrLength));
    
    tempArr[i] = randomValue;
   }
  }
  return tempArr;
}

int giveRandomNum(int minValue, int maxValue){
  return random(minValue, maxValue);
}
