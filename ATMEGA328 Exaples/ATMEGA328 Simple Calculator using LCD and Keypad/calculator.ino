#include <LiquidCrystal.h>
#define r1 0
#define r2 1
#define r3 2
#define r4 3
#define c1 4
#define c2 5
#define c3 6
#define c4 7

//Define a 4x4 keypad 
const byte ROWS = 4; 
const byte COLS = 4; 
// Define the keys on the keypad
char keys[ROWS][COLS] = {
  {'7', '8', '9', '/'},
  {'4', '5', '6', '*'},
  {'1', '2', '3', '-'},
  {'C', '0', '=', '+'}
};

// Initialize LCD objects
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);


float result = 0;        // Final result of the calculations
float tempNum = 0;       // Temporary number storage for input
char operation = '\0';   // Operation (+, -, *, /) being performed
bool inputInProgress = false; // Flag to track input state

void setup() {
  // Sets the row pins (r1-r4) as OUTPUT and initializes them to a HIGH state.
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(r3, OUTPUT);
  pinMode(r4, OUTPUT);

  digitalWrite(r1, HIGH);
  digitalWrite(r2, HIGH);
  digitalWrite(r3, HIGH);
  digitalWrite(r4, HIGH);

  // Sets the column pins (c1-c4) as INPUT_PULLUP, enabling internal pull-up resistors.
  pinMode(c1, INPUT_PULLUP);
  pinMode(c2, INPUT_PULLUP);
  pinMode(c3, INPUT_PULLUP);
  pinMode(c4, INPUT_PULLUP);
  
  // Initializes the LCD with 16 columns and 2 rows, then displays the initial message on the LCD.
  lcd.begin(16, 2);     
  lcd.print("  gmBD's Calc  "); 

}

// Function to check if a key is pressed
char ckeckInput(void) {
  int Read;
  int flag = 0;

  for (int i = 0; i < ROWS; i++) {
    digitalWrite(i, LOW);

    for (int j = 0; j < COLS; j++) {
      Read = digitalRead(j + 4);

      // Wait until the key is released
      while (Read == LOW) {
        Read = digitalRead(j + 4);
        flag = 1;
      }

      if (flag == 1) {
        // Release the row pin
        digitalWrite(i, HIGH);
        return keys[i][j]; // Return the pressed key
      }
    }
    // Release the row pin
    digitalWrite(i, HIGH);
  }
  return 0; // Return 0 if no key is pressed
}

// Continuously checks for a pressed key using ckeckInput() and processes it using handleInput() if a valid key is detected.
void loop() {
  char key = ckeckInput();

  if (key != '\0') {
    handleInput(key); 
  }
}

// Function to handle the input received from the keypad
void handleInput(char key) {
  // If the key is a digit
  if (isdigit(key)) { 
    if (!inputInProgress) {
      lcd.clear();             // Clear the LCD display
      tempNum = atof(&key);    // Store the first digit as temporary number
      lcd.setCursor(0, 0);     // Set cursor to position (0, 0)
      lcd.print(tempNum);      // Display the number on LCD
      inputInProgress = true;  // Update input in progress flag
    } else {
      lcd.print(key);          // Display additional digits pressed
      tempNum = tempNum * 10 + atof(&key); // Accumulate the digits for a multi-digit number
    }
  } else if (key == 'C') { // If 'C' is pressed, clear the calculator
    lcd.clear();           // Clear the LCD display
    resetCalculator();     // Reset the calculator state
  } else if (key == '=') { // If '=' is pressed, perform the calculation
    if (inputInProgress && operation != '\0') {
      // Perform the calculation
      calculate();         

      lcd.clear(); // Clear the LCD
      lcd.setCursor(0, 0);
      lcd.print("result:");

      lcd.setCursor(0, 1); // Move cursor to the second line of LCD
      lcd.print(result);   // Display the result on LCD
      resetCalculator();   // Reset the calculator state
    }
  } else {
    if (inputInProgress) {
      if (operation == '\0') { // If no operation is selected yet
        result = tempNum;     // Store the number as the initial result
      } else {
        calculate();          // Perform the calculation for non-initial results
      }

      lcd.setCursor(0, 1);   // Move cursor to the second line of LCD
      lcd.print(key);        // Display the operator (+, -, *, /) on LCD
      operation = key;       // Store the operator
      inputInProgress = false; // Reset input flag for the next number
    }
  }
}

// Function to perform the calculation based on the stored operator
void calculate() {
  switch (operation) {
    case '+':
      result += tempNum; 
      break;
    case '-':
      result -= tempNum; 
      break;
    case '*':
      result *= tempNum; 
      break;
    case '/':
      if (tempNum != 0) {
        result /= tempNum; 
      } else {
        lcd.clear(); 
        lcd.print("Error: Division by zero"); // Display error message
        delay(2000); // Wait for 2 seconds
        resetCalculator(); // Reset the calculator
      }
      break;
    default:
      break;
  }
}

// Function to reset the calculator state
void resetCalculator() {
  // Reset final result , temporary number , operator and input state flag
  result = 0;            
  tempNum = 0;           
  operation = '\0';     
  inputInProgress = false; 
}
