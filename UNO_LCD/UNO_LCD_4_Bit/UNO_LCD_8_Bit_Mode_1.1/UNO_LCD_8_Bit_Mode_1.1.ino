// Pin definitions for 8-bit mode
#define RS 13  // Register Select pin
#define EN 12  // Enable pin
#define RW 11  // Read/Write pin
#define D0 10  // Data pins D0-D7
#define D1 9
#define D2 8
#define D3 7
#define D4 6
#define D5 5
#define D6 4
#define D7 3

// Custom character (8x5 pixels)
unsigned char specialChar[8] = { 
  0x00, 0x0A, 0x00, 0x00, 0x11, 0x0E, 0x00, 0x00
};

void setup() {
Serial.begin (115200); // Leonardo: wait for serial port to connect 


  // Set all pins as OUTPUT
  pinMode(RS, OUTPUT);
  pinMode(EN, OUTPUT);
  pinMode(RW, OUTPUT);
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);

  // Initialize LCD
  lcdInit();

  // Load custom character into CGRAM
  lcdCommand(0x40);  // Set CGRAM Address
  for (int i = 0; i < 8; i++) {
    lcdData(specialChar[i]);
  }

  lcdCommand(0x80);  // Move cursor to home position
}

void loop() {
  // Write text on the LCD
  lcdCommand(0x80);  // First line, first column
  lcdPrint("    16x2 LCD");

  lcdCommand(0xC0);  // Second line, first column
  lcdPrint("   8 Bit Mode");

  // Print the custom character
  lcdData(0x00);  // Display custom character stored in position 0

  delay(1000);  // Delay for visibility
}

// Function to send a command to the LCD
void lcdCommand(unsigned char command) {
  digitalWrite(RS, LOW);  // RS = 0 (command mode)
  digitalWrite(RW, LOW);  // RW = 0 (write mode)
  lcdWrite8Bits(command);
  delay(2);  // Command execution time
}

// Function to send data to the LCD
void lcdData(unsigned char data) {
  digitalWrite(RS, HIGH);  // RS = 1 (data mode)
  digitalWrite(RW, LOW);   // RW = 0 (write mode)
  lcdWrite8Bits(data);
  delay(2);  // Data write time
}

// Function to write 8 bits to the LCD
void lcdWrite8Bits(unsigned char value) {
  digitalWrite(D0, (value >> 0) & 1);
  digitalWrite(D1, (value >> 1) & 1);
  digitalWrite(D2, (value >> 2) & 1);
  digitalWrite(D3, (value >> 3) & 1);
  digitalWrite(D4, (value >> 4) & 1);
  digitalWrite(D5, (value >> 5) & 1);
  digitalWrite(D6, (value >> 6) & 1);
  digitalWrite(D7, (value >> 7) & 1);

  // Latch data with Enable pulse
  digitalWrite(EN, HIGH);
  delayMicroseconds(1);
  digitalWrite(EN, LOW);
  delayMicroseconds(100);
}

// Function to print a string on the LCD
void lcdPrint(const char *str) {
  while (*str) {
    lcdData(*str++);  // Send each character
  }
}

// Function to initialize the LCD in 8-bit mode
void lcdInit() {
  delay(50);  // Wait for LCD power-up

  // Function Set: 8-bit mode, 2 lines, 5x8 font
  lcdCommand(0x38);
  delay(5);

  // Display ON, Cursor OFF, Blink OFF
  lcdCommand(0x0C);
  delay(5);

  // Clear Display
  lcdCommand(0x01);
  delay(5);

  // Entry Mode Set: Increment cursor, no display shift
  lcdCommand(0x06);
  delay(5);
}
