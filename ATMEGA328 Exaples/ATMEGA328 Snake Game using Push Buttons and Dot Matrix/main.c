
/*  <<---------------------------------------------- This is the main code of the project ------------------------------------------->>  */


#define F_CPU 8000000UL           // MCU clock
#include <avr/io.h>               // set up I/O s
#include <util/delay.h>           // adding delays
#include <avr/interrupt.h>        // adding  interrupts

#include "Displayings.h"          // Add-up created library for all displayings
#include "Movements.h"            // Add-up created library for all movements


#define SWITCH1_PRESSED !(PINC &(1<<PINC0))    // Up button
#define SWITCH2_PRESSED !(PINC &(1<<PINC1))    // Down button
#define SWITCH3_PRESSED !(PINC &(1<<PINC2))    // Right button
#define SWITCH4_PRESSED !(PINC &(1<<PINC3))    // Left button

int main(void)
{
	Cx = 4;                        // Starting X axis point of the snake
	Cy = 3;                        // Starting Y axis point of the snake
	
	DDRD |=(1<<DDD6);              //  LED that used to Check the system
	
	DDRC &= ~(1<<DDC0);            // Up button
	DDRC &= ~(1<<DDC1);            // Down button
	DDRC &= ~(1<<DDC2);            // Right button
	DDRC &= ~(1<<DDC3);            // Left button
	
	
	PCICR |= (1 << PCIE0);         // Checking button interrupts are happenings
	
	/* ......................Four buttons interrupts..........................*/
	PCMSK0 |= (1 << PCINT8);
	PCMSK0 |= (1 << PCINT9);
	PCMSK0 |= (1 << PCINT10);
	PCMSK0 |= (1 << PCINT11);
	
	USART_Init();                        // Connection library starts
    MAX7219_init();                      // LED matrix library starts
	MAX7219_init_7SEG();                 // 7 segment library starts
	MAX7219_set_intensity_7SEG(10);      // setting 7 segment display intensity
	
	FDscore();                       // Starting the scoring function to show the numbers.
	
	PORTD |=(1<<PORTD6);             // Checking LED ON
	_delay_ms(300);
	
	snake();                         // Show game name array
	ShowGO();                        // Set-up Go array
	PORTD &= (~(1<<PORTD6));        // Checking LED OFF
	_delay_ms(300);
	
	foodSpawn();                    // Adding food for first-time
	sei();	                        // For Interrupts....
	    
	while (END != 1)                // Continue the system
    {   
		move(dir);                 // Main snake movement function  		
		isFoodEaten();             // Finding the status of current food and  
	
	}
}

// Interruption handling that used by the buttons.......
ISR(PCINT0_vect)
{
	if (SWITCH1_PRESSED) // up button
	{
		dir=0;  // go up
	}
	if (SWITCH2_PRESSED) // down button
	{
		dir=1;	// go down
	}
	if (SWITCH3_PRESSED) // right button
	{
		dir=2;   // go right
	}
	if (SWITCH4_PRESSED) // left button
	{
		dir=3;   // go left
	}
}