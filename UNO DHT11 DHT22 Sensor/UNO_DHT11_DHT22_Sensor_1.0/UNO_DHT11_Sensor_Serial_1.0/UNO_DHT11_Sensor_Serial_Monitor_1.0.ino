#include <DHT.h>

// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
int pinDHT11 = 2;
DHT11 dht11(pinDHT11);

void setup() {
  Serial.println("Temperature and Humidity Data");
  Serial.begin(9600);
}

void loop() {
  // start working...

  delay(250);
  
  // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  int err = DHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != DHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.print(SimpleDHTErrCode(err));
    Serial.print(","); Serial.println(SimpleDHTErrDuration(err)); delay(1000);
    return;
  }
  
  Serial.print("Sample OK: ");
  Serial.print((int)temperature); Serial.print(" *C, "); 
  Serial.print((int)humidity); Serial.println(" H");
  
  // DHT11 sampling rate is 1HZ.
  delay(1500);
}
