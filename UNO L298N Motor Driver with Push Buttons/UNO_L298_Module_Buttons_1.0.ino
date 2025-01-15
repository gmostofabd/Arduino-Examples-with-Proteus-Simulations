//pin arduino ke module L298N
#define enA 10
#define in1 9
#define in2 8
#define in3 7
#define in4 6
#define enB 5

//tombol kontrol
#define btn_fwd     4
#define btn_bkwd    3
#define btn_stop    2

//nilai pwm (kecepatan putar)
int kecepatan=255;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);
  
  pinMode(btn_fwd, INPUT_PULLUP);
  pinMode(btn_bkwd, INPUT_PULLUP);
  pinMode(btn_stop, INPUT_PULLUP);
  motor_stop();
  delay(500);
}

void loop() {
  //tombol maju ditekan
  if(!digitalRead(btn_fwd)){
    motor_maju();
  }

  //tombol mundur ditekan
  if(!digitalRead(btn_bkwd)) {
    motor_mundur();
  }

  //tombol stop ditekan
  if (!digitalRead(btn_stop)) {
    motor_stop();
  }
}

void motor_maju(){
  analogWrite (enA, kecepatan);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite (enB, kecepatan);
}
void motor_mundur(){
  analogWrite (enA, kecepatan);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite (enB, kecepatan);
}
void motor_stop(){
  //kecepatan=0
  analogWrite (enA, 0);
  analogWrite (enB, 0);
}
