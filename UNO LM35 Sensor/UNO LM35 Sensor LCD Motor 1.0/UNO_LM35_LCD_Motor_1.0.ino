
#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);

const int isSensor = A0;
const int isLedBlue = 8;
const int isLedGreen = 9;
const int isLedRed = 10;
const int isHeater = 11;
const int isFan = 12;

void setup(){
  lcd.begin(16,2);
  lcd.clear();
  pinMode(isSensor,INPUT);
  pinMode(isLedBlue,OUTPUT);
  pinMode(isLedGreen,OUTPUT);
  pinMode(isLedRed,OUTPUT);
  pinMode(isHeater,OUTPUT);
  pinMode(isFan,OUTPUT);
}

int isWrite(int b, int g, int r, int h, int f);

void loop(){
  int tempC = (analogRead(isSensor) * 500.0 / 1024.0)+0.5;
  lcd.setCursor(0,0);
  lcd.print("Temp Monitoring");
  lcd.setCursor(0,1);
  if(tempC>=20 && tempC<=35){
    lcd.print(String("Temp Read: ")+String(tempC)+String("\337C"));
    isWrite(0,1,0,0,0);
  }else if(tempC<=19){
    lcd.print(String(tempC)+String("\337C, Heater: ON"));
    isWrite(1,0,0,1,0);
  }else if(tempC>=36){
    lcd.print(String(tempC)+String("\337C, Fan: ON"));
    isWrite(0,0,1,0,1);
  }
  delay(100);
  lcd.clear();
}

int isWrite(int b, int g, int r, int h, int f){
  digitalWrite(isLedBlue, b);
  digitalWrite(isLedGreen, g);
  digitalWrite(isLedRed, r);
  digitalWrite(isHeater, h);
  digitalWrite(isFan, f);
  return 0;
}
