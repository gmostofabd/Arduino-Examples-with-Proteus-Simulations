

/*  <<---------------------------------------------------This is the library that has commonds to set display things------------------------------------------------------------->>  */



#include "max7219.h"           // Library that used to drive the LED matrix
#include "7seg_max7219.h"      // Library that used to drive the 7 segments display

int px =0;           // variable position for "GO -->"

int END = 0;         // Make the game stop

int score = 0;       // starting score

//---------------------------------------------------- Setting words to matrix display--------------------------------------

void gameOver()              // displaying game over
{                    
	//For G
	MAX7219_set_row(1,0b01111100);
	MAX7219_set_row(2,0b01000000);
	MAX7219_set_row(3,0b01000000);
	MAX7219_set_row(4,0b01011100);
	MAX7219_set_row(5,0b01000100);
	MAX7219_set_row(6,0b01000100);
	MAX7219_set_row(7,0b01111100);
	_delay_ms(500);
	MAX7219_clear();
	
	// For A...
	MAX7219_set_row(1,0b01111100);
	MAX7219_set_row(2,0b01000100);
	MAX7219_set_row(3,0b01000100);
	MAX7219_set_row(4,0b01111100);
	MAX7219_set_row(5,0b01000100);
	MAX7219_set_row(6,0b01000100);
	MAX7219_set_row(7,0b01000100);
	_delay_ms(500);
	MAX7219_clear();
	
	//For M
	MAX7219_set_row(1,0b01000100);
	MAX7219_set_row(2,0b01101100);
	MAX7219_set_row(3,0b01111100);
	MAX7219_set_row(4,0b01010100);
	MAX7219_set_row(5,0b01000100);
	MAX7219_set_row(6,0b01000100);
	MAX7219_set_row(7,0b01000100);
	_delay_ms(500);
	MAX7219_clear();
	
	// For E...
	MAX7219_set_row(1,0b01111100);
	MAX7219_set_row(2,0b01000000);
	MAX7219_set_row(3,0b01000000);
	MAX7219_set_row(4,0b01111100);
	MAX7219_set_row(5,0b01000000);
	MAX7219_set_row(6,0b01000000);
	MAX7219_set_row(7,0b01111100);
	_delay_ms(500);
	MAX7219_clear();
	
	//For O
	MAX7219_set_column(6,0b11111110);
	MAX7219_set_column(5,0b11111110);
	MAX7219_set_column(4,0b10000010);
	MAX7219_set_column(3,0b11111110);
	MAX7219_set_column(2,0b11111110);
	
	_delay_ms(500);
	MAX7219_clear();
	
	//For V
	MAX7219_set_column(6,0b01111110);
	MAX7219_set_column(5,0b11100000);
	MAX7219_set_column(4,0b11000000);
	MAX7219_set_column(3,0b11100000);
	MAX7219_set_column(2,0b01111110);
	
	_delay_ms(500);
	MAX7219_clear();
	
	// For E...
	MAX7219_set_row(1,0b01111100);
	MAX7219_set_row(2,0b01000000);
	MAX7219_set_row(3,0b01000000);
	MAX7219_set_row(4,0b01111100);
	MAX7219_set_row(5,0b01000000);
	MAX7219_set_row(6,0b01000000);
	MAX7219_set_row(7,0b01111100);
	_delay_ms(500);
	MAX7219_clear();
	
	//For R
	MAX7219_set_row(1,0b01111100);
	MAX7219_set_row(2,0b01000100);
	MAX7219_set_row(3,0b01000100);
	MAX7219_set_row(4,0b01111100);
	MAX7219_set_row(5,0b01110000);
	MAX7219_set_row(6,0b01011000);
	MAX7219_set_row(7,0b01001100);
	
	_delay_ms(500);
	MAX7219_clear();
	MAX7219_clear_7SEG();
	
	END=1; // Ending the game
	
	
}           

void snake()                 // displaying name of the game
{
	// For S...
	MAX7219_set_row(1,0b01111100);
	MAX7219_set_row(2,0b01000000);
	MAX7219_set_row(3,0b01000000);
	MAX7219_set_row(4,0b01111100);
	MAX7219_set_row(5,0b00000100);
	MAX7219_set_row(6,0b00000100);
	MAX7219_set_row(7,0b01111100);
	_delay_ms(500);
	MAX7219_clear();
	
	// For N...
	MAX7219_set_row(1,0b01100100);
	MAX7219_set_row(2,0b01100100);
	MAX7219_set_row(3,0b01110100);
	MAX7219_set_row(4,0b01010100);
	MAX7219_set_row(5,0b01011100);
	MAX7219_set_row(6,0b01001100);
	MAX7219_set_row(7,0b01001100);
	_delay_ms(500);
	MAX7219_clear();
	
	// For A...
	MAX7219_set_row(1,0b01111100);
	MAX7219_set_row(2,0b01000100);
	MAX7219_set_row(3,0b01000100);
	MAX7219_set_row(4,0b01111100);
	MAX7219_set_row(5,0b01000100);
	MAX7219_set_row(6,0b01000100);
	MAX7219_set_row(7,0b01000100);
	_delay_ms(500);
	MAX7219_clear();
	
	// For K...
	MAX7219_set_row(1,0b01001100);
	MAX7219_set_row(2,0b01011000);
	MAX7219_set_row(3,0b01110000);
	MAX7219_set_row(4,0b01100000);
	MAX7219_set_row(5,0b01110000);
	MAX7219_set_row(6,0b01011000);
	MAX7219_set_row(7,0b01001100);
	_delay_ms(500);
	MAX7219_clear();
	
	// For E...
	MAX7219_set_row(1,0b01111100);
	MAX7219_set_row(2,0b01000000);
	MAX7219_set_row(3,0b01000000);
	MAX7219_set_row(4,0b01111100);
	MAX7219_set_row(5,0b01000000);
	MAX7219_set_row(6,0b01000000);
	MAX7219_set_row(7,0b01111100);
	_delay_ms(500);
	MAX7219_clear();
	
	// For 1 ....
	MAX7219_set_column(1,0b10000000);
	MAX7219_set_column(2,0b10000000);
	MAX7219_set_column(3,0b11111110);
	MAX7219_set_column(4,0b10000010);
	MAX7219_set_column(5,0b10000010);
	_delay_ms(500);
	MAX7219_clear();
	
	// For 2.....
	MAX7219_set_column(2,0b10011110);
	MAX7219_set_column(3,0b10010010);
	MAX7219_set_column(4,0b10010010);
	MAX7219_set_column(5,0b11110010);
	_delay_ms(500);
	
	MAX7219_clear();
	
	// For 3.....
	MAX7219_set_column(2,0b11111110);
	MAX7219_set_column(3,0b10010010);
	MAX7219_set_column(4,0b10010010);
	MAX7219_set_column(5,0b10010010);
	_delay_ms(500);
	
	MAX7219_clear();
	
	
}

void yoUwin()                // displaying "You Win"
{
	// For Y...
	MAX7219_set_row(1,0b01000100);
	MAX7219_set_row(2,0b01000100);
	MAX7219_set_row(3,0b01000100);
	MAX7219_set_row(4,0b01111100);
	MAX7219_set_row(5,0b00010000);
	MAX7219_set_row(6,0b00010000);
	MAX7219_set_row(7,0b00010000);
	_delay_ms(500);
	MAX7219_clear();
	
	// For O...
	MAX7219_set_column(6,0b11111110);
	MAX7219_set_column(5,0b11111110);
	MAX7219_set_column(4,0b10000010);
	MAX7219_set_column(3,0b11111110);
	MAX7219_set_column(2,0b11111110);
	_delay_ms(500);
	MAX7219_clear();
	
	// For U...
	MAX7219_set_row(1,0b01000100);
	MAX7219_set_row(2,0b01000100);
	MAX7219_set_row(3,0b01000100);
	MAX7219_set_row(4,0b01000100);
	MAX7219_set_row(5,0b01000100);
	MAX7219_set_row(6,0b01000100);
	MAX7219_set_row(7,0b01111100);
	_delay_ms(500);
	MAX7219_clear();
	
	// For W...
	MAX7219_set_row(1,0b01000100);
	MAX7219_set_row(2,0b01000100);
	MAX7219_set_row(3,0b01010100);
	MAX7219_set_row(4,0b01010100);
	MAX7219_set_row(5,0b01111100);
	MAX7219_set_row(6,0b01101100);
	MAX7219_set_row(7,0b01000100);
	_delay_ms(500);
	MAX7219_clear();
	
	// For I...
	MAX7219_set_row(1,0b01111100);
	MAX7219_set_row(2,0b00010000);
	MAX7219_set_row(3,0b00010000);
	MAX7219_set_row(4,0b00010000);
	MAX7219_set_row(5,0b00010000);
	MAX7219_set_row(6,0b00010000);
	MAX7219_set_row(7,0b01111100);
	_delay_ms(500);
	MAX7219_clear();
	
	// For N...
	MAX7219_set_row(1,0b01100100);
	MAX7219_set_row(2,0b01100100);
	MAX7219_set_row(3,0b01110100);
	MAX7219_set_row(4,0b01010100);
	MAX7219_set_row(5,0b01011100);
	MAX7219_set_row(6,0b01001100);
	MAX7219_set_row(7,0b01001100);
	_delay_ms(500);
	MAX7219_clear();
	
	END=1;   // ending the game
	
}


//---------------------------------------------------- Setting score to 7 segment display--------------------------------------

void FDscore()     //displaying score of the game
{
	if (score==0)
	{   MAX7219_clear_7SEG();
		MAX7219_set_row_7SEG(0,0b11111110); //number 0
		
	}
	if (score==1)
	{   MAX7219_clear_7SEG();
		MAX7219_set_row_7SEG(0,0b10110000); //number 1
		
	}
	if (score==2)
	{   MAX7219_clear_7SEG();
		MAX7219_set_row_7SEG(0,0b11101101); //number 2
		
	}
	if (score==3)
	{   MAX7219_clear_7SEG();
		MAX7219_set_row_7SEG(0,0b11111001); //number 3
		
	}
	if (score==4)
	{   MAX7219_clear_7SEG();
		MAX7219_set_row_7SEG(0,0b10110011); //number 4
		
	}
	if (score==5)
	{   MAX7219_clear_7SEG();
		MAX7219_set_row_7SEG(0,0b11011011); //number 5
		
	}
	if (score==6)
	{   MAX7219_clear_7SEG();
		MAX7219_set_row_7SEG(0,0b11011111); //number 6
		
	}
	if (score==7)
	{   MAX7219_clear_7SEG();
		MAX7219_set_row_7SEG(0,0b11110000); //number 7
		
	}
	if (score==8)
	{   MAX7219_clear_7SEG();
		MAX7219_set_row_7SEG(0,0b11111111); //number 8
		
	}
	if (score==9)
	{   MAX7219_clear_7SEG();
		MAX7219_set_row_7SEG(0,0b11111011); //number 9
		
	}
	if (score>=10)
	{   MAX7219_clear_7SEG();
		MAX7219_set_row_7SEG(0,0b11111110); //reset (Max Score)
		yoUwin();  // Setting up the "You Win" to display
	}
}


//----------------------------------------------Go thing--------------------------------


void DispGo()     // displaying " GO --> "
{
	
	//For G
	
	MAX7219_set_column(px-4,0b11110010);
	MAX7219_set_column(px-3,0b10010010);
	MAX7219_set_column(px-2,0b10010010);
	MAX7219_set_column(px-1,0b10000010);
	MAX7219_set_column(px,0b11111110);
	
	//For O
	
	MAX7219_set_column(px-11,0b11111110);
	MAX7219_set_column(px-10,0b11000110);
	MAX7219_set_column(px-9,0b11000110);
	MAX7219_set_column(px-8,0b11000110);
	MAX7219_set_column(px-7,0b11111110);
	
	// Arrow
	MAX7219_set_column(px-13,0b00011000);
	MAX7219_set_column(px-14,0b00011000);
	MAX7219_set_column(px-15,0b00011000);
	MAX7219_set_column(px-16,0b00011000);
	MAX7219_set_column(px-17,0b10011001);
	MAX7219_set_column(px-18,0b11011011);
	MAX7219_set_column(px-19,0b01111110);
	MAX7219_set_column(px-20,0b00111100);
	MAX7219_set_column(px-21,0b00011000);
}
void ShowGO()     // appearing the LED array
{
	for (px=0;px<30;px++)
	{
		DispGo();             // Displaying GO massage.........
		_delay_ms(150);       // Delay for 150ms ..............
		MAX7219_clear();      // Clear display .........
		_delay_ms(10);        // Delay for 150ms ..............
	}
	MAX7219_clear();   // clear the matrix 
	px=0;              // set-up px to 0 in the end
	
}


