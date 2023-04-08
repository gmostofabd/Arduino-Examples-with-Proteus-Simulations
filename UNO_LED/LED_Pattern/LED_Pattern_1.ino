
void setup()
{
  int i;
  for(i=0;i<8;i++)
  {
  pinMode(i,OUTPUT);
  }
}
void loop()
{
  int i;
  while(1)
  {
    for(i=0;i<1;i++)
    {
      PORTD=129;
      delay(500);
       PORTD=66;
      delay(500);
       PORTD=36;
      delay(500);
       PORTD=24;
      delay(500);
    }
    for(i=0;i<1;i++)
    {
       PORTD=36;
      delay(500);
       PORTD=66;
      delay(500);
       PORTD=129;
      delay(500);
    }
  }
}
