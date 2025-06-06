#include "DS18B20.h"
#include "OneWire.h"

#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);
DS18B20 sensor(&oneWire);


void setup(void)
{
  Serial.begin(115200);
  Serial.println(__FILE__);
  Serial.print("DS18B20 Library version: ");
  Serial.println(DS18B20_LIB_VERSION);

  sensor.begin();
}


void loop(void)
{ 
  sensor.requestTemperatures();
  
  while (!sensor.isConversionComplete());  // wait until sensor is ready
  
  Serial.print("Temp: ");
  Serial.println(sensor.getTempC());
}
