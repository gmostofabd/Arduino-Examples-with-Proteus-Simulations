

/*   <<----------------------------------------------------------------This is the library that has commonds to move snake ------------------------------------------------------------>>*/

#include "uzart.h"   // Library that used to communicate between MCUs

int Cx;				 //  head x position of the snake
int Cy;				 //   head y position of the snake

int Tx=3;			 //  Snake tail X position
int Ty=3;            //  Snake tail y position

int XBU=7;			 //   upper boundary of the LED matrix
int YBU=7;           //   right boundary of the LED matrix

int XBD=0;           // bottom boundary of the LED matrix
int YBD=0;           // left boundary of the LED matrix

int tmpSnake [2];    // temperate snake
int snakelength=1;   // length of the starting snake
int dir=1;           // starting length of snake
int foodLoc [2];     // food location array



//----------------------------------------------------- Snake Movements ---------------------------------------------------------------------

void snakeinit()                        // init method of 'MAX7219' library
{
	MAX7219_set_pixel(Cx,Cy,true);     // setting LED
}

void snakeclear()                       // clear the display or clear LED dot
{
	MAX7219_set_pixel(Tx,Ty,false);
}



void moveup()							// Move up function
{
	if (Cx>XBU||Cx<XBD||Cy>YBU||Cy<YBD)  // looking for boundary
	{
		gameOver();  // stop game
	}
	else
	{ 
		MAX7219_set_pixel(Cx,Cy,true);    // on the position dot
		_delay_ms(300);                   // game speeds
		MAX7219_set_pixel(Cx,Cy,false);   // off
		MAX7219_set_pixel(Cx-1,Cy,true);  // on next position
		Cx=Cx-1;                          // update current x value
		Cy=Cy;                            // update current y value
		
		/* other move methods are also same type. So, not going to comment them*/
		
	}
}

void movedown()							// Move down function
{
	if (Cx>XBU||Cx<XBD||Cy>YBU||Cy<YBD)
	{
		gameOver();   // Ending the game after hitting boundaries...............
	}
	else
	{
		MAX7219_set_pixel(Cx,Cy,true);         // On LED .....
		_delay_ms(300);                        // Adding delay
		MAX7219_set_pixel(Cx,Cy,false);
		MAX7219_set_pixel(Cx+1,Cy,true);
		Cx=Cx+1;  
		Cy=Cy;
	}
}

void moveright()						// Move right function
{
	if (Cx>XBU||Cx<XBD||Cy>YBU||Cy<YBD)
	{
		gameOver();   // Ending the game after hitting boundaries...............
	}
	else
	{
		MAX7219_set_pixel(Cx,Cy,true);         // On LED .....
		_delay_ms(300);                        // Adding delay
		MAX7219_set_pixel(Cx,Cy,false);
		MAX7219_set_pixel(Cx,Cy+1,true);
		Cx=Cx;
		Cy=Cy+1;
	}
	
}

void moveleft()                         // Move left function
{
	if (Cx>XBU||Cx<XBD||Cy>YBU||Cy<YBD)
	{
		gameOver();   // Ending the game after hitting boundaries...............
		
	}
	else
	{
		MAX7219_set_pixel(Cx,Cy,true);         // On LED .....
		_delay_ms(300);                        // Adding delay
		MAX7219_set_pixel(Cx,Cy,false);
		MAX7219_set_pixel(Cx,Cy-1,true);
		Cx=Cx;
		Cy=Cy-1;
	}
}




int RNG()
{
	char rec;                         // set-up a char variable to receive data
	int rng;                          // set-up variable to convert 'char' to 'int'
	USART_Transmit('S');              // send the 'char "S" '
	rec = USART_Receive();            // receive the 'char' number
	
	/* This "if" statement is used to convert char to int for set-up positions */
	
	if     (rec == '1'){rng = 0;}
	else if(rec == '2'){rng = 1;}
	else if(rec == '3'){rng = 2;}
	else if(rec == '4'){rng = 3;}
	else if(rec == '5'){rng = 4;}
	else if(rec == '6'){rng = 5;}
	else if(rec == '7'){rng = 6;}
	else               {rng = 7;}
	return(rng);           
}

void foodSpawn()         // This is the method that used to get food positions
{
	int x = RNG();       // getting value to x position
	foodLoc[0]=x;        // assign value to array for comparing 
	int y = RNG();       // getting value to y position
	foodLoc[1]=y;        // assign value to array for comparing 
	
	MAX7219_set_pixel(y,x,true);  // set-up the food dot
}

void isFoodEaten()
{
	tmpSnake [0] = Cx;   // temperate X position of the snake
	tmpSnake [1] = Cy;   // temperate Y position of the snake
	
	if(tmpSnake[0] == foodLoc[1] && tmpSnake[1] == foodLoc[0])  // finding foods are eaten.
	{
		foodSpawn();        //  Getting new food position
		score = score+1;    //  Increase scores
		FDscore();          //  starting Score displaying function
	}
	else{}
}

void move(int dir)                      // Main function that used to directing the movements
{
	if (dir==0) // up
	{
		moveup();      // Calling move up methode......
	}
	
	if (dir==1) // down
	{
		movedown();    // Calling move down methode......
	}
	
	if (dir==2) // right
	{
		moveright();    // Calling move right methode......
	}
	
	if (dir==3) // left
	{
		moveleft();    // Calling move left methode......
	}
}
