/* 
 The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the lcd's number of columns and rows: 
  lcd.begin(16, 2);
}

void loop() { 
  lcd.setCursor(0,0);
  lcd.print("Numbers: ");

  for(int i=0; i<10; i++){
    lcd.setCursor(4,1);
    lcd.print(i);    // requires integer as input -- don't use char 
    delay(500);
  }
}

