// include the library code:
#include <LiquidCrystal.h>

const int rs = 4, en = 2, d4 = A0, d5 = A1, d6 = A2, d7 = A3;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  lcd.print("MULTIMETER");
  delay(5);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("POWER: ");
  lcd.setCursor(0, 1);
  lcd.print("Current: ");
}

void loop() {
  int v = analogRead(A4);
  int i = analogRead(A5);
  float voltage = 5* (float)v / 1023.0 * 2.0;
  float current = 5* (float)(i - 512)/1023.0 * 5.0;
  
  lcd.setCursor(10, 0);
  lcd.print(voltage*current);
  lcd.setCursor(10, 1);
  lcd.print(current);
  delay(500);
}
