
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
  lcd.print("Recieved String: ");
  Serial.begin(9600);
  Serial.println("Enter Alpha-numeric Data:");
}

void loop() {
  int charLength = 0, element = 0, i=0;
  char data[16];
  for(charLength=0;charLength<16;charLength++){
check:  
    if(Serial.available() > 0){ 
      i = Serial.read();
      if(i!=13){
        data[element] = i;
        element++;
      }
      else{
        goto show;
      }
    }
    else{
      goto check;
    }
  }
show:
  lcd.clear();
  lcd.print("Received String: ");
  lcd.setCursor(0,1);
  for(i=0;i<charLength;i++){
    lcd.print(data[i]); 
  }
  
  Serial.println(data);
}



