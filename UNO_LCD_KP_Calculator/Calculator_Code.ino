//==========8225 DEFINES========================================
#define RD 5
#define WR 4
#define A0 3
#define A1 2
#define PortA digitalWrite(A0,0); digitalWrite(A1,0); 
#define PortB digitalWrite(A0,1); digitalWrite(A1,0); 
#define PortC digitalWrite(A0,0); digitalWrite(A1,1); 
#define Contorl_Reg digitalWrite(A0,1); digitalWrite(A1,1);
#define Write_to_8255_pins(Delay) digitalWrite(WR,LOW);  delay(Delay);  digitalWrite(WR,HIGH);

//==============================================================


//========LCD DEFINES====================
#define RS 7
#define EN 6
#define COMMAND 0
#define DATA 1
#define LCD_BEGIN 0x38
#define LCD_CURSOR_BLINK 0X0E
#define LCD_CLEAR 0X01
#define CURSOR_RIGHT 0X06
#define CURSOR_LEFT 0X04
#define CURSOR_FIRST_LINE 0X80
#define CURSOR_SECOND_LINE 0XC0
//=======================================


//==================GLOPAL VARIABLES====================================================
//           d0 d1 d2 d3  d4 d5 d6 d7  RD WR A0 A1
int data[12]={13,12,11,10 ,9, 8, 7, 6 ,5 ,4 ,3 ,2};
String First_num="";                   //number on the Left of the Operator
String Second_num="";                  //number on the Right of the Operator
bool op_flag=0;      
char Operator=' ';      // Operator + - / *  
char keypadd[17]={'7','8','9','/','4','5','6','*','1','2','3','-','e','0','=','+'}; 
//======================================================================================


//=====================FUNCTION DECLERATIONS=============================================
void config_control_reg();
int get_key();
void init_lcd();
void display_character(int ch);
void send_to_lcd(byte Input,bool Command_Or_Data);
void print_string_to_lcd(String,int lcd_line);
void calc(String,String,char);
//=======================================================================================


void setup() 
{  
  // define pins as output
  for(int i=0;i<=11;i++) pinMode(data[i],OUTPUT);

  //Pause the read and write pin of 8255 
  digitalWrite(RD,HIGH); digitalWrite(WR,HIGH);
  
  // configure the control register of the 8255 chip
  config_control_reg();
  
  //send initialization commands to the lcd 
  init_lcd();
}

void loop() 
{

  //Working steps ===> get pressed key ==> Print on the lcd the pressed key ===> keep doing the last 2 steps until  '=' Operation is pressed

  int pressed_key_index=get_key();
  char character=keypadd[pressed_key_index];
  delay(210); 
  
  if(character!='e')    //    ON/c   is the reset button on which is mapped to letter 'e' 
  { 

        send_to_lcd(character,DATA);     // Send the pressed button to lcd to print it
        
        //check if the entered character is Operator 
        if( (int)character>=42 && (int) character<=47 && First_num!="" && op_flag==0)  
        {
            Operator=character;
            op_flag=1;
        }
        else if(character=='=')
        {
            calc(First_num,Second_num,Operator);
            delay(50);
        }
        else
        {
            //if its not an operation then add the number in the first or second string  depends on operator is enterd or not
            (op_flag == 0 ) ? First_num+=character : Second_num+=character;
        }
  }
  else  //if reset button is pressed ==> clear lcd 
  {
      send_to_lcd(LCD_CLEAR,COMMAND);
      First_num="";  Second_num="";  Operator=' ';   op_flag=0; 
  }

   
}





void config_control_reg()
{ 
  
  
  // 10001000  8 bit selecting the working mode of 8255 
  //lower pins of Port C as input and higher pins of Port C as output
  //port A as output for the lcd
  //Port B as output for controlling the lcd


  //first configure A0 A1 ==> control reg
   Contorl_Reg;

  for(int i=0;i<=7;i++) digitalWrite(data[i],LOW);   //all 8 data bits to 00000000
  
  digitalWrite(data[7],HIGH);   // then modify the bits for the Working mode to 10001000
  digitalWrite(data[3],HIGH);


  //write data in Control reg
   Write_to_8255_pins(50);
       
  
}



int get_key()
{
   //Select Port c to get the key from keypad
    PortC;

   //Pause the Write pin  
   digitalWrite(WR,HIGH);
   
  //make the keypad rows as input pins
  for(int i=4;i<=7;i++) pinMode(data[i],INPUT);
  
 
 while(true)
 {

    int N_col=4;
    int N_row=4;
    int selected_col=10;

    for(int col=0;col<N_col;col++)
    {
      digitalWrite(RD,HIGH); //disaple read pin
      
      for(int i=0;i<=3;i++) digitalWrite(data[i],HIGH);

      digitalWrite(selected_col,LOW);        
      
      //write data to 8255 pins
       Write_to_8255_pins(1);
       
        for(int row=0;row<=3;row++)
        {
          //Enable input pin
          digitalWrite(RD,LOW);
          
          if(digitalRead(data[row+4])==LOW) //check if any key is pressed in this Row
          {
            //if found ==> stop the Read pin of 8255  ==>  Return the index of the pressed key

            digitalWrite(RD,HIGH);
          
            return ((row*4)+col);      //return the index of the pressed key
          }
        }
      
      selected_col++;
    }

  
 }

  
}








void init_lcd()
{
  send_to_lcd(LCD_BEGIN,0);
  delay(30);
  send_to_lcd(LCD_CURSOR_BLINK,0);
  delay(30);
  send_to_lcd(LCD_CLEAR,0);
  delay(30);
}




void send_to_lcd(byte Input,bool Command_Or_Data)
{

  
  //select port A to send the data or command to lcd
  PortA; 
  


  for (int i=0;i<8;i++)
  {
    digitalWrite(data[i],(Input>> i) & 0x01);
  }

  
  //write data to lcd
  Write_to_8255_pins(10);

  //select port B to modify rs , EN to Command mode or Data mode
  PortB;

  digitalWrite(RS,Command_Or_Data); //Change RS for command/data




  digitalWrite(EN,HIGH);
  
  Write_to_8255_pins(10);

  digitalWrite(EN,LOW);
  
  Write_to_8255_pins(10);
   
}






void print_string_to_lcd(String st,int lcd_line)
{
 
  int st_size=st.length(); 
  
  if(lcd_line==2){ send_to_lcd(CURSOR_SECOND_LINE,COMMAND);} 
  
  for(int i=0;i<st_size;i++)
  {
     send_to_lcd(st[i],1);
  }

}


void calc(String First_num,String Second_num,char Operator)
{
  float Num1=First_num.toInt();
  float Num2=Second_num.toInt();
  float result;

  if( Num2==0 && Operator =='/' )  
  {
     print_string_to_lcd("Undefined   ....",2);
     return;
  }
  
  switch(Operator)
  {
    case '/':
    result=Num1/Num2;
    break;
    case '+':
    result=Num1+Num2;
    break;
    case '-':
    result=Num1-Num2;
    break;
    case '*':
    result=Num1*Num2;
    break;
  }
   
    print_string_to_lcd(String(result),1);
    print_string_to_lcd("Press ON/C  ....",2);
  
  return;
    
}
