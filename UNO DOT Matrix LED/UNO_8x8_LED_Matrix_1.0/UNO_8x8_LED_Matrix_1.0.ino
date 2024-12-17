//File: MatrixGame.ino
//Version: 1.0
//Release Date: 2012/02/10
//Author: Joe McManus josephmc@cmu.edu
//Purpose: Use and Arduino Nano to drive an 8x8 LED array to play a game


//Define Columns
int col[] = {0,1,2,3,4,5,6,7} ; // pins for columns
int row[] = {8,9,10,11,12,13,14,15}; //pins for rows  

//Define Button Inputs
#define rightButton 16
#define upButton 17
#define leftButton 18
#define downButton 19 
#define pushButton 20 //This has to be read as analog since it is A6

//Hold User Locations. 
int userRow = 0 ;  
int userCol = 0 ; 
int minRow;

//Hold targetLocation
int targetRow = 7;
int targetCol = 7 ;
int targetCount =0;
int loopCount =0;
int targetInterval; 

//Hold bomb Location
int bombRow; 
int bombCol;
int gameRound;
int animationWait=2;
int gameaWait=20;

void setup() {
  //Set All the matrix pins to output
  for (int i=0; i <= 7; i++) { 
    pinMode(row[i], OUTPUT); 
    pinMode(col[i], OUTPUT);
  }
  
  //Set all the joystick pins to input
  pinMode(rightButton, INPUT); 
  pinMode(leftButton, INPUT);
  pinMode(upButton, INPUT);
  pinMode(downButton, INPUT);
  pinMode(pushButton, INPUT);


  //Test the matrix
  matrixTest(); 
 
  //Turn everything off
  allLeds(0);
  //Set the game defaults
  gameDefaults(); 
}

void gameDefaults() {
  drawAirplane(); 
  allLeds(0);
  userRow=0; 
  userCol=0 ;
  targetRow=7;
  targetCol=7;
  targetCount=0;
  loopCount=0;
  bombRow=NULL; 
  bombCol=NULL;
  gameRound=1; 
  targetInterval=4;
  minRow=6;
  printRound(1);  
  
  //Put the user at the left corner as starting position
  digitalWrite(row[userRow], LOW);  
  digitalWrite(col[userCol], HIGH);
  
  //put the bomb at the bottom corner
  digitalWrite(row[7], LOW);  
  digitalWrite(col[7], HIGH); 
}

void matrixTest() {
  //To test the columns we turn all the rows to low which is on for rows. 
  for (int i=0; i<= 7; i++) { 
    digitalWrite(row[i], LOW);
  }
  
  //Now test all columns one at a time, this lights a column top to bottom.
  for(int i=0; i<= 7; i++) { 
    digitalWrite(col[i], HIGH);
    delay(200);
    digitalWrite(col[i], LOW);
  }
  
  //To test the rows we turn all the cols to high and all of the rows to high
  for (int i=0; i<= 7; i++) { 
    digitalWrite(col[i], HIGH);
    digitalWrite(row[i], HIGH);
  }
 
  //Test all rows at once. 
  for (int i=0; i <= 7; i++) { 
    digitalWrite(row[i], LOW); 
    delay(200);
    digitalWrite(row[i], HIGH); 
  }
}

void ledController(int rowNum, int colNum, int action) { 
  if (action == 0) { //Turn ligh off
    digitalWrite(row[rowNum], HIGH);
    digitalWrite(col[colNum], LOW); 
  } else {
    digitalWrite(row[rowNum], LOW);
    digitalWrite(col[colNum], HIGH); 
  } 
}

void allLeds(int action){
  for (int i=0; i <= 7; i++) {
    ledController(i, i, action);
  }
}

void ledFlashController(int rowNum, int colNum) {
  digitalWrite(row[rowNum], LOW);
  digitalWrite(col[colNum], HIGH);
  delay(1);
  digitalWrite(row[rowNum], HIGH);
  digitalWrite(col[colNum], LOW); 
}

void drawAirplane() { 
  for (int i=0; i <= 200; i++) { 
    ledFlashController(0,3);ledFlashController(0,3);
    ledFlashController(1,3); ledFlashController(1,4); 
    ledFlashController(2,0); ledFlashController(2,3); ledFlashController(2,4);ledFlashController(2,5);
    ledFlashController(3,0); ledFlashController(3,1); ledFlashController(3,2); ledFlashController(3,3); ledFlashController(3,4); ledFlashController(3,5); ledFlashController(3,6); ledFlashController(3,7);
    ledFlashController(4,0); ledFlashController(4,3); ledFlashController(4,4);ledFlashController(4,5);
    ledFlashController(5,3); ledFlashController(5,4);
    ledFlashController(6,3); 
  }
  
}


void drawX() {
  for (int i=0; i <= 50; i++) { 
    ledFlashController(0,0); ledFlashController(0,7); 
    ledFlashController(1,1); ledFlashController(1,6); 
    ledFlashController(2,2); ledFlashController(2,5); 
    ledFlashController(3,3); ledFlashController(3,4); 
    ledFlashController(4,4); ledFlashController(4,3); 
    ledFlashController(5,5); ledFlashController(5,2); 
    ledFlashController(6,6); ledFlashController(6,1); 
    ledFlashController(7,7); ledFlashController(7,0);
  }
}

void drawSmiley(){ //Print a Smiley Face
  for (int i=0; i <= 50; i++) {
     ledFlashController(1,1); ledFlashController(1,2); ledFlashController(1,5); ledFlashController(1,6); 
     ledFlashController(2,1); ledFlashController(2,2); ledFlashController(2,5); ledFlashController(2,6); 
     ledFlashController(4,3); ledFlashController(4,4);
     ledFlashController(5,1); ledFlashController(5,6); 
     ledFlashController(6,2); ledFlashController(6,3); ledFlashController(6,4); ledFlashController(6,5); 
   }
}

void printRound(int gameRound) { //This prints game rounds
  for (int i=1; i <= 60; i++) { 
    switch(gameRound){
     case 1:
        ledFlashController(0,4);
        ledFlashController(1,3); ledFlashController(1,4);
        ledFlashController(2,2); ledFlashController(2,3); ledFlashController(2,4);
        ledFlashController(3,3); ledFlashController(3,4);
        ledFlashController(4,3); ledFlashController(4,4);
        ledFlashController(5,3); ledFlashController(5,4);
        ledFlashController(6,2); ledFlashController(6,3); ledFlashController(6,4);ledFlashController(6,5);
        break;
     case 2: 
       ledFlashController(0,2);ledFlashController(0,3);ledFlashController(0,4);ledFlashController(0,5);
       ledFlashController(1,1);ledFlashController(1,5);
       ledFlashController(2,5);
       ledFlashController(3,4);
       ledFlashController(4,3);
       ledFlashController(5,2);
       ledFlashController(6,1);
       ledFlashController(7,1);ledFlashController(7,2);ledFlashController(7,3);ledFlashController(7,4);ledFlashController(7,5);
       break;
     case 3: 
       ledFlashController(0,2);ledFlashController(0,3);ledFlashController(0,4); 
       ledFlashController(1,5);
       ledFlashController(2,5);
       ledFlashController(3,2);ledFlashController(3,3);ledFlashController(3,4);
       ledFlashController(4,5);
       ledFlashController(5,5);
       ledFlashController(6,2);ledFlashController(6,3);ledFlashController(6,4);
       break;
     case 4:
       ledFlashController(1,2);ledFlashController(1,5);
       ledFlashController(2,2);ledFlashController(2,5); 
       ledFlashController(3,2);ledFlashController(3,3);ledFlashController(3,4);ledFlashController(3,5);
       ledFlashController(4,5);
       ledFlashController(5,5);
       ledFlashController(6,5);
       break;
    }
  }    
}

void loop() {
  //turn all off, then display the user.   
  if(digitalRead(leftButton) == LOW ) { //If left pressed do this. 
    if (userCol == 0) { //If we are already at 1 wrap around
        userCol = 7; 
    } else { 
        userCol = userCol--;
    }
  } 
  
  if(digitalRead(rightButton) == LOW) {
    if (userCol == 7) { //if we are at 8 wrap around
      userCol = 0;
    } else { 
      userCol = userCol++;
    }
  }
   
  if(digitalRead(downButton) == LOW) { //If we pressed down.   
    if (userRow == minRow) { //If we are at the bottom, then wrap to to the top; each round moves you further from the target
      userRow = 0; 
    } else {
      userRow = userRow + 1; 
    }
  }
  
  if(digitalRead(upButton) == LOW) {
    if (userRow == 0) { //if we are at the top, wrap to the bottom
      userRow = minRow; 
    } else { 
      userRow = userRow - 1;
    }
  }
 
  //Start the target action. turn all off, display the target
  
  //scroll the target
  if (loopCount == targetInterval) { //Every Xloops we move. 
    loopCount=0;
    if (targetCol ==  0) { 
       targetCol = 7;
    } else { 
      targetCol--; 
   }  
  
  } else { //Otherwise we just increase the count and animationWait to move
      loopCount++;
  }
   
   //If the pushbutton has been pressed. 
  if (bombRow == NULL) { 
    if (analogRead(pushButton) < 500) { 
      bombRow=userRow + 1;
      bombCol=userCol;
    }
  } else {  
    if (bombRow == 7) {
      if (bombCol == targetCol) {//If the bomb is in the the same spot of the target. 
        drawSmiley();
        gameRound++; 
        printRound(gameRound);
        targetInterval--;
        userRow=0; 
        userCol=0 ;
        targetRow=7;
        targetCol=7;
        targetCount=0;
        loopCount=0;
        bombRow=NULL; 
        bombCol=NULL;
        minRow--;
        if ( gameRound == 5) { // If we have won the 4th round, restar.
            gameDefaults();
        }
      } else {
        drawX();
        delay(1000);
        gameDefaults();
      }
     
    } else {
     if (loopCount == 0 || loopCount ==2) { 
       bombRow++;
      }
    }
 }
 
 for(int i=0; i <= 40; i++) {
   ledFlashController(userRow, userCol);
   ledFlashController(targetRow, targetCol);
   if (bombRow != NULL) { 
     ledFlashController(bombRow, bombCol);
   }
 } 
} 
