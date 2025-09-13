#include <Servo.h>
#include <LiquidCrystal.h>
// --- LCD (RS, E, D4, D5, D6, D7) ---
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

Servo myservo;

const int trigPin = 11;
const int echoPin = 10;
int degree = 0;

const int minAngle = 0;
const int maxAngle = 180;

long duration;
float distanceCm;

void setup() {
  Serial.begin(115200);
  myservo.attach(9);  // Servo signal pin
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);



    // LCD setup
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("  SONAR RADAR ");
  //lcd.clear();
  Serial.println("Radar Start"); // send start word for Python
  delay(1000);
}

float readDistanceCM() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH, 30000); // 30ms timeout
  distanceCm = duration * 0.034 / 2.0;
  
  if(distanceCm == 0) distanceCm = 0.0; // handle timeout
  return distanceCm;
}

void loop() {
  // Sweep servo from 0 to 180
  for(int angle = minAngle; angle <= maxAngle; angle++){
    myservo.write(angle);
    delay(20); // wait for servo to reach position
    degree = int(angle);

    float dist = readDistanceCM();
    Serial.print(angle);
    Serial.print(",");
    Serial.println(dist);
    displayOnLCD();
  }

  // Optional: Sweep back 180 to 0
  for(int angle = maxAngle; angle >= minAngle; angle--){
    myservo.write(angle);
    delay(20);
    degree = int(angle);
    float dist = readDistanceCM();
    Serial.print(angle);
    Serial.print(",");
    Serial.println(dist);
    displayOnLCD();
  }

}


void  displayOnLCD(){
  lcd.setCursor(0, 1);
  lcd.print("D: ");
  lcd.print(distanceCm, 1);
  lcd.setCursor(10, 1);
  lcd.print("A: ");
  lcd.print(degree);
  //delay(500);
}

