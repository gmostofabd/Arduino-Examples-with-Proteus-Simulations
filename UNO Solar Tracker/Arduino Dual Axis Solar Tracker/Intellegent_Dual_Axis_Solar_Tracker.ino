#include <Wire.h>
#include <Adafruit_INA219.h>
#include <LiquidCrystal.h>
#include <Servo.h>

// --- Servo setup ---
Servo horizontal;   // X-axis
Servo vertical;     // Y-axis

int servoh = 90;    // start pos
int servov = 90;

// Servo limits
int servohLimitHigh = 175;
int servohLimitLow  = 5;
int servovLimitHigh = 175;
int servovLimitLow  = 5;

// --- LDR pins ---
int ldrlt = A3; // top left
int ldrrt = A2; // top right
int ldrld = A0; // bottom left
int ldrrd = A1; // bottom right

// --- Voltage sensing (A4 with divider) ---
//int voltPin = A4;
float panelVoltage = 0.0;

// Voltage divider resistors (adjust as per your circuit)
float R1 = 10000.0; // 10k
float R2 = 10000.0; // 10k

// --- INA219 current sensor ---
Adafruit_INA219 ina219;
float panelCurrent = 0.0;

// --- LCD (RS, E, D4, D5, D6, D7) ---
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup() {
  // Attach servos
  horizontal.attach(9);
  vertical.attach(10);
  horizontal.write(servoh);
  vertical.write(servov);

  // LCD setup
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print(" SMART SOLAR ");
  lcd.setCursor(0, 1);
  lcd.print("  TRACKER");
  delay(2000);
  lcd.clear();

  // Serial monitor
  Serial.begin(9600);

  // INA219 init
  if (!ina219.begin()) {
    Serial.println("Failed to find INA219 chip");
    while (1) { delay(10); }
  }
  ina219.setCalibration_32V_2A(); // suitable calibration
}

void loop() {
  // --- Track sun using LDRs ---
  int lt = analogRead(ldrlt); 
  int rt = analogRead(ldrrt); 
  int ld = analogRead(ldrld); 
  int rd = analogRead(ldrrd); 

  int avt = (lt + rt) / 2; // avg top
  int avd = (ld + rd) / 2; // avg bottom
  int avl = (lt + ld) / 2; // avg left
  int avr = (rt + rd) / 2; // avg right

  int dvert = avt - avd;
  int dhoriz = avl - avr;
  int tol = 50; // sensitivity

  // Vertical movement
  if (abs(dvert) > tol) {
    if (avt > avd) servov++;
    else servov--;

    if (servov > servovLimitHigh) servov = servovLimitHigh;
    if (servov < servovLimitLow)  servov = servovLimitLow;

    vertical.write(servov);
  }

  // Horizontal movement
  if (abs(dhoriz) > tol) {
    if (avl > avr) servoh--;
    else servoh++;

    if (servoh > servohLimitHigh) servoh = servohLimitHigh;
    if (servoh < servohLimitLow)  servoh = servohLimitLow;

    horizontal.write(servoh);
  }

  // --- Read panel voltage ---
  //int rawADC = analogRead(voltPin);
  //float vout = (rawADC * 5.0) / 1023.0;
  //panelVoltage = vout * ((R1 + R2) / R2);

  // --- Read panel current ---
  panelCurrent = ina219.getCurrent_mA() / 1000.0; // A

  // --- Display on LCD ---
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("V:");
  lcd.print(panelVoltage, 2);
  lcd.print(" I:");
  lcd.print(panelCurrent, 2);

  lcd.setCursor(0, 1);
  lcd.print("H:");
  lcd.print(servoh);
  lcd.print(" V:");
  lcd.print(servov);

  // --- Debug Serial ---
  Serial.print("Voltage: "); Serial.print(panelVoltage, 2); Serial.println(" V");
  Serial.print("Current: "); Serial.print(panelCurrent, 2); Serial.println(" A");
  Serial.print("Servo H: "); Serial.print(servoh);
  Serial.print(" Servo V: "); Serial.println(servov);

  delay(500);
}
