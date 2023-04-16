/**********************

 The circuit:
 * LCD RS pin to digital pin 7
 * LCD Enable pin to digital pin 6
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 */

// include the library code:
#include <LiquidCrystal.h>
#include <Keypad.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 6, 5, 4, 3, 2); 

#define MOTOR A0

const byte ROWS = 4; //four rows
const byte COLS = 3; //four columns
//define the cymbols on the buttons of the keypads
char password[] = {
  '5','4','1','9','1','5'};

/*
 * Default Password: 541915
 */

char userPassword[6];
char hexaKeys[ROWS][COLS] = {
  {
    '1','2','3'                }
  ,
  {
    '4','5','6'                }
  ,
  {
    '7','8','9'                }
  ,
  {
    0X00,'0',0X00                }
};
byte rowPins[ROWS] = {
  12, 11, 10, 9}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {
  A5, A4, A3}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  pinMode(A0, OUTPUT);
  // set up the lcd's number of columns and rows: 
  lcd.begin(20,2);
  lcd.print("Enter Password:");

}
void loop(){
  getPassword();
}

void getPassword(){

  byte count = 0;
  while(1){
    char customKey = customKeypad.getKey();
    if (customKey){
      userPassword[count]=customKey;
      lcd.setCursor(count, 1);
      lcd.write('*');
      delay(300);  // Debounce Delay
      count++;
    }
    if(count == 6)
      break;
  }

  verifyPassword();
}

void verifyPassword(){
  byte count=0;
  for(char t=0; t<6; t++){
    if(userPassword[t]==password[t]){
      count++;
    }
  }
  if(count == 6){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Correct Password");
    digitalWrite(MOTOR, HIGH);
    while(1);
  }
  else{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Incorrect Password");  
    delay(1500);
    lcd.clear();
    lcd.print("Enter Password:");
  }
}





