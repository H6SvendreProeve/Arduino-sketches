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
  Serial.print("I2C message is: ");
  Serial.println(instructionMessage); 
  if(instructionMessage == "start"){ 
    int randomAmountOfLims = random(1, 5); 

    Serial.print("random amount of lims: "); 
    Serial.println(randomAmountOfLims);

    int* randomLims = chooceRandomNum(randomAmountOfLims);
  
    printArray(randomLims, randomAmountOfLims);
    setRandomLimPos(randomLims, randomAmountOfLims);
  
    delete[]randomLims;
  }
  delay(500);
 
}

void setRandomLimPos(int arr[], int arrSize) {
  for(int i = 0; i < arrSize; i++) {
  if (arr[i] == 1) {
    int randomNumForRL = giveRandomNum(15,155);
    Serial.print("The random number given to right leg: ");
    Serial.println(randomNumForRL);

    servoRightLeg.write(randomNumForRL);
    delay(100);
  } else if (arr[i] == 2) {
    int randomNumForRA = giveRandomNum(50,170);
    Serial.print("The random number given to right arm: ");
    Serial.println(randomNumForRA);
      
    servoRightArm.write(randomNumForRA);
    delay(100);
  } else if (arr[i] == 3) {
    int randomNumForLL = giveRandomNum(20,160);
    Serial.print("The random number given to left leg: ");
    Serial.println(randomNumForLL);

    servoLeftLeg.write(randomNumForLL);
    delay(100);
  } else if (arr[i] == 4) {
    int randomNumForLA = giveRandomNum(10,150);
    Serial.print("The random number given to left arm: ");
    Serial.println(randomNumForLA);

    servoLeftArm.write(randomNumForLA);
    delay(100);
  }
  delay(1000);
  }
}
