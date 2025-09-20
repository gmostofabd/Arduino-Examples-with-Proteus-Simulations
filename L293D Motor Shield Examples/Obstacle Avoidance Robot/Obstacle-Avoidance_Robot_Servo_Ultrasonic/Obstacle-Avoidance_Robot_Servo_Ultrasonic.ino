#include "AFMotor.h"
#include <Servo.h>

// === Motors ===
AF_DCMotor motorLF(1);  // Left Front M1
AF_DCMotor motorLR(2);  // Left Rear M2
AF_DCMotor motorRF(3);  // Right Front M3
AF_DCMotor motorRR(4);  // Right Rear M4

// === Servo ===
Servo sensorServo;  // D9 for ultrasonic sensor

// === Ultrasonic Sensor ===
const int trigPin = A0;
const int echoPin = A1;
long duration;
int distance;

// === Settings ===
int motorSpeed = 180;
int safeDistance = 20;  // cm

void setup() {
  Serial.begin(9600);
  Serial.println("Obstacle Avoidance Robot Starting...");

  // Motor speed
  motorLF.setSpeed(motorSpeed);
  motorLR.setSpeed(motorSpeed);
  motorRF.setSpeed(motorSpeed);
  motorRR.setSpeed(motorSpeed);

  // Attach servo
  sensorServo.attach(9);
  sensorServo.write(90);  // center

  // Ultrasonic pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  int minDistance = 200;

  // Sweep servo from 60° to 120° and find nearest obstacle
  for(int angle = 60; angle <= 120; angle += 15) {
    sensorServo.write(angle);
    delay(200);
    int d = readUltrasonic();
    if(d < minDistance) minDistance = d;
  }

  Serial.print("Nearest obstacle: ");
  Serial.print(minDistance);
  Serial.println(" cm");

  // --- Decision ---
  if(minDistance > safeDistance){
    moveForward();
    Serial.println("Moving Forward");
  }
  else{
    stopMotors();
    Serial.println("Obstacle! Stopping");
    delay(300);

    // Basic avoidance: turn right
    turnRight();
    Serial.println("Turning Right");
    delay(500);

    stopMotors();
    delay(200);
  }
}

// --- Functions ---
int readUltrasonic() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // cm
  return distance;
}

void moveForward() {
  motorLF.run(FORWARD);
  motorLR.run(FORWARD);
  motorRF.run(FORWARD);
  motorRR.run(FORWARD);
}

void moveBackward() {
  motorLF.run(BACKWARD);
  motorLR.run(BACKWARD);
  motorRF.run(BACKWARD);
  motorRR.run(BACKWARD);
}

void stopMotors() {
  motorLF.run(RELEASE);
  motorLR.run(RELEASE);
  motorRF.run(RELEASE);
  motorRR.run(RELEASE);
}

void turnRight() {
  motorLF.run(FORWARD);
  motorLR.run(FORWARD);
  motorRF.run(BACKWARD);
  motorRR.run(BACKWARD);
}

void turnLeft() {
  motorLF.run(BACKWARD);
  motorLR.run(BACKWARD);
  motorRF.run(FORWARD);
  motorRR.run(FORWARD);
}
