#define RELAY  A5                      

void setup()
{    
  pinMode(RELAY, OUTPUT);       
}

void loop()
{
  digitalWrite(RELAY,HIGH);           // Turns Relay On
  delay(500); 
  digitalWrite(RELAY,LOW);          // Turns Relay Off
  delay(500); 
}



