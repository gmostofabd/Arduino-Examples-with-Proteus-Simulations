int ledPin = 13;
int pirPin = 2; 
int pirStat = 0;
 
void setup() {
  pinMode(ledPin, OUTPUT);     
  pinMode(pirPin, INPUT);     
 
  Serial.begin(9600);
}
 
void loop(){
  
  pirStat = digitalRead(pirPin); 
   
  if (pirStat == HIGH) { 
    digitalWrite(ledPin, HIGH); 
    Serial.println("Motion Detected");
    delay(1000);

  } 
  else {
    digitalWrite(ledPin, LOW);
    Serial.println("No Motion Detected");
    delay(1000);
  }
}
