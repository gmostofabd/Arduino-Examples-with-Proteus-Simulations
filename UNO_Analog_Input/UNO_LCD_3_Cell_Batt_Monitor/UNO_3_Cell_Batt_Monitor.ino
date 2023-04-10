
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(57600);
  
  sbi(ADCSRA, ADPS2);    //Биту ADPS2 присваиваем единицу
  cbi(ADCSRA, ADPS1);    //Битам ADPS1 и ADPS0 присваиваем нули
  cbi(ADCSRA, ADPS0);

  // set up the LCD's number of columns and rows:
  lcd.begin(20, 4);
  // Print a message to the LCD.
  lcd.setCursor(0, 0);
  lcd.print("3 Cell Monitor");
  lcd.setCursor(0, 1);
  lcd.print("LCD Melab");
  lcd.setCursor(0, 2);
  lcd.print("3.3V 4092");
  delay(1000);
  lcd.clear();
}

void loop() {
  int b1Value = analogReadOversampled(0);
  int b2Value = analogReadOversampled(1);
  int b3Value = analogReadOversampled(2);

  /*
    //5V power
    float voltage_b1 = b1Value * (10.0 / 1023.0);
    float voltage_b2 = b2Value * (15.0 / 1023.0) - voltage_b1;
    float voltage_b3 = b3Value * (20.0 / 1023.0) - voltage_b2 - voltage_b1;
    float voltage_all = voltage_b1 + voltage_b2 + voltage_b3;
  */

  //3.3V power
  float voltage_b1 = b1Value * (6.6 / 4092.0); // 4092
  float voltage_b2 = b2Value * (9.9 / 4092.0) - voltage_b1;
  float voltage_b3 = b3Value * (13.2 / 4092.0) - voltage_b2 - voltage_b1;
  float voltage_all = voltage_b1 + voltage_b2 + voltage_b3;

  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
  lcd.print("Cel 1 = ");
  lcd.print(voltage_b1, 2);
  lcd.print(" V ");
  lcd.print(b1Value);
  lcd.print(" ");

  lcd.setCursor(0, 1);
  lcd.print("Cel 2 = ");
  lcd.print(voltage_b2, 2);
  lcd.print(" V ");
  lcd.print(b2Value);
  lcd.print(" ");

  lcd.setCursor(0, 2);
  lcd.print("Cel 3 = ");
  lcd.print(voltage_b3, 2);
  lcd.print(" V ");
  lcd.print(b3Value);
  lcd.print(" ");

  lcd.setCursor(0, 3);
  lcd.print("BATT = ");
  lcd.print(voltage_all, 3);
  lcd.print(" V ");


  Serial.print(b1Value);
  Serial.print(",");
  Serial.print(b2Value);
  Serial.print(",");
  Serial.print(b3Value);
  Serial.print(",");
  Serial.print(voltage_b1, 3);
  Serial.print(",");
  Serial.print(voltage_b2, 3);
  Serial.print(",");
  Serial.println(voltage_b3, 3);

  delay(10);
  //lcd.clear();
}

  unsigned int analogReadOversampled(byte analogChannel)  { // оверсемплинг, возвращает 12 битное значение 0...4092
  unsigned long aSum = 0;   // the sum of all analog readings
  for (unsigned int i = 256; i > 0; i--) {
    aSum = aSum + analogRead(analogChannel);
  }
  return aSum >> 6;
}
