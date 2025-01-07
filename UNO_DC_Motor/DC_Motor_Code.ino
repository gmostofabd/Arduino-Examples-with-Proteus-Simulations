#define M1 7
#define M2 6

void setup() {
 pinMode(M1,OUTPUT) ; 
 pinMode(M2,OUTPUT) ;
}

void loop() {
   digitalWrite(M1,HIGH) ;
   digitalWrite(M2,LOW) ;
   delay(3000) ;
   digitalWrite(M1,LOW) ;
   digitalWrite(M2,HIGH) ;
   delay(3000) ;
   
}