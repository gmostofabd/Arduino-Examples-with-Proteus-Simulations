#include<Servo.h>

int pos=0; // variable to store the servo position

Servo myservo;         // create servo object to control a servo
// twelve servo objects can be created on most boards

void setup() {
  // put your setup code here, to run once:
   myservo.attach(11);   // attaches the servo on pin 9 to the servo object
}

void loop() {
  // put your main code here, to run repeatedly:
    for(pos =0;pos<=90;pos++){        // goes from 0 degrees to 90 degrees
      myservo.write(pos);          // tell servo to go to position in variable 'pos'
      delay(100);          // waits 20ms for the servo to reach the position
    }
    for(pos =90;pos>=0;pos--){        // goes from 90 degrees to 0 degrees
      myservo.write(pos);          // tell servo to go to position in variable 'pos'
      delay(100);      // waits 20ms for the servo to reach the position
    }
}
