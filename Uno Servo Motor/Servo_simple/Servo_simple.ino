#include <Servo.h>

Servo servo1;
//Servo servo2;

void setup()
{
  servo1.attach(12);  
  Serial.begin(9600);
  Serial.println("Servo Beging");
}

void loop()
{ 
  Serial.println("Hello");  
  servo1.write(0);
  delay(2000);
  servo1.write(180);
  delay(2000);  
  
}
