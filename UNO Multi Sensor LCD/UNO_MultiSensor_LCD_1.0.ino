

#include <LiquidCrystal.h>

//LiquidCrystal lcd(rs, e, d4, d5, d6, d7);
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
void setup()
{
  lcd.begin(30, 4);
}
void loop()
{

  int phRead=analogRead(A0);
  float phValue=(float)phRead*5/1024; 

  phValue=3.5*phValue;                      //convert the millivolt into pH value
  lcd.setCursor(0, 0);
  if(phValue<=8.5 && phValue>=5.5)
  {
    lcd.print("pH Value : ");
    lcd.println(phValue,2);
    lcd.println("The water is Drinkable.");
    delay(1000);
    lcd.clear(); 
  }
  else if(phValue<5.5 && phValue>=0)
  {
    lcd.print("pH Value : ");
    lcd.println(phValue,2);
    delay(1000);
    lcd.clear();
    
    lcd.println("The water is Acidic");
    delay(1000);
    lcd.clear();
    
    lcd.println("Harmful for drinking and fishes.");
    delay(1000);
    lcd.clear();
  }

    else if(phValue<=14 && phValue>8.5)
  {
    lcd.print("pH Value : ");
    lcd.println(phValue,2);
    delay(1000);
    lcd.clear();
    
    lcd.println("The water is alkali");
    delay(1000);
    lcd.clear();
    
    lcd.println("Harmful for drinking and fishes.");
    delay(1000);
    lcd.clear();

  }
  else
  {
    if(phValue>14)
    {
    phValue=14;
    lcd.print("pH Value : ");
    lcd.println(phValue,2);
    delay(1000);
    lcd.clear();

    
    lcd.println("The water is alkali");
    delay(1000);
    lcd.clear();
    
    lcd.println("Harmful for drinking and fishes.");
    delay(1000);
    lcd.clear();

    }
  }



  //
  //Temperature
int tempReading=analogRead(A1);
delay(30);
int temp= tempReading*4.88/10;
//  
    lcd.print("Temperature: ");
    lcd.print(temp);
    delay(1000);
    lcd.clear();

     if(temp<34)
    {
    lcd.println("Suitable Temp for water living creatures.");
    delay(1000);
    lcd.clear();
    }
    else
    {
    lcd.println("Temperature Not Suitable for water living creatures.");
    delay(1000);
    lcd.clear();
    }

//
//Turbidity
int turbidity=analogRead(A2);
delay(30);
turbidity=(turbidity*4.88/10)+1;


//
    lcd.print("Turbidity : ");
    lcd.println(turbidity);
    delay(1000);
    lcd.clear();

    if(turbidity>5)
    {
      lcd.println("Not Drinkable Turbidity!");
      delay(1000);
       lcd.clear();
    }
    else if(turbidity>=2 && turbidity<=5)
    {
      lcd.println("Drinkable Turbidity");
      delay(1000);
      lcd.clear();
    }
     else if(turbidity>=0 && turbidity<=1)
    {
      lcd.println("Very Much Drinkable Turbidity");
      delay(1000);
       lcd.clear();
    }
    else 
    {
      lcd.println("Not Drinkable Turbidity");
      delay(1000);
    lcd.clear();
    }
    lcd.clear();
    
    //Desolved Oxygen

    //Oxygen
int oxmeter=analogRead(A3);
delay(30);
oxmeter=oxmeter*4.88/10;

//
    
    lcd.print("Desolved Oxygen : ");
    lcd.println(oxmeter);
    delay(1000);
    lcd.clear();

    if(oxmeter>=6 && oxmeter<=9)
    {
      lcd.println("Suitable For Fish & Drinking DO");
      delay(1000);
    lcd.clear();
    }
    else if(oxmeter<6)
    {
      lcd.println("Not Suitable For Fish & Drinking DO!");
      delay(1000);
    lcd.clear();
    }
     else if(oxmeter>9)
    {
      lcd.println("Not Suitable For Fish & Drinking DO!");
      delay(1000);
    lcd.clear();
    }
    else 
    {
      lcd.println("Not Suitable For Fish & Drinking-DO!");
      delay(1000);
    lcd.clear();
    }
   lcd.clear();
  

}
