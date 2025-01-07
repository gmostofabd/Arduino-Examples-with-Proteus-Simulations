#include <Stepper.h>
const int apr = 200;

Stepper stepper(apr, 8, 9, 10, 11);
void setup() {
  stepper.setSpeed(60);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  stepper.step(apr);
  delay(1000);
  stepper.step(-apr);
  delay(1000);

}
