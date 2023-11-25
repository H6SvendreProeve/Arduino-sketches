#include "Servo_controller.h"

Servo servoRightLeg; 
Servo servoRightArm; 
Servo servoLeftLeg;  
Servo servoLeftArm;  



void servoControllerSetup(){
  servoLeftLeg.attach(9); 
  servoRightLeg.attach(10); 
  servoRightArm.attach(11);
  servoLeftArm.attach(12);  
}

void writeToServo(Servo servoName, int positionToGoTo){
  servoName.write(positionToGoTo);
}
