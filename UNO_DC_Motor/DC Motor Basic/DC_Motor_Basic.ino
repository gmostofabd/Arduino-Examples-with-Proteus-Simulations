#define MP 0 // Motor Positive Terminal
#define MN 1 // Motor Negative Terminal

void setup(){
  pinMode(MP, OUTPUT);
  pinMode(MN, OUTPUT);
}

void loop(){
  digitalWrite(MP, HIGH);
  digitalWrite(MN, LOW);
  delay(1000);
  digitalWrite(MP, LOW);
  digitalWrite(MN, HIGH);
  delay(1000);

}
