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
  
  //if(instructionMessage == "start"){
    //writeToServo(servoDoor, 0);
    motorUp(servoDoor, 0, 50);
    delay(1000);
    motorUp(servoTiltPlate, 80, 160);
    delay(2000);
    motorDown(servoTiltPlate, 80, 160);
    delay(1000);
    writeToServo(servoDoor, 0);
    
    //motorUp(servoDoor, 0, 50);
    //delay(4000);
    writeToServo(servoDoor, 0);
    //motorDown(servoDoor, 0, 80);
    //delay(4000);
    //motorDown(servoTiltPlate, 80, 160);
    while(true){
      Serial.println("in while");
      delay(1000);
    }
    motorUp(servoDoor, 0, 50);
    delay(4000);
    motorDown(servoDoor, 0, 50);
    motorDown(servoTiltPlate, 80, 160);
  //  cageHasRunOnce = true;
  //}else {
  //  cageHasRunOnce = false;
  //}

  delay(10000000);
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
