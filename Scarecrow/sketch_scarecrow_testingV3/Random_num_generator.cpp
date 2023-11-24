#include "Random_num_generator.h"

int randomAmountOfLims = random(1, 5); //to Random_num_generator.h

void randomNumGenertorSetup(){
  randomSeed(analogRead(0));    //to Random_num_generator.h
}




///to Random_num_generator.h
void setRandomLimPos2(int caseValue) {
  if (caseValue == 1) {
    //int randomNumForRL = giveRandomNum(15,155);
      //Serial.print("The random number given to right leg: ");
      //Serial.println(randomNumForRL);

      //servoRightLeg.write(randomNumForRL); //to Servo_controller.h
      //delay(100);
  } else if (caseValue == 2) {
          //int randomNumForRA = giveRandomNum(50,170);
      //Serial.print("The random number given to right arm: ");
      //Serial.println(randomNumForRA);
      
      //servoRightArm.write(randomNumForRA); //to Servo_controller.h
      //delay(100);
  } else if (caseValue == 3) {
          //int randomNumForLL = giveRandomNum(20,160);
      //Serial.print("The random number given to left leg: ");
      //Serial.println(randomNumForLL);

      //servoLeftLeg.write(randomNumForLL); //to Servo_controller.h
      //delay(100);
  } else if (caseValue == 4) {
          //int randomNumForLA = giveRandomNum(10,150);
      //Serial.print("The random number given to left arm: ");
      //Serial.println(randomNumForLA);

      //servoLeftArm.write(randomNumForLA); //to Servo_controller.h
      //delay(100);
  }
  delay(1000);
}



///to Random_num_generator.h
void chooceRandomLim(int amountOfLims) {
  int *tempArr = new int[amountOfLims];
  //int tempArr[4] = {0, 0, 0, 0};
  int arrLength = amountOfLims;
  Serial.print("tempArr length is: ");
  Serial.println(arrLength);
  
  Serial.println("Commemented chooceRandomLim temperary");
  //printArray(tempArr, arrLength); //TODO: find a solution
  int allLims = 4;
  if(amountOfLims == allLims){
      for (int i = 0; i < amountOfLims; ++i) {
        tempArr[i] = i + 1;
      }
  } else{
  for(int i = 0; i < amountOfLims; i++) {
   int randomValue;
    do{
      randomValue = random(1,5);
      Serial.println("Commemented chooceRandomLim temperary");
    }while(/*doesThisIntArrayContain(randomValue, tempArr, arrLength)*//*TODO: find a solution*/ true);
    
    //Serial.print("random value: ");
    //Serial.println(randomValue);

    //if(doesThisIntArrayContain(randomValue, tempArr, arrLength) == false) {
    //  Serial.println("TempArr value set");
      tempArr[i] = randomValue;
    //  Serial.println("-----------------------------------");
    //  Serial.print("Random value is: ");
    //  Serial.println(randomValue); 
    //  Serial.print("Random value to tempArr: ");
    //  Serial.println(randomValue);
    //  Serial.println("-----------------------------------");
    //} else {
    //  Serial.println("Value was existing in tempArr");
    //}
  }
  }
  Serial.println("Commemented chooceRandomLim temperary");
  //printArray(tempArr, arrLength); //TODO: find a solution
  Serial.println("Commemented chooceRandomLim temperary");
  //setServoPos(tempArr, arrLength); //TODO: find a solution
  //setRandomLimPos2(3);
}



///to Random_num_generator.h
int giveRandomNum(int minValue, int maxValue){
  return random(minValue, maxValue);
}
