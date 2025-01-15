#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

#include "Logging.h"
#include "LampLogic.h"

// Lamp Pin & Photoresistor / LDR (analog) Pin
#define LAMP_PIN 13
#define LDR_PIN  A0

// Virtual Terminal Pins
#define RXD_PIN 10
#define TXD_PIN 9

SoftwareSerial Terminal(  
  TXD_PIN, RXD_PIN
);

// LCD Display Pins
#define RS_PIN 12
#define EN_PIN 11
#define D4_PIN 5
#define D5_PIN 4
#define D6_PIN 3
#define D7_PIN 2

LiquidCrystal LcdDisplay(
  RS_PIN, EN_PIN,
  D4_PIN, D5_PIN,
  D6_PIN, D7_PIN
);

// Baud Rate
#define BAUD_RATE 9600

void setup() {
  pinMode(LAMP_PIN, OUTPUT);
  
  Serial.begin(BAUD_RATE);
  Terminal.begin(BAUD_RATE);
  LcdDisplay.begin(16, 2);
}

void loop() {
  
  Logging Log;
  LampLogic lampLogic;

  int PhotoResistor = analogRead(LDR_PIN);
  ResultLogic LampLogicResult = lampLogic.Logic(PhotoResistor);
  
  analogWrite(LAMP_PIN, LampLogicResult.Brightness);

  Log.ConditionLogging(Terminal, LcdDisplay,
    PhotoResistor, LampLogicResult.LampCondition
  );
  
}