#ifndef SERVOCONTROLLER_H
#define SERVOCONTROLLER_H
#include <Arduino.h>
#include <Servo.h>

extern Servo servoRightLeg;
extern Servo servoRightArm;
extern Servo servoLeftLeg;
extern Servo servoLeftArm;

void servoControllerSetup();
void writeToServo(Servo servoName, int positionToGoTo);

#endif
