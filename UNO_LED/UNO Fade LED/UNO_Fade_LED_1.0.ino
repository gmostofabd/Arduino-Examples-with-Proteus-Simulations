// Define the pin number for the LED
int LED = 10;

void setup() 
{
    // Set the LED pin as an output
    pinMode(LED, OUTPUT);
}

void loop() 
{
    // Gradually increase the brightness of the LED
    for(int i = 0; i < 256; i += 20) // Increment brightness in steps of 20
    {
        analogWrite(LED, i); // Set the LED brightness (PWM signal)
        delay(30); // Wait 30 milliseconds before the next step
    }
    
    // Gradually decrease the brightness of the LED
    for(int j = 255; j > 1; j -= 20) // Decrement brightness in steps of 20
    {
        analogWrite(LED, j); // Set the LED brightness (PWM signal)
        delay(30); // Wait 30 milliseconds before the next step
    }
}
