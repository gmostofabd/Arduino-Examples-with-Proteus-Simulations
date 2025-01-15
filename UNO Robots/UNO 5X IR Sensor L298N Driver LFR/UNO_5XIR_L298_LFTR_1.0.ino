/*program Arduino LF dengan  sensor IR 5ch
  www.arducoding.com */
#define enA 3
#define in1 2
#define in2 4
#define in3 6
#define in4 7
#define enB 5

int pin_sensor[]={8,9,10,11,12};
int baca_sensor;
int inp;
int hasil_baca[]={0,0,0,0,0};

void setup(){
  pinMode(enA, OUTPUT); pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT); pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT); pinMode(in4, OUTPUT);
  
  int a;
  //setting pin sensor sebagai INPUT
   while(a<5){
    pinMode(pin_sensor[a],INPUT);
    a=a+1;
   } 
 }
 void loop() {
   baca_sensor=readOut(pin_sensor);

   switch (baca_sensor) {
      //hasil baca sensor untuk belok kiri
      case 1: case 10: case 11: case 111: 
      belok_kiri();  break;

      //hasil baca sensor untuk arah maju
      case 100: case 110: case 1100: 
      gerak_maju(); break;

      //hasil baca sensor untuk belok kanan
      case 11100: case 11000:   
      case 1000:  case 10000:  
      belok_kanan(); break;

      //hasil baca sensor untuk stop
      case 11111:  case 0: 
      motor_stop(); break;
   }
   
 }
 
 //menampung hasil baca sensor menjadi interger
 int readOut(int pin_sensor[]){
   int a,b,c=0;
   inp=0;
   while(c<5){
    hasil_baca[c]=0;
    c=c+1;
   }
   for(a=0;a<5;a++){
     hasil_baca[a]=digitalRead(pin_sensor[a]);
   }
   while(b<5){
     inp=inp*10+hasil_baca[b];
     b=b+1;
   }
  return inp;
}

//kendali motor
void gerak_maju(){
  analogWrite (enA, 255);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite (enB, 255);
}
void belok_kanan(){
  analogWrite (enA, 0);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite (enB, 200);
}

void belok_kiri(){
  analogWrite (enA, 200);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite (enB, 0);
}
void motor_stop(){
  //kecepatan=0
  analogWrite (enA, 0);
  analogWrite (enB, 0);
}
