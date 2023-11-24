//#include <Servo.h> //to Servo_controller.h
//#include <Wire.h>  //to I2c_slave.h
#include "I2c_slave.h"
#include "Servo_controller.h"
#include "Random_num_generator.h"

//Servo servoRightLeg; //to Servo_controller.h
//Servo servoRightArm; //to Servo_controller.h
//Servo servoLeftLeg;  //to Servo_controller.h
//Servo servoLeftArm;  //to Servo_controller.h

//String instructionMessage; //to I2c_slave.h

void setup() {
  Serial.begin(9600);
  //randomSeed(analogRead(0));    //to Random_num_generator.h
  //Wire.begin(0x08);             //to I2c_slave.h
  //Wire.onReceive(receiveEvent); //to I2c_slave.h

  //servoLeftLeg.attach(9);   //to Servo_controller.h 
  //servoRightLeg.attach(10); //to Servo_controller.h 
  //servoRightArm.attach(11); //to Servo_controller.h 
  //servoLeftArm.attach(12);  //to Servo_controller.h 
}

void loop() {
  Serial.print("I2C message is: ");   //to I2c_slave.h /
  Serial.println(instructionMessage); //to I2c_slave.h /
  if(instructionMessage == "start"){  //to I2c_slave.h /
    //int randomAmountOfLims = random(1, 5); //to Random_num_generator.h
  
    Serial.print("random amount of lims: "); 
    Serial.println(randomAmountOfLims);
  
  chooceRandomLim(randomAmountOfLims); //to Random_num_generator.h /
  }
  //int randomAmountOfLims = random(1, 5);
  
  //Serial.print("random amount of lims: ");
  //Serial.println(randomAmountOfLims);
  
  //chooceRandomLim(randomAmountOfLims);

  //while(true) {
    delay(500);
  //}
}

///to Random_num_generator.h
//void setRandomLimPos2(int caseValue) {
//  if (caseValue == 1) {
    //int randomNumForRL = giveRandomNum(15,155);
      //Serial.print("The random number given to right leg: ");
      //Serial.println(randomNumForRL);

      //servoRightLeg.write(randomNumForRL); //to Servo_controller.h
      //delay(100);
//  } else if (caseValue == 2) {
          //int randomNumForRA = giveRandomNum(50,170);
      //Serial.print("The random number given to right arm: ");
      //Serial.println(randomNumForRA);
      
      //servoRightArm.write(randomNumForRA); //to Servo_controller.h
      //delay(100);
//  } else if (caseValue == 3) {
          //int randomNumForLL = giveRandomNum(20,160);
      //Serial.print("The random number given to left leg: ");
      //Serial.println(randomNumForLL);

      //servoLeftLeg.write(randomNumForLL); //to Servo_controller.h
      //delay(100);
//  } else if (caseValue == 4) {
          //int randomNumForLA = giveRandomNum(10,150);
      //Serial.print("The random number given to left arm: ");
      //Serial.println(randomNumForLA);

      //servoLeftArm.write(randomNumForLA); //to Servo_controller.h
      //delay(100);
//  }
//  delay(1000);
//}


//void setRandomLimPos(int valueToSwitchOn) {
//  Serial.println("in method setrandomlimpos");
//  Serial.println(valueToSwitchOn);
//  switch(valueToSwitchOn) {
//    case 1:
//      int randomNumForRL = GiveRandomNum();
//      Serial.print("The random number given to right leg: ");
//      Serial.println(randomNumForRL);

//      servoRightLeg.write(randomNumForRL);
//      break;
//    case 2:
//      int randomNumForRA = GiveRandomNum();
//      Serial.print("The random number given to right arm: ");
//      Serial.println(randomNumForRA);
      
//      servoRightArm.write(randomNumForRA);
//      break;
//    case 3:
//      int randomNumForLL = GiveRandomNum();
//      Serial.print("The random number given to left leg: ");
//      Serial.println(randomNumForLL);

//      servoLeftLeg.write(randomNumForLL);
//      break;
//    case 4:
//      int randomNumForLA = GiveRandomNum();
//      Serial.print("The random number given to left arm: ");
//      Serial.println(randomNumForLA);

//      servoLeftArm.write(randomNumForLA);
//      break;
//  }
//}

///to Random_num_generator.h
//void chooceRandomLim(int amountOfLims) {
//  int *tempArr = new int[amountOfLims];
  //int tempArr[4] = {0, 0, 0, 0};
//  int arrLength = amountOfLims;
//  Serial.print("tempArr length is: ");
//  Serial.println(arrLength);
  
//  printArray(tempArr, arrLength);
//  int allLims = 4;
//  if(amountOfLims == allLims){
//      for (int i = 0; i < amountOfLims; ++i) {
//        tempArr[i] = i + 1;
//      }
//  } else{
//  for(int i = 0; i < amountOfLims; i++) {
//   int randomValue;
//    do{
//      randomValue = random(1,5);
//    }while(doesThisIntArrayContain(randomValue, tempArr, arrLength));
    
    //Serial.print("random value: ");
    //Serial.println(randomValue);

    //if(doesThisIntArrayContain(randomValue, tempArr, arrLength) == false) {
    //  Serial.println("TempArr value set");
//      tempArr[i] = randomValue;
    //  Serial.println("-----------------------------------");
    //  Serial.print("Random value is: ");
    //  Serial.println(randomValue); 
    //  Serial.print("Random value to tempArr: ");
    //  Serial.println(randomValue);
    //  Serial.println("-----------------------------------");
    //} else {
    //  Serial.println("Value was existing in tempArr");
    //}
//  }
//  }

//  printArray(tempArr, arrLength);
//  setServoPos(tempArr, arrLength);
  //setRandomLimPos2(3);
//}

///to Helper.h
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

///to Helper.h
void printArray(int arr[], int arrSize) {
  for(int i = 0; i < arrSize; i++) {
    Serial.print(arr[i]);
    Serial.print(" | ");
  }
  Serial.println();
}

///to Servo_controller.h
//void setServoPos(int arr[], int arrSize) {
//  Serial.println("in method set servos pos");
//  for(int i = 0; i < arrSize; i++) {
//    Serial.println(arr[i]);
//    setRandomLimPos2(arr[i]);
//  }
//  delay(1000);
//}

///to Random_num_generator.h
//int giveRandomNum(int minValue, int maxValue){
//  return random(minValue, maxValue);
//}

///to I2c_slave
//void receiveEvent(int bytes) {
//  String message = "";
//  while (Wire.available()) {
//  char c = Wire.read();
//  message += c;
// }
// instructionMessage = message;
//}
