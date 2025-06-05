#include <Servo.h> //includes the servo library

Servo myservo;

#define ldr1 A0 // set ldr 1 Analog input pin of East ldr as an integer
#define ldr2 A1 // set ldr 2 Analog input pin of West ldr as an integer

int pos = 90; // initial position of the Horizontal movement controlling servo motor
int tolerance = 20; // allowable tolerance setting - so solar servo motor isn't constantly in motion
   
void setup(){
myservo.attach(2); // attaches the servo on digital pin 2 to the horizontal movement servo motor 
pinMode(ldr1, INPUT); //set East ldr pin as an input
pinMode(ldr2, INPUT); //set West ldr pin as an input
myservo.write(pos); // write the starting position of the horizontal movement servo motor 
    
delay(1000); // 1 second delay to allow the solar panel to move to its staring position before comencing solar tracking
}

void loop(){      
int val1 = analogRead(ldr1); // read the value of ldr 1
int val2 = analogRead(ldr2); // read the value of ldr 2
      
if((abs(val1 - val2) <= tolerance) || (abs(val2 - val1) <= tolerance)) {
//no servo motor horizontal movement will take place if the ldr value is within the allowable tolerance
}else {
if(val1 > val2) // if ldr1 senses more light than ldr2 
{
pos = pos+1; // decrement the 90 degree poistion of the horizontal servo motor - this will move the panel position Eastward
}
if(val1 < val2) // if ldr2 senses more light than ldr1
{
pos = pos-1; // increment the 90 degree position of the horizontal motor - this will move the panel position Westward
 }
}
     
if(pos > 180) {pos = 180;} // reset the horizontal postion of the motor to 180 if it tries to move past this point
if(pos < 0) {pos = 0;} // reset the horizontal position of the motor to 0 if it tries to move past this point
myservo.write(pos); // write the starting position to the horizontal motor
delay(50);

}

