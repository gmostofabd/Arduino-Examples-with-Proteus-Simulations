
// Pin definitions for 4-bit mode
#define RS 12  // Register Select pin
//#define RW 12  // Read/Write pin
#define EN 11  // Enable pin
#define D4 6   // Data pins D4-D7
#define D5 5
#define D6 4
#define D7 3

#define SW1 A0
#define SW2 A1
#define SW3 A2
#define SW4 A3


// Custom character (8x5 pixels)
unsigned char specialChar[8] = { 
  0x00, 0x0A, 0x00, 0x00, 0x11, 0x0E, 0x00, 0x00
};

void setup() {

  
    // Set pins as OUTPUT
  pinMode(RS, OUTPUT);
//  pinMode(RW, OUTPUT);
  pinMode(EN, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);

  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);

  // Initialize LCD in 4-bit mode
  lcdInit();
 lcdCommand(0x01);

  Serial.begin(9600);
  Serial.println("Enter Alpha-numeric Data:");

}


  // Write text on the LCD
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
  lcdCommand(0x81);
  lcdPrintString("Received String: ");
  lcdCommand(0xC1);
  for(i=0;i<charLength;i++){
    lcdPrint(data[i]); 
  }
  
  //Serial.println(data);
Serial.println(data); // Print the ASCII value


}















// Function to send a command to the LCD
void lcdCommand(unsigned char command) {
  digitalWrite(RS, LOW);    // RS = 0 (command mode)
//  digitalWrite(RW, LOW);    // RW = 0 (write mode)
  lcdWrite4Bits(command >> 4);  // Send higher nibble
  lcdWrite4Bits(command & 0x0F);  // Send lower nibble
  delay(5);                 // Command execution time
}

// Function to send data to the LCD
void lcdData(unsigned char data) {
  digitalWrite(RS, HIGH);     // RS = 1 (data mode)
//  digitalWrite(RW, LOW);      // RW = 0 (write mode)
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
void lcdPrintString(const char *str) {
  while (*str) {
    lcdData(*str++);  // Send each character
  }
}

// Function to print a string on the LCD
void lcdPrint(int value) {

  char buffer[10];          // Buffer to hold the converted integer
  itoa(value, buffer, 10);  // Convert integer to string (base 10)
  lcdPrintString(buffer);         // Print the string using lcdPrint

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












void display2lcd(char p){
   lcdCommand(0x01);
lcdCommand(0x80);

  if(p == '1'){
    lcdPrintString("Switch 1 Pressed");
    for(int i=0; i<10; i++){
      lcdCommand(0xC4);
      lcdPrint(i);
      delay(200);
    }
  }
  else if(p == '2'){
    lcdPrintString("Switch 2 Pressed");
    for(int i=0; i<100; i++){
      lcdCommand(0xC4);
      lcdPrint(i);
      delay(200);
    }
  }
  else if(p == '3'){
    lcdPrintString("Switch 3 Pressed");
    for(int i=0; i<1000; i++){
      lcdCommand(0xC4);
      lcdPrint(i);
      delay(200);
    }
  }  
  else {
    lcdPrintString("Switch 4 Pressed");
    for(int i=0; i<10000; i++){
      lcdCommand(0xC4);
      lcdPrint(i);
      delay(200);
    }
  }
  lcdCommand(0x01);
}











