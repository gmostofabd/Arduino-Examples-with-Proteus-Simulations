#include <LiquidCrystal.h>
LiquidCrystal lcd( 13, 12, 11, 10, 9, 8);
int GASSENSOR =5;
int LEDRED =7;
int LEDBLUE =6;
void setup() {
  // put your setup code here, to run once:
pinMode(GASSENSOR, INPUT_PULLUP);
pinMode(LEDRED, OUTPUT);
pinMode(LEDBLUE, OUTPUT);
lcd.begin(20,4);
lcd.setCursor(2,0);
lcd.print("MQ-2 Gas Sensor");
lcd.setCursor(6,1);
lcd.print("ALKOHOL"); 
lcd.setCursor(5,2);
lcd.print("Detection");
delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
int GASSENSOR_READ = digitalRead(GASSENSOR);
if (GASSENSOR_READ == LOW){
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("ALKOHOL NOT DETECTED");
  digitalWrite(LEDRED, LOW);
  digitalWrite(LEDBLUE, HIGH);
  delay(20);
}
else {
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("  ALKOHOL DETECTED");
  digitalWrite(LEDRED, HIGH);
  digitalWrite(LEDBLUE, LOW);
  delay(20);
}
}
