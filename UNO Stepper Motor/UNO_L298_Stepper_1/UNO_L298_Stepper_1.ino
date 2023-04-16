#include <Stepper.h>

const int stepsPerRevolution = 20; 

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8,9,10,11);            

void setup() {
  // set the speed at 40 rpm:
  myStepper.setSpeed(40);
}

void loop() {
  // step one revolution  in one direction:
  myStepper.step(~stepsPerRevolution);
  delay(20);
}
