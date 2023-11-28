#include "I2c_slave.h"
#include "Servo_controller.h"
#include "Random_num_generator.h"
#include "Helper.h"

//maybe create in this class
//Servo servoRightLeg;
//Servo servoRightArm; 
//Servo servoLeftLeg;  
//Servo servoLeftArm;  

void setup() {
  Serial.begin(9600);
  randomNumGenertorSetup();
  i2cSlaveSetup();
  servoControllerSetup();

}

void loop() {
  Serial.print("I2C message is: ");   //TODO: move to logger file
  Serial.println(instructionMessage); //TODO: move to logger file
  
  if(instructionMessage == "start"){ 
    const int minRandomValue = 1;
    const int maxRandomValue = 5;
    int randomAmountOfLims = random(minRandomValue, maxRandomValue); 

    Serial.print("random amount of lims: ");
    Serial.println(randomAmountOfLims);

    int* randomLims = chooseRandomNum(randomAmountOfLims);
  
    printArray(randomLims, randomAmountOfLims);
    setRandomLimPos(randomLims, randomAmountOfLims);
  
    delete[]randomLims;
  }
  delay(500);
 
}

static void setRandomLimPos(int arr[], const int arrSize) {
  for(int i = 0; i < arrSize; i++) {
  if (arr[i] == 1) {
    setLimPosition("Right leg", servoRightLeg, 15, 155);
    //int randomNumForRL = giveRandomNum(15,155);
    //Serial.print("The random number given to right leg: "); //TODO: move to logger file
    //Serial.println(randomNumForRL);                         //TODO: move to logger file

    //servoRightLeg.write(randomNumForRL);
    //delay(100);
  } else if (arr[i] == 2) {
    setLimPosition("Right arm", servoRightArm, 50, 170);
    //int randomNumForRA = giveRandomNum(50,170);
    //Serial.print("The random number given to right arm: "); //TODO: move to logger file
    //Serial.println(randomNumForRA);                         //TODO: move to logger file
      
    //servoRightArm.write(randomNumForRA);
    //delay(100);
  } else if (arr[i] == 3) {
    setLimPosition("left leg", servoLeftLeg, 20, 160);
    //int randomNumForLL = giveRandomNum(20,160);
    //Serial.print("The random number given to left leg: "); //TODO: move to logger file
    //Serial.println(randomNumForLL);                        //TODO: move to logger file

    //servoLeftLeg.write(randomNumForLL);
    //delay(100);
  } else if (arr[i] == 4) {
    setLimPosition("left arm", servoLeftArm, 10, 150);
    //int randomNumForLA = giveRandomNum(10,150);
    //Serial.print("The random number given to left arm: ");  //TODO: move to logger file
    //Serial.println(randomNumForLA);                         //TODO: move to logger file

    //servoLeftArm.write(randomNumForLA);
    //delay(100);
  }
  delay(1000);
  }
}

static void setLimPosition(const char* servoName, Servo servoObj, const int minMovementRange, const int maxMovementRange){
    int randomNum = giveRandomNum(minMovementRange, maxMovementRange);
    
    Serial.print("The random number given to : ");      //TODO: move to logger file
    Serial.println(servoName);                        //TODO: move to logger file
    
    servoObj.write(randomNum);
    delay(100);
}
