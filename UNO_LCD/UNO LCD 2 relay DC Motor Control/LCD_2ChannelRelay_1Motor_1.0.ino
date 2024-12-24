// Include the LiquidCrystal library for interfacing with an LCD display
#include <LiquidCrystal.h>

// Define pin numbers for the LCD (RS, Enable, D4, D5, D6, D7)
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;

// Create an LCD object with the specified pin connections
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Define pin numbers for motor control and input switches
int Fwd = 8; // Forward button/input pin
int Rev = 9; // Reverse button/input pin
int Mtr1_A = 10; // Motor control pin A
int Mtr1_B = 11; // Motor control pin B

void setup() 
{
    // Set the input and output modes for the motor control and button pins
    pinMode(Fwd, INPUT); // Set Forward button as input
    pinMode(Rev, INPUT); // Set Reverse button as input
    pinMode(Mtr1_A, OUTPUT); // Set Motor control A as output
    pinMode(Mtr1_B, OUTPUT); // Set Motor control B as output
    
    // Initialize the LCD display with a size of 16 columns and 2 rows
    lcd.begin(16, 2);
    
    // Display a welcome message on the LCD
    lcd.print("Motor & 2 Relays");
    delay(1000); // Wait for 1 second
    lcd.clear(); // Clear the LCD display
}

void loop() 
{
   // Check if the Forward button is pressed and Reverse button is not pressed
   if(digitalRead(Fwd) == HIGH && digitalRead(Rev) == LOW)
   {
     digitalWrite(Mtr1_A, HIGH); // Turn motor in clockwise direction
     digitalWrite(Mtr1_B, LOW);
     lcd.setCursor(0, 0); // Set LCD cursor to the beginning of the first line
     lcd.print("C-wise Direction"); // Display clockwise direction on LCD
   } 
   // Check if the Reverse button is pressed and Forward button is not pressed
   else if(digitalRead(Rev) == HIGH && digitalRead(Fwd) == LOW)
   {
     digitalWrite(Mtr1_A, LOW); // Turn motor in anti-clockwise direction
     digitalWrite(Mtr1_B, HIGH);
     lcd.setCursor(0, 0); // Set LCD cursor to the beginning of the first line
     lcd.print("A-wise Direction"); // Display anti-clockwise direction on LCD
   }
   // Check if both buttons are pressed or neither button is pressed
   else if(digitalRead(Rev) == LOW && digitalRead(Fwd) == LOW || digitalRead(Rev) == HIGH && digitalRead(Fwd) == HIGH)
   {
     digitalWrite(Mtr1_A, LOW); // Stop the motor
     digitalWrite(Mtr1_B, LOW);
     lcd.setCursor(0, 0); // Set LCD cursor to the beginning of the first line
     lcd.print("Motor Stop      "); // Display motor stop status on LCD
   }
}
