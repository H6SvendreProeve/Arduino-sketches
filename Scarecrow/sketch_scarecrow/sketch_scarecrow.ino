#include <Servo.h>
#include <Wire.h>

Servo servoRightLeg;  
//Servo servoRightArm;
//Servo servoLeftLeg;  
//Servo servoLeftArm;  


String instructionMessage;

void setup() {
  Serial.begin(9600);
  Wire.begin(0x08);
  Wire.onReceive(receiveEvent);
  
  servoRightLeg.attach(9);
  //servoRightArm.attach(10);
  //servoLeftLeg.attach(11);
  //servoLeftArm.attach(12);

}

void loop() {
  Serial.print("instructionMessage: ");
  Serial.println(instructionMessage);
  
  if(instructionMessage == "start"){
    int randomNumForRL = GiveRandomNum();
    int randomNumForRA = GiveRandomNum();
    int randomNumForLL = GiveRandomNum();
    int randomNumForLA = GiveRandomNum();

    Serial.print("The random number given to right leg: ");
    Serial.println(randomNumForRL);
    Serial.print("The random number given to right arm: ");
    Serial.println(randomNumForRA);
    Serial.print("The random number given to left leg: ");
    Serial.println(randomNumForLL);
    Serial.print("The random number given to left arm: ");
    Serial.println(randomNumForLA);
    
    servoRightLeg.write(180);
    //servoRightArm.write(randomNumForRA);    
    //servoLeftLeg.write(70);
    //delay(2000);
    //servoLeftLeg.write(0);
    //servoLeftArm.write(randomNumForLA);
  }
    delay(1000);

}

int GiveRandomNum(){
  return random(180);
}

void receiveEvent(int bytes) {
  String message = "";
  while (Wire.available()) {
  char c = Wire.read();
  message += c;
 }
 instructionMessage = message;
}
