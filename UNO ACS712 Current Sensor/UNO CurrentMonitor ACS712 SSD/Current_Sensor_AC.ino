const int sensorIn = A0;
int time = 0;
int first_ssd, second_ssd, number_sevenseg;
double standard = 0.7;
int number=1000, i, x=1;
int mVperAmp = 185; // use 100 for 20A Module and 66 for 30A Module
int VoltsOfCircuit = 1;
int y = 0;
int flag = 0;

char default1 = 'Washing Machine';
char default2 = 'Cable Box';
char default3 = 'TV';
char default4 = 'Coffee Maker';
char default5 = 'Charger';
char ResetChar = 'Reset';
char OpenChar = 'Open';
char CloseChar = 'Close';
char MonitorChar = 'Monitor';
char TimerChar = 'Set Timer';

double Voltage = 0;
double VRMS = 0;
double AmpsRMS = 0;



void setup(){ 
 Serial.begin(9600);
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
  
 y = y + 1;
 Serial.println(y);
 DetectChange();
 Voltage = getVPP();
 VRMS = (Voltage/2.0) *0.707; 
 AmpsRMS = (VRMS * 1000)/mVperAmp;
 
 Serial.print(AmpsRMS);
 Serial.println(" Amps RMS");
 int Watts = AmpsRMS * VoltsOfCircuit;

   double number_sevenseg = AmpsRMS * 100;
   
   if(AmpsRMS>1.00){
     number_sevenseg = number_sevenseg / 100;
   }
   first_ssd = number_sevenseg/10;
   second_ssd = number_sevenseg - (first_ssd * 10);
   
switch (first_ssd){
     case(0):
   digitalWrite(2, HIGH);
   digitalWrite(3, HIGH);
   digitalWrite(4, HIGH);
   digitalWrite(5, HIGH);
   digitalWrite(6, HIGH);
   digitalWrite(7, HIGH);
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
   digitalWrite(10, HIGH);
   digitalWrite(11, HIGH);
   digitalWrite(12, HIGH);
   digitalWrite(A1, HIGH);
   digitalWrite(A2, HIGH);
   digitalWrite(A3, HIGH);
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

   }
   
   if (flag == 0){
   if (y > 15){
if(AmpsRMS < standard){
 digitalWrite(13, HIGH);
 } 
   }
}
}


float getVPP()
{
  float result;
  
  int readValue;             //value read from the sensor
  int maxValue = 0;          // store max value here
  int minValue = 1024;          // store min value here
  
   uint32_t start_time = millis();
   while((millis()-start_time) < 1000) //sample for 1 Sec
   {
       readValue = analogRead(sensorIn);
       // see if you have a new maxValue
       if (readValue > maxValue) 
       {
           /*record the maximum sensor value*/
           maxValue = readValue;
       }
       if (readValue < minValue) 
       {
           /*record the maximum sensor value*/
           minValue = readValue;
       }
   }
   
   // Subtract min from max
   result = ((maxValue - minValue) * 5.0)/1024.0;
      
   return result;
 }
 

int DetectChange(){
  if (Serial.available() > 0){
    char data = Serial.read();
    
    if (data == default1){
      standard = 4;
      Serial.print("Washing Machine, Standard Set");
      Serial.print(standard);
    }
    if (data == default2){
      standard = 26;
      Serial.print("Cable Box, Standard Set");
      Serial.print(standard);
    }
    if (data == default3){
      standard = 1;
      Serial.println("TV, Standard Set");
      Serial.println(standard);
    }
    if (data == default4){
      standard = 1.1;
      Serial.println("Coffee Maker, Standard Set");
      Serial.println(standard);
    }
    if (data == default5){
      standard = 0.2;
      Serial.print("Charger, Standard Set");
      Serial.print(standard);
    }
    if (data == ResetChar){
      digitalWrite(13, LOW);
      Serial.print("Circuit Reset");
      flag = 0;
      delay(10000);
    }
    if (data == OpenChar){
      digitalWrite(13, LOW);
      Serial.print("OPEN");
      flag = 1;
      delay(10000);
    }
    if (data == CloseChar){
      digitalWrite(13, HIGH);
      Serial.print("CLOSED");
    }
    if (data == MonitorChar){
      Serial.print("Experimental Only for Phone Chargers");
      if (AmpsRMS > 0.9){
      Serial.print("Between 0 and 85 percent charged");
      }
      if (AmpsRMS < 0.9 & AmpsRMS != 0.2){
      Serial.print("Between 85 and 100 percent charged");
      }
      if (AmpsRMS = 0.2){
      Serial.print("100% charged and disconnected from current");
      }
    }
    if (data == TimerChar){
      Serial.print("Enter desired time in minutes");
      int time = Serial.read();
      time = time * 60000;
      delay(time);
      digitalWrite(13, HIGH);
      }
    Serial.print("Data Recieved");
  }

}
