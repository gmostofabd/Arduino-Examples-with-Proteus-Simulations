#include "DHT.h"

#define DHTPIN 8     // what pin we're connected to
// include the library code:
#include <LiquidCrystal.h>

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11 
//#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

// Connect pin 1 (on the left) of the sensor to +5V
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); 
  Serial.println("DHTxx test!");
 lcd.begin(16, 2);
  dht.begin();
}

void loop() {
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // check if returns are valid, if they are NaN (not a number) then something went wrong!
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
  } else {
 
  lcd.setCursor(0,0);
  lcd.print("Temp. =");
  lcd.print(t);
  lcd.print(" *C");
  lcd.setCursor(0,1);
  lcd.print("Hum% =");
  lcd.print(h);
  lcd.print("% ");
  delay(500);
 
    Serial.print("Hum%: "); 
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temp.: "); 
    Serial.print(t);
    Serial.println(" *C");
  }
}
