#include <Arduino.h>
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

class Logging {

  public:
  
    void ConditionLogging(SoftwareSerial Terminal, LiquidCrystal LcdDisplay,
      int PhotoResistor, String LampCondition) {

      String LogMessage = (
        "{ 'photoresistor' : " + String(PhotoResistor) + ", " +
        "'lamp_condition' : '"  + String(LampCondition) + "' }"
      );
      
      Terminal.println(LogMessage);

      LcdDisplay.print("Hasil : ");
      LcdDisplay.setCursor(0, 1);
      LcdDisplay.println("\t" + LampCondition + " \t\t");
      
    }

};