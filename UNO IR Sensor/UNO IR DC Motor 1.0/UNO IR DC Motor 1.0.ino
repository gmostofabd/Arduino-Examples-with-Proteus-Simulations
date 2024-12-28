#include<Servo.h>
int IRSensor = 2; //cpnnect ir sensor to arduino pin2
Servo myservo;


void setup() {
  // put your setup code here, to run once:
  pinMode (IRSensor, INPUT);// sensor pin INPUT
  myservo.attach(11);
}

int pos = 0;
void loop() {

  int sensor_status = digitalRead (IRSensor);

  if (sensor_status == 1) {

    for (pos = 0; pos <=78; pos++) {
      myservo.write(pos);
      delay(100);
    }
    delay(38000);
    for (pos = 78; pos >= 0; pos--) {
      myservo.write(pos);
      delay(100);
    }
  }
}
