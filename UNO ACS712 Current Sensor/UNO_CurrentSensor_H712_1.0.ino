
#include <LiquidCrystal.h>
LiquidCrystal LCD(9,8,5,4,3,2);
double acsoffset=2.5;
double sensitivity=0.066;
double current=0;
double voltageRead=0;
void setup() {
  
LCD.begin(16,2);
pinMode(13,OUTPUT);
 digitalWrite(13,LOW);
}
void loop() {
double value=analogRead(A0);
voltageRead=(value*5/1023);
current=(voltageRead-acsoffset)/sensitivity;
LCD.setCursor(0,0);
LCD.print("current=");
LCD.print(current);
LCD.print("Amp");

if(current>5.99) //offset value of current
{
  delay(3000);   //Fault detection delay
  double value=analogRead(A0);
voltageRead=(value*5/1023);
current=(voltageRead-acsoffset)/sensitivity;
  
if(current>5.99) //offset value of current
{
     digitalWrite(13,HIGH);
}
  } 
  
delay(500);
}