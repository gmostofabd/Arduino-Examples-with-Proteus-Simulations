void setup() {
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
}

void loop() {
  int v = digitalRead(2);
  int s = digitalRead(3);
  
  if(v==1 and s==1){
    digitalWrite(13,1);
    digitalWrite(12,0);
    digitalWrite(11,1);
    digitalWrite(10,0);
  }
  if(v==1 and s==0){
    digitalWrite(13,0);
    digitalWrite(12,1);
    digitalWrite(11,1);
    digitalWrite(10,0);
  }
  if(v==0 and s==1){
    digitalWrite(13,1);
    digitalWrite(12,0);
    digitalWrite(11,0);
    digitalWrite(10,1);
  }
  if(v==0 and s==0){
    digitalWrite(13,0);
    digitalWrite(12,1);
    digitalWrite(11,0);
    digitalWrite(10,1);
}
}