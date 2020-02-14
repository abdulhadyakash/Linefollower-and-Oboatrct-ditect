int s1, s2, s3, s4, s5, s6, s7, s8; 
int trigPin = 9; int echoPin = 10; 
long duration; float distance; 
int left_enable = 3; 
int left_forward = 5; 
int left_backward = 4; 
int right_enable = 6;
int right_forward = 7; 
int right_backward = 8; 
void setup() { // put your setup code here,to run once: 
  pinMode(14, INPUT);
  pinMode(15, INPUT);
  pinMode(16, INPUT);
  pinMode(17, INPUT);
  pinMode(18, INPUT);
  pinMode(19, INPUT); 
  pinMode(left_enable, OUTPUT);
  pinMode(right_enable, OUTPUT);
  pinMode(left_forward, OUTPUT);
  pinMode(left_backward, OUTPUT);
  pinMode(right_forward, OUTPUT); 
  pinMode(right_backward, OUTPUT); 
  Serial.begin(9600); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); }
}
}
10
void loop() { // put your main code here, to run repeatedly:
  s1 = digitalRead(14);
  s2 = digitalRead(15);
  s3 = digitalRead(16); 
  s4 = digitalRead(17); 
  s5 = digitalRead(18); 
  s6 = digitalRead(19); 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 
  duration = pulseIn(echoPin, HIGH); 
  distance = ((duration) / 2) * .034; 
  if ( distance<10.00)
  { 
    //here the obstacle code 
    Stop(); 
    delay(1000);
    RightTurn(); 
    delay(420); 
    Stop(); 
    delay(500); 
    forword(); 
    delay(800); 
    left(); 
    delay(365); 
    Stop(); 
    delay(500); 
    forword(); 
    delay(1200); 
    Stop(); 
    delay(500); 
    left(); 
    delay(500); 
    Stop(); 
    delay(500); 
    }
    else {
      //here the line follow code 
      if ((s1 == 0) && (s2 == 0) && (s3 == 1) && (s4 == 1) && (s5 == 0) && (s6 == 0)) 
      { Forword();
      } else if ((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 0) && (s6 == 0)) 
      { Forword();
      } else if ((s1 == 0) && (s2 == 0) && (s3 == 1) && (s4 == 0) && (s5 == 0) && (s6 == 0)) {
        Forword(); } 
        else if ((s1 == 0) && (s2 == 1) && (s3 == 1) && (s4 == 0) && (s5 == 0) && (s6 == 0)) { 
          Forword(); }
        else if ((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 1) && (s6 == 0)) {
          Forword(); } 
          11
        else if ((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 0) && (s6 == 0))
        { Left(); } 
        else if ((s1 == 1) && (s2 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 0) && (s6 == 0)) {
          Left(); } 
        else if ((s1 == 0) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 0) && (s6 == 0)) {
          Left(); } 
        else if ((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 0) && (s5 == 0) && (s6 == 0)) { 
            Left(); } 
        else if ((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 0) && (s6 == 0)) { 
           Left(); } 
           else if ((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 1) && (s6 == 1)) { 
            Right(); } 
            else if ((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 0) && (s6 == 1)) 
            { Right(); 
            } 
            else if ((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 1) && (s6 == 0)) { 
              Right(); }
           else if ((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 1) && (s6 == 1))
           { Right();
           }
           else if ((s1 == 0) && (s2 == 0) && (s3 == 1) && (s4 == 1) && (s5 == 1) && (s6 == 1)) { 
            Right(); }
            else if ((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 0) && (s6 == 0))
            { special(); }
            else if ((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 1) && (s6 == 1))
            { search(); 
            delay(420);
            }
            else {
              Stop();
}
}
}
void Forword() {//normal forword code 
  analogWrite(left_enable, 100);//200 
  analogWrite(right_enable, 140); //200 
  digitalWrite(right_backward, LOW); 
  digitalWrite(right_forward, HIGH); 
  digitalWrite(left_backward, LOW); 
  digitalWrite(left_forward, HIGH);
}

void Right() { //normal Right turn 
  analogWrite(left_enable, 100); //230 
  analogWrite(right_enable, 150); //0 
  digitalWrite(right_backward, HIGH); 
  digitalWrite(right_forward, LOW); 
  digitalWrite(left_backward, LOW); 
  digitalWrite(left_forward, HIGH); 
  } 
void Left() {//normal Left turn 
    analogWrite(left_enable, 150); //0 
    analogWrite(right_enable, 120); //245 
    digitalWrite(right_backward, LOW); 
    digitalWrite(right_forward, HIGH); 
    digitalWrite(left_backward, HIGH); 
    digitalWrite(left_forward, LOW); } 
void Stop() { 
      analogWrite(left_enable, 0); 
      analogWrite(right_enable, 0); 
      digitalWrite(right_backward, LOW); 
      digitalWrite(right_forward, HIGH); 
      digitalWrite(left_backward, LOW); 
      digitalWrite(left_forward, HIGH); 
      } 
void RightTurn(){ 
  analogWrite(left_enable,130);//230 
  analogWrite(right_enable,200);//0 
  digitalWrite(right_backward,HIGH); 
  digitalWrite(right_forward,LOW); 
  digitalWrite(left_backward,LOW); 
  digitalWrite(left_forward,HIGH); 
  } 
void forword(){//after finding obstacle 
    analogWrite(left_enable,100);//230 
    analogWrite(right_enable,150);//0 
    digitalWrite(right_backward,LOW); 
    digitalWrite(right_forward,HIGH); 
    digitalWrite(left_backward,LOW); 
    digitalWrite(left_forward,HIGH); 
    } 
void left(){//after finding obstacle 
      analogWrite(left_enable,180);//230 
      analogWrite(right_enable,150);//0 
      digitalWrite(right_backward,LOW); 
      digitalWrite(right_forward,HIGH); 
      digitalWrite(left_backward,HIGH); 
      digitalWrite(left_forward,LOW); 
      } 
void special(){//after finding obstacle 
        analogWrite(left_enable,80);//230 
        analogWrite(right_enable,120);//0 
        digitalWrite(right_backward,LOW); 
        digitalWrite(right_forward,HIGH); 
        digitalWrite(left_backward,LOW);
        digitalWrite(left_forward,HIGH); 
        } 
void search(){//When 8 sensor all are on black line 
          analogWrite(left_enable,120);//230 
          analogWrite(right_enable,150);//0 
          digitalWrite(right_backward,HIGH); 
          digitalWrite(right_forward,LOW); 
          digitalWrite(left_backward,LOW); 
          digitalWrite(left_forward,HIGH); 
          }
