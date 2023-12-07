#include <Servo.h>
#include "I2c_slave.h"

Servo servoTiltPlate;  
Servo servoDoor;
bool cageHasRunOnce = false;

void setup() {
  Serial.begin(9600);
  servoTiltPlate.attach(9);
  servoDoor.attach(8);

  
  i2cSlaveSetup();
  
}

void loop() {
  Serial.print("instructionMessage: ");
  Serial.println(instructionMessage);
  
  if(instructionMessage == "start"){
    motorUp(servoDoor, 0, 50);
    delay(1000);
    motorUp(servoTiltPlate, 80, 160);
    delay(2000);
    motorDown(servoTiltPlate, 80, 160);
    delay(1000);

    motorDown(servoDoor, 0, 80);
    delay(1000);
   cageHasRunOnce = true;
  }else {
   cageHasRunOnce = false;
  }

}


void motorUp(Servo servoMotor, int lowestPoint, int highestPoint){
  for(int i = lowestPoint; i < highestPoint; i++){
    writeToServo(servoMotor, i);
  }
}


void motorDown(Servo servoMotor, int lowestPoint, int highestPoint){
  for(int i = highestPoint; i > lowestPoint; i--){
    writeToServo(servoMotor, i);
  }
}


void writeToServo(Servo servoMotor, int postion){
  Serial.println(postion);
  servoMotor.write(postion);
  delay(50);
}
