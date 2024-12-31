#define sensor A0
#define relay A1
#define E1 8
#define E2 9

void setup(){
  analogReference(EXTERNAL);
  pinMode(sensor, INPUT);
  for(int i=0;i<10;i++){
    pinMode(i,OUTPUT);    
  }  
  pinMode(relay,OUTPUT);
}

char num[]={
  0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90    };

void loop(){
  int out = analogRead(sensor)/4;
  display2segment(out);
  if(out>20)
    digitalWrite(relay, HIGH);
  else
    digitalWrite(relay, LOW);
}

void display2segment(int temp){
  digitalWrite(E2,LOW);
  digitalWrite(E1,HIGH);  
  PORTD = num[temp/10];
  delay(1);
  digitalWrite(E1,LOW);
  digitalWrite(E2,HIGH);  
  PORTD = num[temp%10];
  delay(1);

}



