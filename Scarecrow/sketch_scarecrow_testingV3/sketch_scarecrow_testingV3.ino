#include <Servo.h>

Servo servoRightLeg;  
Servo servoRightArm;
Servo servoLeftLeg;  
Servo servoLeftArm;  

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));

  servoRightLeg.attach(9);
  servoRightArm.attach(10);
  servoLeftLeg.attach(11);
  servoLeftArm.attach(12);
}

void loop() {
  int randomAmountOfLims = random(1, 5);
  
  Serial.print("random amount of lims: ");
  Serial.println(randomAmountOfLims);
  
  chooceRandomLim(randomAmountOfLims);

  //while(true) {
    delay(500);
  //}
}


void setRandomLimPos2(int caseValue) {
  if (caseValue == 1) {
    int randomNumForRL = GiveRandomNum();
      Serial.print("The random number given to right leg: ");
      Serial.println(randomNumForRL);

      servoRightLeg.write(randomNumForRL);
  } else if (caseValue == 2) {
          int randomNumForRA = GiveRandomNum();
      Serial.print("The random number given to right arm: ");
      Serial.println(randomNumForRA);
      
      servoRightArm.write(randomNumForRA);
  } else if (caseValue == 3) {
          int randomNumForLL = GiveRandomNum();
      Serial.print("The random number given to left leg: ");
      Serial.println(randomNumForLL);

      servoLeftLeg.write(randomNumForLL);
  } else if (caseValue == 4) {
          int randomNumForLA = GiveRandomNum();
      Serial.print("The random number given to left arm: ");
      Serial.println(randomNumForLA);

      servoLeftArm.write(randomNumForLA);
  }
  delay(500);
}


void setRandomLimPos(int valueToSwitchOn) {
  Serial.println("in method setrandomlimpos");
  Serial.println(valueToSwitchOn);
  switch(valueToSwitchOn) {
    case 1:
      int randomNumForRL = GiveRandomNum();
      Serial.print("The random number given to right leg: ");
      Serial.println(randomNumForRL);

      servoRightLeg.write(randomNumForRL);
      break;
    case 2:
      int randomNumForRA = GiveRandomNum();
      Serial.print("The random number given to right arm: ");
      Serial.println(randomNumForRA);
      
      servoRightArm.write(randomNumForRA);
      break;
    case 3:
      int randomNumForLL = GiveRandomNum();
      Serial.print("The random number given to left leg: ");
      Serial.println(randomNumForLL);

      servoLeftLeg.write(randomNumForLL);
      break;
    case 4:
      int randomNumForLA = GiveRandomNum();
      Serial.print("The random number given to left arm: ");
      Serial.println(randomNumForLA);

      servoLeftArm.write(randomNumForLA);
      break;
  }
}

void chooceRandomLim(int amountOfLims) {
  int *tempArr = new int[amountOfLims];
  //int tempArr[4] = {0, 0, 0, 0};
  int arrLength = amountOfLims;
  Serial.print("tempArr length is: ");
  Serial.println(arrLength);
  
  printArray(tempArr, arrLength);
  
  for(int i = 0; i < amountOfLims; i++) {
   int randomValue;
    do{
      randomValue = random(1,5);
    }while(doesThisIntArrayContain(randomValue, tempArr, arrLength));
    
    //Serial.print("random value: ");
    //Serial.println(randomValue);

    //if(doesThisIntArrayContain(randomValue, tempArr, arrLength) == false) {
    //  Serial.println("TempArr value set");
      tempArr[i] = randomValue;
    //  Serial.println("-----------------------------------");
    //  Serial.print("Random value is: ");
    //  Serial.println(randomValue); 
    //  Serial.print("Random value to tempArr: ");
    //  Serial.println(randomValue);
    //  Serial.println("-----------------------------------");
    //} else {
    //  Serial.println("Value was existing in tempArr");
    //}
  }

  printArray(tempArr, arrLength);
  setServoPos(tempArr, arrLength);
  //setRandomLimPos2(3);
}

bool doesThisIntArrayContain(int value, int* arr, int arrSize) {
  bool isIn = false;

  for(int i = 0; i < arrSize; i++) {
    if(arr[i] == value) {
      isIn = true;
    } 
  }
  
  Serial.println("-----------------------------------");
  Serial.print("Return isIn is: ");
  Serial.println(isIn);
  Serial.println("-----------------------------------");
  return isIn;
}

void printArray(int arr[], int arrSize) {
  for(int i = 0; i < arrSize; i++) {
    Serial.print(arr[i]);
    Serial.print(" | ");
  }
  Serial.println();
}

void setServoPos(int arr[], int arrSize) {
  Serial.println("in method set servos pos");
  for(int i = 0; i < arrSize; i++) {
    Serial.println(arr[i]);
    setRandomLimPos2(arr[i]);
  }
  delay(1000);
}

int GiveRandomNum(){
  return random(180);
}
