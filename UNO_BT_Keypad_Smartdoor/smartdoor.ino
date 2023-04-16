#include <SoftwareSerial.h>
#include "Keypad.h"
const int RELAY_PIN  = A0; // the Arduino pin, which connects to the IN pin of relay
//const int APP = 13;
const int R_N = 4; //four rows
const int C_N = 3; //three columns
char key[R_N][C_N] =
{
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte pin_rows[R_N] = {9, 8, 7, 6}; //connect to row pinouts of keypad
byte pin_colmn[C_N] = {5, 4, 3}; //Connect to column pinouts of keypad

Keypad keypad = Keypad(makeKeymap(key), pin_rows, pin_colmn, R_N, C_N);


const String password_1 = "1234"; // Password 1
const String password_2 = "4321";  // Password 2
String input_password;
int commandChar = 0;

void setup() {
  Serial.begin(9600);
  //pinMode(RELAY_PIN, OUTPUT); // initialize pin as an output.
  pinMode(13, OUTPUT);
  //digitalWrite(RELAY_PIN, LOW); // lock the door
}

void loop() {
  
  char key = keypad.getKey();
  if (key)
  {
    //Serial.println(key);
    if (key == '#') {
      if (input_password == password_1 || input_password == password_2) {
        //Serial.println("Password Correct, Door Unlock");
        digitalWrite(RELAY_PIN, HIGH);  // unlock the door 
      }
      else {
        //Serial.println("Password Incorrect, Try Again");
        digitalWrite(RELAY_PIN, LOW); // lock the door
      }

       input_password = ""; // reset the input password
    }
    else
    {
      input_password += key; // append new character to input password string
    }
  }

  while (Serial.available() == 0) {  }
  commandChar = Serial.parseInt();
  if (commandChar == 5)
  {
    digitalWrite(13, HIGH);
  }
  else
  {
    digitalWrite(13, LOW);
  }
  
}
