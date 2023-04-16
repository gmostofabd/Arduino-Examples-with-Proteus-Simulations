#include <LiquidCrystal.h>
LiquidCrystal lcd1(13, 12, 11, 10, 9, 8);
LiquidCrystal lcd2(7, 6, 5, 4, 3, 2);
int value1 = 0;
int value2 = 0;
int lm35_pool = A3;
int lm35_air = A2;
void setup()
{
  Serial.begin(9600);
  lcd1.begin(16, 2);
  lcd1.clear();
  lcd2.begin(16, 2);
  lcd2.clear();
}
void loop()
{
  value1 = analogRead(lm35_pool); 
  float millivolts1 = ( value1 / 1024.0) * 5 * 1000;
  float cel1 = millivolts1 / 10;

  lcd2.print("POOL= ");
  lcd2.print(cel1);
  lcd2.print("*C");
  lcd2.println();
  delay(1000);

  value2 = analogRead(lm35_air); 
  float millivolts2 = ( value2 / 1024.0) * 5 * 1000;
  float cel2 = millivolts2 / 10;

  lcd1.print("AIR= ");
  lcd1.print(cel2);
  lcd1.print("*C");
  lcd1.println();
  delay(1000);

}
