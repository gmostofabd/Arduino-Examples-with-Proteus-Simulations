// include the library code:
#include <LiquidCrystal.h> //library for LCD 

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

const int RedlED = 5;
const int GreenlED = 6;
const int Buzzer = 7;

int count = 0;
char c;
String id;

int wait = 5000;

void setup()
{
  Serial.begin(9600);
  pinMode(RedlED, OUTPUT);
  pinMode(GreenlED, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  Serial.println("Please scan your RFID Card");

  lcd.begin(20, 4); // set up the LCD's number of columns and rows:
  lcd.setCursor(0, 0);
  lcd.print("_____SMART HOME____ ");
  lcd.setCursor(0, 1);
  lcd.print(" RFID BASED LOCK SYS");
  lcd.setCursor(0, 2);
  lcd.print(" CARD:   ");
  lcd.setCursor(0, 3);
  lcd.print(" NAME:   ");
}

void loop()
{
  while (Serial.available() > 0)
  {
    c = Serial.read();
    count++;
    id += c;
    if (count == 12)
    {
      Serial.print(id);
      //break;

      if (id == "E280689401A9")
      {
        Serial.println("Valid Card");
        lcd.setCursor(0, 2);
        lcd.print(" CARD: VALID   ");
        lcd.setCursor(0, 3);
        lcd.print(" NAME: ALTAF   ");
        digitalWrite(GreenlED, HIGH);
        delay(wait);
        digitalWrite(GreenlED, LOW);
        lcd.setCursor(0, 2);
        lcd.print(" CARD:           ");
        lcd.setCursor(0, 3);
        lcd.print(" NAME:           ");
      }

      else if (id == "E2000019060C")
      {
        Serial.println("Valid Card");
        lcd.setCursor(0, 2);
        lcd.print(" CARD: VALID   ");
        lcd.setCursor(0, 3);
        lcd.print(" NAME: ZUBAIR   ");
        digitalWrite(GreenlED, HIGH);
        delay(wait);
        digitalWrite(GreenlED, LOW);
        lcd.setCursor(0, 2);
        lcd.print(" CARD:           ");
        lcd.setCursor(0, 3);
        lcd.print(" NAME:           ");
      }

      else if (id == "G46RD9V40F3A")
      {
        Serial.println("Valid Card");
        lcd.setCursor(0, 2);
        lcd.print(" CARD: VALID   ");
        lcd.setCursor(0, 3);
        lcd.print(" NAME: AMIR   ");
        digitalWrite(GreenlED, HIGH);
        delay(wait);
        digitalWrite(GreenlED, LOW);
        lcd.setCursor(0, 2);
        lcd.print(" CARD:           ");
        lcd.setCursor(0, 3);
        lcd.print(" NAME:           ");
      }

      else if (id == "B71001B76894")
      {
        Serial.println("Valid Card");
        lcd.setCursor(0, 2);
        lcd.print(" CARD: VALID   ");
        lcd.setCursor(0, 3);
        lcd.print(" NAME: KHALID   ");
        digitalWrite(GreenlED, HIGH);
        delay(wait);
        digitalWrite(GreenlED, LOW);
        lcd.setCursor(0, 2);
        lcd.print(" CARD:           ");
        lcd.setCursor(0, 3);
        lcd.print(" NAME:           ");
      }

      else if (id == "1C81159073FD")
      {
        Serial.println("Valid Card");
        lcd.setCursor(0, 2);
        lcd.print(" CARD: VALID   ");
        lcd.setCursor(0, 3);
        lcd.print(" NAME: IMRAN   ");
        digitalWrite(GreenlED, HIGH);
        delay(wait);
        digitalWrite(GreenlED, LOW);
        lcd.setCursor(0, 2);
        lcd.print(" CARD:           ");
        lcd.setCursor(0, 3);
        lcd.print(" NAME:           ");
      }

      else if (id == "B710D0186022")
      {
        Serial.println("Valid Card");
        lcd.setCursor(0, 2);
        lcd.print(" CARD: VALID   ");
        lcd.setCursor(0, 3);
        lcd.print(" NAME: MEHRAN   ");
        digitalWrite(GreenlED, HIGH);
        delay(wait);
        digitalWrite(GreenlED, LOW);
        lcd.setCursor(0, 2);
        lcd.print(" CARD:           ");
        lcd.setCursor(0, 3);
        lcd.print(" NAME:           ");
      }

      else
      {
        Serial.println("Invalid Card");
        lcd.setCursor(0, 2);
        lcd.print(" CARD: INVALID   ");
        lcd.setCursor(0, 3);
        lcd.print(" NAME: UNKNOWN     ");
        digitalWrite(RedlED, HIGH);
        digitalWrite(Buzzer, HIGH);
        delay(500);
        digitalWrite(Buzzer, LOW);
        delay(4000);
        digitalWrite(RedlED, LOW);
        lcd.setCursor(0, 2);
        lcd.print(" CARD:           ");
        lcd.setCursor(0, 3);
        lcd.print(" NAME:           ");
      }
    }
  }
  count = 0;
  id = "";
  delay(500);
}
