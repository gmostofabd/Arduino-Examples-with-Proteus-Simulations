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

#define SW1 A0
#define SW2 A1
#define SW3 A2
#define SW4 A3

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
  // set up the lcd's number of columns and rows: 
  lcd.begin(16, 2);
}

void loop() { 
  lcd.setCursor(0,0);
  lcd.print("Press Switch To");
  lcd.setCursor(0,1);
  lcd.print("Start Counting");
  if(digitalRead(SW1) == 0)
    display2lcd('1');
  else if(digitalRead(SW2) == 0)
    display2lcd('2');
  else if(digitalRead(SW3) == 0)
    display2lcd('3');
  else if(digitalRead(SW4) == 0)
    display2lcd('4');

}

void display2lcd(char p){
  lcd.clear();
  lcd.setCursor(0,0);
  if(p == '1'){
    lcd.print("Switch 1 Pressed");
    for(int i=0; i<10; i++){
      lcd.setCursor(4,1);
      lcd.print(i);
      delay(200);
    }
  }
  else if(p == '2'){
    lcd.print("Switch 2 Pressed");
    for(int i=0; i<100; i++){
      lcd.setCursor(4,1);
      lcd.print(i);
      delay(200);
    }
  }
  else if(p == '3'){
    lcd.print("Switch 3 Pressed");
    for(int i=0; i<1000; i++){
      lcd.setCursor(4,1);
      lcd.print(i);
      delay(200);
    }
  }  
  else {
    lcd.print("Switch 4 Pressed");
    for(int i=0; i<10000; i++){
      lcd.setCursor(4,1);
      lcd.print(i);
      delay(200);
    }
  }
  lcd.clear();
}













