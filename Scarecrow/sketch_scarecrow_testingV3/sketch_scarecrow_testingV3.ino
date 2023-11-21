void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  int randomAmountOfLims = random(1, 5);
  
  Serial.print("random amount of lims: ");
  Serial.println(randomAmountOfLims);
  
  chooceRandomLim(randomAmountOfLims);

  while(true) {
    delay(100000);
  }
}

void setRandomLimPos() {
  switch(3) {
    case 1:
      //int randomNumForRL = GiveRandomNum();
      //Serial.print("The random number given to right leg: ");
      //Serial.println(randomNumForRL);
      
      break;
    case 2:
      //int randomNumForRA = GiveRandomNum();
      //Serial.print("The random number given to right arm: ");
      //Serial.println(randomNumForRA);
      break;
    case 3:
      //int randomNumForLL = GiveRandomNum();
      //Serial.print("The random number given to left leg: ");
      //Serial.println(randomNumForLL);
      break;
    case 4:
      //int randomNumForLA = GiveRandomNum();
      //Serial.print("The random number given to left arm: ");
      //Serial.println(randomNumForLA);
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
