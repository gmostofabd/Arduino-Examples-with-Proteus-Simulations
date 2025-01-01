// For First Traffic Signal
#define red1 13
#define green1 11
#define yellow1 12

// For Second Traffic Signal
#define red2 10
#define green2 8
#define yellow2 9

void setup() {
  pinMode(red1, OUTPUT);
  pinMode(yellow1, OUTPUT);
  pinMode(green1, OUTPUT);

  pinMode(red2, OUTPUT);
  pinMode(yellow2, OUTPUT);
  pinMode(green2, OUTPUT);

  digitalWrite(red1, LOW);
  digitalWrite(yellow1, LOW);
  digitalWrite(green1, LOW);
  digitalWrite(red2, LOW);
  digitalWrite(yellow2, LOW);
  digitalWrite(green2, LOW);


}

void loop() {
  //  Calling Function...
  Traffic_Signals();
}

// Creating a Function for Traffic Signals

void Traffic_Signals()
{
  //Turn OFF both Yellow Signals and Turn ON Red1 signal and Green2 Signal
  digitalWrite(yellow1, LOW);
  digitalWrite(yellow2, LOW);
  digitalWrite(red1, HIGH);
  digitalWrite(red2, LOW);
  digitalWrite(green1, LOW);
  digitalWrite(green2, HIGH);
  delay(3000);

  //Turn ON both Yellow Signals and Turn OFF Red1 signal and Green2 Signal
  digitalWrite(yellow1, HIGH);
  digitalWrite(yellow2, HIGH);
  digitalWrite(red1, LOW);
  digitalWrite(red2, LOW);
  digitalWrite(green2, LOW);
  digitalWrite(green1, LOW);
  delay(1000);

  //Turn OFF both Yellow Signals and Turn ON Red2 signal and Green1 Signal
  digitalWrite(yellow1, LOW);
  digitalWrite(yellow2, LOW);
  digitalWrite(red1, LOW);
  digitalWrite(red2, HIGH);
  digitalWrite(green2, LOW);
  digitalWrite(green1, HIGH);
  delay(3000);

  //Turn ON both Yellow Signals and Turn OFF Red2 signal and Green1 Signal
  digitalWrite(yellow1, HIGH);
  digitalWrite(yellow2, HIGH);
  digitalWrite(red1, LOW);
  digitalWrite(red2, LOW);
  digitalWrite(green2, LOW);
  digitalWrite(green1, LOW);
  delay(1000);

}
