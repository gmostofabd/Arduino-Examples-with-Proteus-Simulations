#include <Arduino.h>
#include "Font_Header.h"
#include <avr/pgmspace.h>

// Pin definitions
#define RS 2
#define RW LOW   // tied to GND
#define EN 4
#define CS1 A0
#define CS2 A1
#define RST A2

uint8_t dataPins[8] = {12,11,10,9,8,7,6,5};
#define TotalPage 8

// --- Low-level helpers ---
void pulseEN() {
  digitalWrite(EN,HIGH);
  delayMicroseconds(10);
  digitalWrite(EN,LOW);
  delayMicroseconds(5);
}

void GLCD_Command(uint8_t cmd, bool left) {
  digitalWrite(CS1,left?LOW:HIGH);
  digitalWrite(CS2,left?HIGH:LOW);
  digitalWrite(RS,LOW);
  for(int i=0;i<8;i++) digitalWrite(dataPins[i], (cmd>>i)&1);
  pulseEN();
}

void GLCD_Data(uint8_t dat, bool left) {
  digitalWrite(CS1,left?LOW:HIGH);
  digitalWrite(CS2,left?HIGH:LOW);
  digitalWrite(RS,HIGH);
  for(int i=0;i<8;i++) digitalWrite(dataPins[i], (dat>>i)&1);
  pulseEN();
}

// --- Initialization ---
void GLCD_Init() {
  pinMode(RS,OUTPUT);
  pinMode(EN,OUTPUT);
  pinMode(CS1,OUTPUT);
  pinMode(CS2,OUTPUT);
  pinMode(RST,OUTPUT);
  for(int i=0;i<8;i++) pinMode(dataPins[i],OUTPUT);

  digitalWrite(RST,LOW); delay(10);
  digitalWrite(RST,HIGH); delay(10);

  // Turn off, set addresses, turn on
  GLCD_Command(0x3E,true);  GLCD_Command(0x40,true);  GLCD_Command(0xB8,true);  GLCD_Command(0xC0,true);  GLCD_Command(0x3F,true);
  GLCD_Command(0x3E,false); GLCD_Command(0x40,false); GLCD_Command(0xB8,false); GLCD_Command(0xC0,false); GLCD_Command(0x3F,false);
}

// --- Clear GLCD ---
void GLCD_ClearAll() {
  for(int page=0; page<TotalPage; page++){
    for(int col=0; col<64; col++){
      GLCD_Command(0xB8+page,true);  GLCD_Command(0x40+col,true);  GLCD_Data(0,true);
      GLCD_Command(0xB8+page,false); GLCD_Command(0x40+col,false); GLCD_Data(0,false);
    }
  }
}

// --- Map character to font index ---
uint8_t charIndex(char c){
  switch(c){
    case 'H': return 0;
    case 'E': return 1;
    case 'L': return 2;
    case 'O': return 3;
    case 'W': return 4;
    case 'R': return 5;
    case 'D': return 6;
    case ' ': return 0;
    default: return 0;
  }
}

// --- Draw 5x8 char at x,page ---
void drawChar(uint8_t x, uint8_t page, char c){
  uint8_t idx = charIndex(c);
  for(int i=0;i<FontWidth;i++){
    uint8_t col = x+i;
    if(col>127) break;
    bool left = col<64;
    GLCD_Command(0xB8+page,left);
    GLCD_Command(0x40+(col%64),left);
    GLCD_Data(font[idx][i],left);
  }
}

// --- Draw string at page 0..7 ---
void drawString(uint8_t x, uint8_t page, const char* s){
  while(*s){
    drawChar(x,page,*s);
    x+=FontWidth+1;
    s++;
  }
}

// --- Simple vertical line animation ---
void runAnimation(){
  for(int x=0;x<128;x++){
    for(int page=0; page<8; page++){
      bool left = x<64;
      GLCD_Command(0xB8+page,left);
      GLCD_Command(0x40+(x%64),left);
      if(page==3) GLCD_Data(0xFF,left);
      else GLCD_Data(0x00,left);
    }
    delay(20);
  }
}

void setup() {
  GLCD_Init();
  GLCD_ClearAll();
  drawString(10,2,"HELLO WORLD");
  delay(2000);
  GLCD_ClearAll();
}

void loop() {
  runAnimation();
}
