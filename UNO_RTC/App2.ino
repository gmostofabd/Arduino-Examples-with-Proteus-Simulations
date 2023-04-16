#define slave_adress 0x68 // this to define slave adress

#include <Wire.h> // this to declare I2C librarry
#include<LiquidCrystal.h> // this to declare LCD library
byte sec_bcd=0, min_bcd=0, hour_bcd=0; // this declartion for BCd mode
byte sec_dec=0, min_dec=0, hour_dec=0; // this declaration for Decimal mode
const int rs=2, en=3, d4=4, d5=5, d6=6, d7=7;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
void setup() {
// put your setup code here, to run once:
Wire.begin();
lcd.begin(16,2);
lcd.print("RTC by DS1307");
}
void loop() {
// put your main code here, to run repeatedly:
Wire.beginTransmission(slave_adress); // adress Devide is specified in Ds1307
//datasheet
Wire.write(0x00);
Wire.endTransmission();

Wire.requestFrom(slave_adress,3);
sec_bcd=Wire.read(); // octet à lire pour les secondes (adresse 0x00)
min_bcd=Wire.read(); // octet à lire pour les minutes (adresse 0x01)
hour_bcd=Wire.read(); // octet à lire pour les heures (adresse 0x02)
Wire.endTransmission(); // fin de transmission
// Conversion BCD===> décimal
sec_dec=(sec_bcd & 0x0F)+((sec_bcd & 0xF0)>>4)*10;
min_dec=(min_bcd & 0x0F)+((min_bcd & 0xF0)>>4)*10;
hour_dec=(hour_bcd & 0x0F)+((hour_bcd & 0xF0)>>4)*10;
// Affichage sur l’afficheur LCD
lcd.setCursor(4,1);
lcd.print(hour_dec);
lcd.print(":");
lcd.print(min_dec);
lcd.print(":");
lcd.print(sec_dec);
delay(1000);
}
