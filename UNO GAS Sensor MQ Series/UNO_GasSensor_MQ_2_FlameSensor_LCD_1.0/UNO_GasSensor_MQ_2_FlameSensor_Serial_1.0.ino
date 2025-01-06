#include <Servo.h>
Servo myservo;
int flame = 11;
int smoke = 12;
int red = 2;
int green = 3 ;
int buzzer = 10 ;

void setup ()
{
  pinMode (flame, INPUT) ;
  pinMode (smoke, INPUT) ;
  pinMode (red, OUTPUT) ;
  pinMode (green, OUTPUT) ;
  pinMode (buzzer, OUTPUT) ;
  Serial.begin(9600);
  myservo.attach(8);
  myservo.write(0);
}

void loop ()
{
  int f = digitalRead(flame) ;
  int s = digitalRead(smoke);

  if ( f == HIGH or s == HIGH)
  {
    digitalWrite(red, HIGH);
    digitalWrite(buzzer, HIGH);
    digitalWrite(green, LOW);
    myservo.write(180);
  }
  else
  {
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(buzzer, LOW);
    myservo.write(0);
  }
  Serial.print(f);
  Serial.print("* ");
  Serial.print(s);
  Serial.println("");
 
  delay(100);
}
