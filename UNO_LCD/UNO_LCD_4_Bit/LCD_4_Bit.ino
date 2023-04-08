/*
 LiquidCrystal Library 
 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.
 
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 10
 * LCD D5 pin to digital pin 9
 * LCD D6 pin to digital pin 8
 * LCD D7 pin to digital pin 7
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 */
 

#include<LiquidCrystal.h>

//initialize the library with numbers of the interface pins
//LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);


void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.clear();
  lcd.print("Arduino Tutorials"); //Print a message to the LCD.
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  //print the number of seconds since reset:

  delay(3000);

  lcd.print("MELAB");
  delay(2000);
  lcd.clear();

  delay(2000);

  lcd.print("Cursor Blink");
  lcd.blink();

  delay(2000);
  lcd.clear();


  lcd.print("U_Cursor");
  lcd.cursor();

  delay(2000);
  lcd.clear();

  lcd.print("No cursor");
  lcd.noCursor();

  delay(2000);
  lcd.clear();

  lcd.print("Resume");
  lcd.display();
  delay(2000);
  lcd.clear();

}
