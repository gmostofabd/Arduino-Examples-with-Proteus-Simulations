const int trigPin = 4;
const int echoPin = 5;
const int buzzer = 3;
int LeftMotorForward = 7;
int LeftMotorReverse = 6;



long duration;
int distance;

int ledPin1 = 8, ledPin2 = 9, ledPin3 = 10, ledPin4 = 11, ledPin5 = 12;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode (trigPin, OUTPUT);
  pinMode (echoPin, INPUT);
  pinMode (ledPin1, OUTPUT);
  pinMode (ledPin2, OUTPUT);
  pinMode (ledPin3, OUTPUT);
  pinMode (ledPin4, OUTPUT);
  pinMode (ledPin5, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorReverse, OUTPUT);


  
}

void loop() {

  digitalWrite(trigPin, LOW);
  delay(2);
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.034) / 2;
  
  if (distance >= 0 && 20 <= distance)
  {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin5, HIGH);
  }
  else if (distance >= 21 && 40 <= distance)
  {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin5, LOW);
  }
  else if (distance >= 41 && 60 <= distance)
  {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin5, LOW);

  }
  else if (distance >= 61 && 80 <= distance)
  {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin5, LOW);
  }
  else
  {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin5, LOW);
    tone (buzzer, 1000);
    delay(100);
    noTone(buzzer);
    delay(1000);
  
   
    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(LeftMotorForward, LOW);
    delay(2000);

    digitalWrite(LeftMotorReverse, HIGH);
    digitalWrite(LeftMotorForward, LOW);
    delay(2000);

    digitalWrite(LeftMotorForward, LOW);
    digitalWrite(LeftMotorForward, LOW);
    delay(2000);
  }
  delay(900000);
}
