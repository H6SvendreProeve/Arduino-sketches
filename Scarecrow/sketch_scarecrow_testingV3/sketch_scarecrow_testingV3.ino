#include <Servo.h>
#include "I2c_slave.h"
#include "Random_num_generator.h"
#include "Helper.h"

Servo servoRightLeg;
Servo servoRightArm; 
Servo servoLeftLeg;  
Servo servoLeftArm;  

RandomNumGenerator ranGenerator;
Helper helper;

void setup() {
  Serial.begin(9600);
  ranGenerator.randomNumGenertorSetup();
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

    int* randomLims = ranGenerator.chooseRandomNum(randomAmountOfLims);
  
    helper.printArray(randomLims, randomAmountOfLims);
    setRandomLimPos(randomLims, randomAmountOfLims);
  
    delete[]randomLims;
  }
  delay(500);
 
}
static void servoControllerSetup(){
  servoLeftLeg.attach(9); 
  servoRightLeg.attach(10); 
  servoRightArm.attach(11);
  servoLeftArm.attach(12);  
}

static void setRandomLimPos(int arr[], const int arrSize) {
  for(int i = 0; i < arrSize; i++) {
  if (arr[i] == 1) {
    setLimPosition("Right leg", servoRightLeg, 15, 155);
  } else if (arr[i] == 2) {
    setLimPosition("Right arm", servoRightArm, 50, 170);
  } else if (arr[i] == 3) {
    setLimPosition("left leg", servoLeftLeg, 20, 160);
  } else if (arr[i] == 4) {
    setLimPosition("left arm", servoLeftArm, 10, 150);

  }
  delay(1000);
  }
}

static void setLimPosition(const char* servoName, Servo servoObj, const int minMovementRange, const int maxMovementRange){
    int randomNum = ranGenerator.giveRandomNum(minMovementRange, maxMovementRange);
    
    Serial.print("The random number given to : ");      //TODO: move to logger file
    Serial.println(servoName);                        //TODO: move to logger file
    
    servoObj.write(randomNum);
    delay(100);
}
