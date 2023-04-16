#include <Servo.h>
#include <EEPROM.h>

Servo servo1;
Servo servo2;

const int pot = A1;
int btn = 1;
int btnValue; 
int potValue; 
int angleValue; 
int feedbackValue;

void setup() {
  
  pinMode(btn, INPUT);
  
  servo1.attach(11);
  servo2.attach(5);
  
  servo1.write(0);
  servo2.write(0);

}

void loop() {

  btnValue = digitalRead(btn);
  
  if (btnValue == HIGH) {
 
    for (int i = 0 ; i <= 100 ; i++) {
    
    potValue = analogRead(pot);
    angleValue = map(potValue, 0, 1023, 0, 180);
    EEPROM.write(i,angleValue);
    delay(500); 
    feedbackValue = EEPROM.read(i);
    servo1.write(angleValue); 
    servo2.write(feedbackValue);  
    }
  }
}
