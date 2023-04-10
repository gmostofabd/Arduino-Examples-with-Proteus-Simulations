#include <Stepper.h>

#define SWITCH 3
const int stepsPerRevolution = 20; 

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8,9,10,11);            

void setup() {
  pinMode(SWITCH, INPUT_PULLUP);
  // set the speed at 40 rpm:
  myStepper.setSpeed(40);
}

void loop() {
  if(digitalRead(SWITCH) == 0){
    // rotate motor anticlockwise
    myStepper.step(stepsPerRevolution);
    delay(20);
  } 
  else{
    // rotate motor clockwise
    myStepper.step(~stepsPerRevolution);
    delay(20);
  }
}
