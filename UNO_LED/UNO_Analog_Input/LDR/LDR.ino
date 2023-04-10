int ldr = A4;
int value = 0;
int ledPin = 10;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode (ledPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(ldr);
  if(value<=400)
  {
    digitalWrite(ledPin, HIGH);
    delay(1000);
  }else{
    digitalWrite(ledPin, LOW);
    delay(1000);
  }
  Serial.println("Intensity of the LDR is =");
  Serial.println(value);
  delay(1000);
}
