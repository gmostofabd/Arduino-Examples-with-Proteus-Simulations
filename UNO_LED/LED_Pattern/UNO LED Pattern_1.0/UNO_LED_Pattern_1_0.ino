void setup()
{
  int i;
  // Configure digital pins 0 to 7 as output pins
  for (i = 0; i < 8; i++)
  {
    pinMode(i, OUTPUT);
  }
}

void loop()
{
  int i;
  while (1) // Infinite loop
  {
    // Forward LED pattern sequence
    for (i = 0; i < 1; i++)
    {
      PORTD = 129; // Turn on LEDs at pins 0 and 7
      delay(500);  // Wait for 500 milliseconds

      PORTD = 66;  // Turn on LEDs at pins 1 and 6
      delay(500);  // Wait for 500 milliseconds

      PORTD = 36;  // Turn on LEDs at pins 2 and 5
      delay(500);  // Wait for 500 milliseconds

      PORTD = 24;  // Turn on LEDs at pins 3 and 4
      delay(500);  // Wait for 500 milliseconds
    }

    // Reverse LED pattern sequence
    for (i = 0; i < 1; i++)
    {
      PORTD = 36;  // Turn on LEDs at pins 2 and 5
      delay(500);  // Wait for 500 milliseconds

      PORTD = 66;  // Turn on LEDs at pins 1 and 6
      delay(500);  // Wait for 500 milliseconds

      PORTD = 129; // Turn on LEDs at pins 0 and 7
      delay(500);  // Wait for 500 milliseconds
    }
  }
}
