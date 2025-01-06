//LCD library 
#include<LiquidCrystal.h>

//lcd pins declarations 
LiquidCrystal lcd(12 , 11 , 5 ,4 ,3 ,2);

//pins in use
int Gas = 9;
int redLed = 7; //presense of gas 
int greenLed = 6; //normaml mode absense of gas 
int alarm = 8; // ring incase of gas 


// setup mode

void setup() {
Serial.begin(9600);
pinMode(Gas , INPUT);
  
}

void loop() {

//when gas is detected 
  if(digitalRead(Gas) == HIGH){
    lcd.setCursor(0,0);
    lcd.print(" Gas Detected ");
    Serial.println("Gas detected ");
    digitalWrite(7 , HIGH);
    digitalWrite(6, LOW);
    digitalWrite(8,HIGH);
  }

  //without gas detection 
else{
  lcd.setCursor(0,0);
  lcd.print("No Gaas Detected ");
  Serial.println("No Gas:  ");
  digitalWrite(6, HIGH);
  digitalWrite(7 ,LOW);
  digitalWrite(8,LOW);
}
delay(500);
lcd.clear();

}
