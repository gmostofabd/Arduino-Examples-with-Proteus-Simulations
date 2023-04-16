#include <Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

int ldr=A4;
int value=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Loading/Initializing");
  lcd.clear();
  lcd.setCursor(0, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
value=analogRead(ldr);
Serial.println("Intensity of the LDR is =");
Serial.println(value);
lcd.clear();
lcd.setCursor(0, 0);
lcd.print(value);
delay(1000);
if(value>=100 && value<=300)
{
    int LeftMotorForward=7;
    int LeftMotorReverse=6;
    int RightMotorForward=5;
    int RightMotorReverse=4;
    pinMode(LeftMotorForward, OUTPUT);
    pinMode(LeftMotorReverse, OUTPUT);
    pinMode(RightMotorForward, OUTPUT);
    pinMode(RightMotorReverse, OUTPUT);
    
    
    digitalWrite(LeftMotorForward, LOW);
    digitalWrite(LeftMotorReverse, HIGH);
    digitalWrite(RightMotorForward, HIGH);
    digitalWrite(RightMotorReverse, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Going F... LDR value: ");
    lcd.print(value);
    delay(3000);

}
if(value>=301 && value<=500)
{
    int LeftMotorForward=7;
    int LeftMotorReverse=6;
    pinMode(LeftMotorForward, OUTPUT);
    pinMode(LeftMotorReverse, OUTPUT);
    
    
    digitalWrite(LeftMotorReverse, HIGH);
    digitalWrite(LeftMotorForward, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Going B... LDR value: ");
    lcd.print(value);
    delay(3000);

}
if(value<100)
{
    int LeftMotorForward=7;
    int LeftMotorReverse=6;
    pinMode(LeftMotorForward, OUTPUT);
    pinMode(LeftMotorReverse, OUTPUT);
    
    
    digitalWrite(LeftMotorReverse, LOW);
    digitalWrite(LeftMotorForward, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Stopped... LDR value: ");
    lcd.print(value);
    delay(3000);

}
if(value>=501 && value<=700)
{
    int LeftMotorForward=7;
    int LeftMotorReverse=6;
    pinMode(LeftMotorForward, OUTPUT);
    pinMode(LeftMotorReverse, OUTPUT);
    
    
    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(LeftMotorReverse, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Going R... LDR value: ");
    lcd.print(value);
    delay(3000);

}
if(value>700)
{
    int LeftMotorForward=7;
    int LeftMotorReverse=6;
    pinMode(LeftMotorForward, OUTPUT);
    pinMode(LeftMotorReverse, OUTPUT);
    
    
    digitalWrite(LeftMotorReverse, HIGH);
    digitalWrite(LeftMotorForward, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Going L... LDR value: ");
    lcd.print(value);
    delay(3000);

}
}
