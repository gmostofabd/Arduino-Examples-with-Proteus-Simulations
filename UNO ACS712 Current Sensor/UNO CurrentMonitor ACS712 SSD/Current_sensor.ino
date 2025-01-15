const int analogIn = A0;
int mVperAmp = 157; // use 100 for 20A Module and 66 for 30A Module
int RawValue= 0;
int ACSoffset = 2500; 
double Voltage = 0;
double Amps = 0;

void setup(){ 
 Serial.begin(9600);
 pinMode(A0, INPUT);
 pinMode(13, OUTPUT);
 for (int thisPin = 2; thisPin < 13; thisPin++) {
    pinMode(thisPin, OUTPUT);
    digitalWrite(thisPin, LOW);
  }
  
 pinMode(A1, OUTPUT);
 pinMode(A2, OUTPUT);
 pinMode(A3, OUTPUT);
 pinMode(A4, OUTPUT);
 pinMode(A5, OUTPUT);

}

void loop(){
 
 RawValue = analogRead(analogIn);
 delay(100);
 RawValue = RawValue+analogRead(analogIn);
  delay(100);
 RawValue = RawValue+analogRead(analogIn); delay(100);
 RawValue = RawValue+analogRead(analogIn); delay(100);
 RawValue = RawValue+analogRead(analogIn); delay(100);
 RawValue = RawValue+analogRead(analogIn); delay(100);
 RawValue = RawValue+analogRead(analogIn); delay(100);
 RawValue = RawValue+analogRead(analogIn); delay(100);
 RawValue = RawValue+analogRead(analogIn); delay(100);
 RawValue = RawValue+analogRead(analogIn);



 
  delay(100);
 RawValue = RawValue/10;
 
 Voltage = (RawValue / 1024.0) * 5000; // Gets you mV
 Amps = ((Voltage - ACSoffset) / mVperAmp);
 


 RawValue = analogRead(analogIn);
 delay(100);
 RawValue = RawValue+analogRead(analogIn);
  delay(100);
 RawValue = RawValue+analogRead(analogIn); delay(100);
 RawValue = RawValue+analogRead(analogIn); delay(100);
 RawValue = RawValue+analogRead(analogIn); delay(100);
 RawValue = RawValue+analogRead(analogIn); delay(100);
 RawValue = RawValue+analogRead(analogIn); delay(100);
 RawValue = RawValue+analogRead(analogIn); delay(100);
 RawValue = RawValue+analogRead(analogIn); delay(100);
 RawValue = RawValue+analogRead(analogIn);



 
  delay(100);
 RawValue = RawValue/10;
 
 Voltage = Voltage + (RawValue / 1024.0) * 5000; // Gets you mV
 Voltage=Voltage/2;
 Amps = ((Voltage - ACSoffset) / mVperAmp);




 
 Serial.print("Raw Value = " ); // shows pre-scaled value 
 Serial.print(RawValue); 
 Serial.print("\t mV = "); // shows the voltage measured 
 Serial.print(Voltage,3); // the '3' after voltage allows you to display 3 digits after decimal point
 Serial.print("\t Amps = "); // shows the voltage measured 
 Serial.println(Amps,3); // the '3' after voltage allows you to display 3 digits after decimal point
 delay(2500); 
 
 double number_sevenseg = Amps * 100;
   
   if(Amps>1.00){
     number_sevenseg = number_sevenseg / 100;
   }
   Serial.println(number_sevenseg);
   int first_ssd = number_sevenseg/10;
   int second_ssd = number_sevenseg - (first_ssd * 10);
   Serial.println(first_ssd); 
 switch(first_ssd){
   case(0):
   digitalWrite(2, LOW);
   digitalWrite(3, LOW);
   digitalWrite(4, LOW);
   digitalWrite(5, LOW);
   digitalWrite(6, LOW);
   digitalWrite(7, LOW);
   digitalWrite(8, LOW);
   digitalWrite(9, LOW);
     break;
   case(1):
   digitalWrite(2, LOW);
   digitalWrite(3, HIGH);
   digitalWrite(4, HIGH);
   digitalWrite(5, LOW);
   digitalWrite(6, LOW);
   digitalWrite(7, LOW);
   digitalWrite(8, LOW);
   digitalWrite(9, LOW);
     break;
   case(2):
   digitalWrite(2, HIGH);
   digitalWrite(3, HIGH);
   digitalWrite(4, LOW);
   digitalWrite(5, HIGH);
   digitalWrite(6, HIGH);
   digitalWrite(7, LOW);
   digitalWrite(8, HIGH);
   digitalWrite(9, LOW);
     break;
   case(3):
   digitalWrite(2, HIGH);
   digitalWrite(3, HIGH);
   digitalWrite(4, HIGH);
   digitalWrite(5, HIGH);
   digitalWrite(6, LOW);
   digitalWrite(7, LOW);
   digitalWrite(8, HIGH);
   digitalWrite(9, LOW);
     break;
   case(4):
   digitalWrite(2, LOW);
   digitalWrite(3, HIGH);
   digitalWrite(4, HIGH);
   digitalWrite(5, LOW);
   digitalWrite(6, LOW);
   digitalWrite(7, HIGH);
   digitalWrite(8, HIGH);
   digitalWrite(9, LOW);
     break;
   case(5):
   digitalWrite(2, HIGH);
   digitalWrite(3, LOW);
   digitalWrite(4, HIGH);
   digitalWrite(5, HIGH);
   digitalWrite(6, LOW);
   digitalWrite(7, HIGH);
   digitalWrite(8, HIGH);
   digitalWrite(9, LOW);
     break;
   case(6):
   digitalWrite(2, HIGH);
   digitalWrite(3, LOW);
   digitalWrite(4, HIGH);
   digitalWrite(5, HIGH);
   digitalWrite(6, HIGH);
   digitalWrite(7, HIGH);
   digitalWrite(8, HIGH);
   digitalWrite(9, LOW);
     break;
   case(7):
   digitalWrite(2, HIGH);
   digitalWrite(3, HIGH);
   digitalWrite(4, HIGH);
   digitalWrite(5, LOW);
   digitalWrite(6, LOW);
   digitalWrite(7, LOW);
   digitalWrite(8, LOW);
   digitalWrite(9, LOW);
     break;
   case(8):
   digitalWrite(2, HIGH);
   digitalWrite(3, HIGH);
   digitalWrite(4, HIGH);
   digitalWrite(5, HIGH);
   digitalWrite(6, HIGH);
   digitalWrite(7, HIGH);
   digitalWrite(8, HIGH);
   digitalWrite(9, LOW);
   break;
   
   case(9):
   digitalWrite(2, HIGH);
   digitalWrite(3, HIGH);
   digitalWrite(4, HIGH);
   digitalWrite(5, HIGH);
   digitalWrite(6, LOW);
   digitalWrite(7, HIGH);
   digitalWrite(8, HIGH);
   digitalWrite(9, LOW);
     break;
 }
   switch(second_ssd){
   case(0):
   digitalWrite(10, LOW);
   digitalWrite(11, LOW);
   digitalWrite(12, LOW);
   digitalWrite(A1, LOW);
   digitalWrite(A2, LOW);
   digitalWrite(A3, LOW);
   digitalWrite(A4, LOW);
   digitalWrite(A5, LOW);
     break;
   case(1):
   digitalWrite(10, LOW);
   digitalWrite(11, HIGH);
   digitalWrite(12, HIGH);
   digitalWrite(A1, LOW);
   digitalWrite(A2, LOW);
   digitalWrite(A3, LOW);
   digitalWrite(A4, LOW);
   digitalWrite(A5, LOW);
     break;
   case(2):
   digitalWrite(10, HIGH);
   digitalWrite(11, HIGH);
   digitalWrite(12, LOW);
   digitalWrite(A1, HIGH);
   digitalWrite(A2, HIGH);
   digitalWrite(A3, LOW);
   digitalWrite(A4, HIGH);
   digitalWrite(A5, LOW);
     break;
   case(3):
   digitalWrite(10, HIGH);
   digitalWrite(11, HIGH);
   digitalWrite(12, HIGH);
   digitalWrite(A1, HIGH);
   digitalWrite(A2, LOW);
   digitalWrite(A3, LOW);
   digitalWrite(A4, HIGH);
   digitalWrite(A5, LOW);
     break;
   case(4):
   digitalWrite(10, LOW);
   digitalWrite(11, HIGH);
   digitalWrite(12, HIGH);
   digitalWrite(A1, LOW);
   digitalWrite(A2, LOW);
   digitalWrite(A3, HIGH);
   digitalWrite(A4, HIGH);
   digitalWrite(A5, LOW);
     break;
   case(5):
   digitalWrite(10, HIGH);
   digitalWrite(11, LOW);
   digitalWrite(12, HIGH);
   digitalWrite(A1, HIGH);
   digitalWrite(A2, LOW);
   digitalWrite(A3, HIGH);
   digitalWrite(A4, HIGH);
   digitalWrite(A5, LOW);
     break;
   case(6):
   digitalWrite(10, HIGH);
   digitalWrite(11, LOW);
   digitalWrite(12, HIGH);
   digitalWrite(A1, HIGH);
   digitalWrite(A2, HIGH);
   digitalWrite(A3, HIGH);
   digitalWrite(A4, HIGH);
   digitalWrite(A5, LOW);
     break;
   case(7):
   digitalWrite(10, HIGH);
   digitalWrite(11, HIGH);
   digitalWrite(12, HIGH);
   digitalWrite(A1, LOW);
   digitalWrite(A2, LOW);
   digitalWrite(A3, LOW);
   digitalWrite(A4, LOW);
   digitalWrite(A5, LOW);
     break;
   case(8):
   digitalWrite(10, HIGH);
   digitalWrite(11, HIGH);
   digitalWrite(12, HIGH);
   digitalWrite(A1, HIGH);
   digitalWrite(A2, HIGH);
   digitalWrite(A3, HIGH);
   digitalWrite(A4, HIGH);
   digitalWrite(A5, LOW);
     break;
   case(9):
   digitalWrite(10, HIGH);
   digitalWrite(11, HIGH);
   digitalWrite(12, HIGH);
   digitalWrite(A1, HIGH);
   digitalWrite(A2, LOW);
   digitalWrite(A3, HIGH);
   digitalWrite(A4, HIGH);
   digitalWrite(A5, LOW);
     break;

}}
