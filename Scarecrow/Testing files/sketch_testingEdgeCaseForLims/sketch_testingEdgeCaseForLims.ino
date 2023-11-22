#include <Servo.h>

Servo servoRightLeg;  
Servo servoRightArm;
Servo servoLeftLeg;  
Servo servoLeftArm;  

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));

  servoLeftLeg.attach(9);
  servoRightLeg.attach(10);
  servoRightArm.attach(11);
  servoLeftArm.attach(12);
}

void loop() {

    //Serial.println("Servo thats run is servo LA");
    //Serial.println("Postion: 10");
    //servoLeftArm.write(10);
    //servoLeftArm.write(10);
    //delay(5000);
    //Serial.println("Postion: 150");
    //servoLeftArm.write(150);
    //delay(5000);
    int ranLA = giveRandomNum(10, 150);
    int ranRA = giveRandomNum(50, 170);
    int ranRL = giveRandomNum(15, 155);
    int ranLL = giveRandomNum(20, 160);

    Serial.print("ranLA: ");
    Serial.println(ranLA);
    servoLeftArm.write(ranLA);
    delay(1000);
    Serial.print("ranRA: ");
    Serial.println(ranRA);
    servoRightArm.write(ranRA);
    delay(1000);
    Serial.print("ranRL: ");
    Serial.println(ranRL);
    servoRightLeg.write(ranRL);
    delay(1000);
    Serial.print("ranLL: ");
    Serial.println(ranLL);
    servoLeftLeg.write(ranLL);
    delay(1000);

    
    //delay(random(1000));
}

int giveRandomNum(int min, int max){
  return random(min, max);
}
