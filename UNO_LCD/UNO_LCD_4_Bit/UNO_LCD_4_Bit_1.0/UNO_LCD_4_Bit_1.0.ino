
// Pin definitions for 4-bit mode
#define RS 13  // Register Select pin
#define RW 12  // Read/Write pin
#define EN 11  // Enable pin
#define D4 6   // Data pins D4-D7
#define D5 5
#define D6 4
#define D7 3

// Custom character (8x5 pixels)
unsigned char specialChar[8] = { 
  0x00, 0x0A, 0x00, 0x00, 0x11, 0x0E, 0x00, 0x00
};

void setup() {
  Serial.begin(115200); // Leonardo: wait for serial port to connect
  // Set pins as OUTPUT
  pinMode(RS, OUTPUT);
  pinMode(RW, OUTPUT);
  pinMode(EN, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);

  // Initialize LCD in 4-bit mode
  lcdInit();

  // Load custom character into CGRAM
  lcdCommand(0x40);  // Set CGRAM Address
  for (int i = 0; i < 8; i++) {
    lcdData(specialChar[i]);
  }

  lcdCommand(0x80);  // Move cursor to home position
}


  // Write text on the LCD
void loop() {
  lcdCommand(0x80);  // First line, first column
  lcdPrint("    16x2 LCD");
  lcdCommand(0xC0);  // Second line, first column
  lcdPrint("   4 Bit Mode");   // Print the custom character
  lcdData(0x00);    // Display custom character stored in position 0
  delay(1000);      // Delay for visibility
}

// Function to send a command to the LCD
void lcdCommand(unsigned char command) {
  digitalWrite(RS, LOW);    // RS = 0 (command mode)
  digitalWrite(RW, LOW);    // RW = 0 (write mode)
  lcdWrite4Bits(command >> 4);  // Send higher nibble
  lcdWrite4Bits(command & 0x0F);  // Send lower nibble
  delay(5);                 // Command execution time
}

// Function to send data to the LCD
void lcdData(unsigned char data) {
  digitalWrite(RS, HIGH);     // RS = 1 (data mode)
  digitalWrite(RW, LOW);      // RW = 0 (write mode)
  lcdWrite4Bits(data >> 4);   // Send higher nibble
  lcdWrite4Bits(data & 0x0F); // Send lower nibble
  delay(5);                   // Data write time
}

// Function to write 4 bits to the LCD
void lcdWrite4Bits(unsigned char value) {
  digitalWrite(D4, (value >> 0) & 1);
  digitalWrite(D5, (value >> 1) & 1);
  digitalWrite(D6, (value >> 2) & 1);
  digitalWrite(D7, (value >> 3) & 1);

  // Latch data with Enable pulse
  digitalWrite(EN, HIGH);
  delayMicroseconds(1);
  digitalWrite(EN, LOW);
  delayMicroseconds(200);
}

// Function to print a string on the LCD
void lcdPrint(const char *str) {
  while (*str) {
    lcdData(*str++);  // Send each character
  }
}



// Function to initialize the LCD in 4-bit mode
void lcdInit() {
  delay(100);           // Wait for LCD power-up
  lcdWrite4Bits(0x03);  // Set 4-bit mode (special sequence)
  delay(5);
  lcdWrite4Bits(0x03);  // Set 4-bit mode (special sequence)
  delay(5);
  lcdWrite4Bits(0x03);  // Set 4-bit mode (special sequence)
  delay(5);
  lcdWrite4Bits(0x02);  // Set to 4-bit mode
  lcdCommand(0x28);     // Function Set: 4-bit mode, 2 lines, 5x8 font
  delay(5);
  lcdCommand(0x0C);     // Display ON, Cursor OFF, Blink OFF
  delay(5);
  lcdCommand(0x01);     // Clear Display
  delay(5);
  lcdCommand(0x06);     // Entry Mode Set: Increment cursor, no display shift
  delay(5);
}
