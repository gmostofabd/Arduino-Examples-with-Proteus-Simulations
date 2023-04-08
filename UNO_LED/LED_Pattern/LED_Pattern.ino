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

  int i,x,j;
  while(1)
  {

    //////////////////////////////////////////  1 led toggle  //////////////////////
    for(j=0;j<3;j++)
    { 
      digitalWrite(0,HIGH);
      delay(500);
      digitalWrite(0,LOW);
      delay(500);
    }
    /////////////////////////////////// 8 led toggle /////////////////////////////////////
    for(j=0;j<3;j++)
    { 
      PORTD=0xff;
      delay(500);
      PORTD=0x00;
      delay(500);
    }
    //////////////////////////////////////// 4 led on off /////////////////////////////// 
    for(j=0;j<3;j++)
    {   
      PORTD=0x0f;
      delay(500);
      PORTD=0xf0;
      delay(500);
    }
    //////////////////////////////////  alternate led pattern  //////////////////////////
    for(j=0;j<3;j++)
    { 
      PORTD=0x55;
      delay(500);
      PORTD=0xaa;
      delay(500);
    }
    //////////////////////////  left side pattern  ////////////////////////////////
    for(j=0;j<3;j++)
    {
      x=1;
      for(i=0;i<8;i++)
      {
        PORTD=x;
        delay(500);
        x=x<<1;
      }
    }
    //////////////////////////////  right side pattern  ///////////////////////////// 
    for(j=0;j<3;j++)
    {
      x=128;
      for(i=0;i<8;i++)
      {
        PORTD=x;
        delay(500);
        x=x>>1;
      }
    } 

    ///////////////////  left and right side pattern  //////////////////// 
    for(j=0;j<3;j++)
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
    ///////////////////////////////////////////////////////////////////////////

    PORTD=0x00;
  }
}
