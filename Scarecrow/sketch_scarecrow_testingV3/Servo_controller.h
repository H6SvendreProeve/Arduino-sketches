#ifndef SERVOCONTROLLER_H
#define SERVOCONTROLLER_H
#include <Arduino.h>
#include <Servo.h> //to Servo_controller.h

extern Servo servoRightLeg;
extern Servo servoRightArm;
extern Servo servoLeftLeg;
extern Servo servoLeftArm;




void servoControllerSetup();
///to Servo_controller.h
void setServoPos(int arr[], int arrSize);
void writeToServo(Servo servoName, int positionToGoTo);

#endif
