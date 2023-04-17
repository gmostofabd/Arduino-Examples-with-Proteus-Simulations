#define Debug false
#define Ah_Button 8 
#define pinLED 13
#define WattAmpH_Conctant 0.1
#define Current_Constant 0.0 //0.029284455

float VoltCoef = 40.0 / 1024.0;
float CurrCoef = 15.0 / 1024.0;

#define RS 2
#define E 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7

#include <LiquidCrystal.h>

LiquidCrystal lcd(RS, E, D4, D5, D6, D7);

float Wh = 0.0; 
float Ah = 0.0;

unsigned long previousMillis = 0;
#define interval 100

boolean LCD_Ah = false; 

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);

  pinMode(Ah_Button, INPUT);
  pinMode(pinLED, OUTPUT);

  lcd.setCursor(0, 0);
  lcd.print("UNO Watt Meter");
  lcd.setCursor(0, 1);
  lcd.print("  By Melab-bd");
  delay(1000);
  lcd.clear();
}

void loop() {
  int CurrentValue = analogReadOversampled(0); // A0, ADC0, PC0
  int VoltageValue = analogReadOversampled(1); // A1, ADC1, PC1

  float Voltage =  VoltageValue * VoltCoef; // Max 40 Volt
  float Current = CurrentValue * CurrCoef - Current_Constant; // Max 15 Amp
  float Watt =  Voltage * Current;

  Ah = Ah + Current * 0.00000431987;
  Wh = Wh + Watt * 0.00000431987;

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    lcd.setCursor(0, 0);
    lcd.print(Voltage); lcd.print("V ");
    lcd.setCursor(8, 0);
    lcd.print(Watt); lcd.print("W  ");
    lcd.setCursor(0, 1);
    lcd.print(Current, 2); lcd.print("A ");
    lcd.setCursor(8, 1);

    if (LCD_Ah == 0) {

      if (Ah < 10.0) {
        lcd.print(Ah, 3);
      } else if (Ah < 100.0) {
        lcd.print(Ah, 2);
      } else if (Ah < 1000.0) {
        lcd.print(Ah, 1);
      }
      lcd.print("A/h  ");
    } else {
      if (Wh < 10.0) {
        lcd.print(Wh, 3);
      } else if (Wh < 100.0) {
        lcd.print(Wh, 2);
      } else if (Wh < 1000.0) {
        lcd.print(Wh, 1);
      }
      lcd.print("W/h  ");
    }

    if (Debug == 0) {
      Serial.print(Voltage, 3); Serial.print(" ");
      Serial.print(Current, 3); Serial.print(" ");
      Serial.print(Watt, 3); Serial.print(" ");
      Serial.print(Ah, 3); Serial.print(" ");
      Serial.println(Wh, 3);
    }
  }

}

int analogReadOversampled(byte analogChannel)  {
  unsigned long aSum = 0;   // the sum of all analog readings
  for (unsigned int i = 64; i > 0; i--) { // 8^x
    aSum = aSum + analogRead(analogChannel); // read and sum 256 ADС probes
  }
  return aSum >> 6;   
}
