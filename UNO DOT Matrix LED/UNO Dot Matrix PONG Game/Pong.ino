#include"project.h"

//COLUMNS
#define C1 4
#define C2 5
#define C3 6
#define C4 7
#define C5 8
#define C6 9
#define C7 10
#define C8 11
//ROWS
#define R1 12
#define R2 13
#define R3 A0
#define R4 A1
#define R5 A2
#define R6 A3
#define R7 A4
#define R8 A5
//BUTTONS
#define B1 2
#define B2 3
#define B3 1
#define B4 0

//for controlling interrupts
int upButton = 0;
int downButton = 0;

Ball ball = Ball();
int timer = 1;
int state1 = 0, state2=0;


void setup() {
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(R3, OUTPUT);
  pinMode(R4, OUTPUT);
  pinMode(R5, OUTPUT);
  pinMode(R6, OUTPUT);
  pinMode(R7, OUTPUT);
  pinMode(R8, OUTPUT);

  pinMode(C1, OUTPUT);
  pinMode(C2, OUTPUT);
  pinMode(C3, OUTPUT);
  pinMode(C4, OUTPUT);
  pinMode(C5, OUTPUT);
  pinMode(C6, OUTPUT);
  pinMode(C7, OUTPUT);
  pinMode(C8, OUTPUT);

  digitalWrite(R1,HIGH);
  digitalWrite(R2,HIGH);
  digitalWrite(R3,HIGH);
  digitalWrite(R4,HIGH);
  digitalWrite(R5,HIGH);
  digitalWrite(R6,HIGH);
  digitalWrite(R7,HIGH);
  digitalWrite(R8,HIGH);
  digitalWrite(C1,LOW);
  digitalWrite(C2,LOW);
  digitalWrite(C3,LOW);
  digitalWrite(C4,LOW);
  digitalWrite(C5,LOW);
  digitalWrite(C6,LOW);
  digitalWrite(C7,LOW);
  digitalWrite(C8,LOW);

  pinMode(B1, INPUT_PULLUP);
  pinMode(B2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(B1), up_right, RISING);
  attachInterrupt(digitalPinToInterrupt(B2), down_right, RISING);
  pinMode(B3, INPUT_PULLUP);
  pinMode(B4, INPUT_PULLUP);

  for(int i = 0; i < X_SIZE_OF_LED; i++){
    for(int j = 0; j < Y_SIZE_OF_LED; j++){
        array[i][j] = 0;
    }
  }
  ball.ballInit();
  left.controllerInit();
  right.controllerInit();
}

void new_game(){
  ball.make3();
  for(int i = 0; i < 70; i++){
    updateLED();
  }
  ball.remove3();
  ball.make2();
  for(int i = 0; i < 70; i++){
    updateLED();
  }
  ball.remove2();
  ball.make1();
  for(int i = 0; i < 70; i++){
    updateLED();
  }
  ball.remove1();
  newGame = 0;  
}

void setRow(int row){
  if(row==1) digitalWrite(R1,LOW); else digitalWrite(R1,HIGH);
  if(row==2) digitalWrite(R2,LOW); else digitalWrite(R2,HIGH);
  if(row==3) digitalWrite(R3,LOW); else digitalWrite(R3,HIGH);
  if(row==4) digitalWrite(R4,LOW); else digitalWrite(R4,HIGH);
  if(row==5) digitalWrite(R5,LOW); else digitalWrite(R5,HIGH);
  if(row==6) digitalWrite(R6,LOW); else digitalWrite(R6,HIGH);
  if(row==7) digitalWrite(R7,LOW); else digitalWrite(R7,HIGH);
  if(row==8) digitalWrite(R8,LOW); else digitalWrite(R8,HIGH);
}

void setLEDInActiveRow(int col, int state){
  if(col==1) digitalWrite(C1,state);
  if(col==2) digitalWrite(C2,state);
  if(col==3) digitalWrite(C3,state);
  if(col==4) digitalWrite(C4,state);
  if(col==5) digitalWrite(C5,state);
  if(col==6) digitalWrite(C6,state);
  if(col==7) digitalWrite(C7,state);
  if(col==8) digitalWrite(C8,state);
}

void updateLED(){
  for(int i = 0; i <= Y_SIZE_OF_LED; i++){
    setRow(i + 1);
    for(int j = 0; j <= X_SIZE_OF_LED; j++){ 
      setLEDInActiveRow(j + 1, array[j][i]);
    }
    delay(1);    
  }
}

//for interrupt of up button
void up_right(){
  right.go_up();
}

//for interrupt of down button
void down_right(){
  right.go_down();
}

void checkLeftController(){
  if(digitalRead(B3) == HIGH){
    if(state1 == 0){
      state1 = 1;
      left.go_up();
    }
  }
  else{
    if(state1 == 1){
      state1 = 0;
    }        
  }
  if(digitalRead(B4) == HIGH){
    if(state2 == 0){
      state2 = 1;
      left.go_down();
    }
  }
  else{
    if(state2 == 1){
      state2 = 0;
    }        
  }
}


void loop() {
  if(newGame) new_game();
  checkLeftController();
  if(timer%45 == 0)
    ball.move();
  updateLED();
  timer++;
}
