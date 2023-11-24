#include "Servo_controller.h"


Servo servoRightLeg; //to Servo_controller.h
Servo servoRightArm; //to Servo_controller.h
Servo servoLeftLeg;  //to Servo_controller.h
Servo servoLeftArm;  //to Servo_controller.h

///to Servo_controller.h
void setServoPos(int arr[], int arrSize) {
  Serial.println("in method set servos pos");
  for(int i = 0; i < arrSize; i++) {
    Serial.println(arr[i]);
    Serial.println("Commemented setRandomLimPos2 temperary");
    //setRandomLimPos2(arr[i]); //TODO: needs a solution
  }
  delay(1000);
}

void servoControllerSetup(){
  servoLeftLeg.attach(9);   //to Servo_controller.h 
  servoRightLeg.attach(10); //to Servo_controller.h 
  servoRightArm.attach(11); //to Servo_controller.h 
  servoLeftArm.attach(12);  //to Servo_controller.h 
}

///TODO: needs a solution
void writeToServo(Servo servoName, int positionToGoTo){
  Serial.println("Commemented writeToServo temperary");
  //int randomNumForRL = giveRandomNum(15, 155);
  //int randomNumForRA = giveRandomNum(50, 170);
  //int randomNumForLL = giveRandomNum(20, 160);
  //int randomNumForLA = giveRandomNum(10, 150);
  
  //servoRightLeg.write(randomNumForRL); //to Servo_controller.h
  //delay(100);
  //servoRightArm.write(randomNumForRA); //to Servo_controller.h
  //delay(100);
  //servoLeftLeg.write(randomNumForLL); //to Servo_controller.h
  //delay(100);
  //servoLeftArm.write(randomNumForLA); //to Servo_controller.h
  //delay(100);
}
