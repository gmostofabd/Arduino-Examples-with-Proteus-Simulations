int leftMotorForward = 7;
int leftMotorReverse = 6;
void setup() {
  Serial.begin(9600);
  pinMode(leftMotorForward, OUTPUT);
  pinMode(leftMotorReverse, OUTPUT);
}

void loop() {
  
  //FORWARD
  digitalWrite(leftMotorForward, HIGH);
  digitalWrite(leftMotorReverse, LOW);
  delay(2000);

  //REVERSE
  digitalWrite(leftMotorReverse, HIGH);
  digitalWrite(leftMotorForward, LOW);
  delay(2000);

  //STOP
  digitalWrite(leftMotorReverse, LOW);
  digitalWrite(leftMotorForward, LOW);
  delay(2000);
}
