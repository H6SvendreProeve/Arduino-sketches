#include <Servo.h>
#include <Wire.h>

Servo servoTiltPlate;  
Servo servoDoor;

String instructionMessage;

void setup() {
  Serial.begin(9600);
  Wire.begin(0x07);
  Wire.onReceive(receiveEvent);
  
  servoTiltPlate.attach(9);
  servoDoor.attach(8);


}

void loop() {
  //Serial.print("instructionMessage: ");
  //Serial.println(instructionMessage);
  
  //if(instructionMessage == "start"){
    //Serial.print("The random number given to right leg: ");
    //Serial.println(randomNumForRL);
    
    //Serial.print("The random number given to right arm: ");
    //Serial.println(randomNumForRA);
    //Serial.print("The random number given to left leg: ");
    //Serial.println(randomNumForLL);
    //Serial.print("The random number given to left arm: ");
    //Serial.println(randomNumForLA);
    
    //Serial.println("0");
    //servoDoor.write(0);
    //delay(2000);
    //Serial.println("60");
    //servoDoor.write(60);
    //Serial.println("testing");

    for(int i = 0; i < 50; i++){
      Serial.println(i);
      servoDoor.write(i);
      delay(15);
    }
    for(int i = 50; i > 0; i--){
      Serial.println(i);
      servoDoor.write(i);
      delay(15);
    }
    
    //for(int i = 80; i < 159; i++){
    //  Serial.println(i);
    //  servoTiltPlate.write(i);
    //  delay(15);
    //}
    //for(int i = 160; i > 80; i--){
    //  Serial.println(i);
    //  servoTiltPlate.write(i);
    //  delay(50);
    //}
    //servoRightArm.write(randomNumForRA);    
    //servoLeftLeg.write(70);
    //delay(2000);
    //servoLeftLeg.write(0);
    //servoLeftArm.write(randomNumForLA);
  //}
    delay(2000);

}

void receiveEvent(int bytes) {
  String message = "";
  while (Wire.available()) {
  char c = Wire.read();
  message += c;
 }
 instructionMessage = message;
}
