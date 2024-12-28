int IRSensor = 2; // connect ir sensor to arduino pin 2
int LED = 13; // connect Led to arduino pin 13
void setup()
{
  pinMode (IRSensor, INPUT); // sensor pin INPUT
  pinMode (LED, OUTPUT); // Led pin OUTPUT
}

void loop()
{
  int sensor_status = digitalRead (IRSensor);

  if (sensor_status == 1) {
    digitalWrite(LED, HIGH); // LED ON
  }
  else
  {
    digitalWrite(LED, LOW); // LED OFF
  }
}
