int s1,s2,s3,s4,s5,s6,s7,s8;


int left_enable = 3;
int left_forward = 5;
int left_backward = 4;

int right_enable = 6;
int right_forward = 7;
int right_backward = 8;



void setup() {
  // put your setup code here, to run once:
  pinMode(14,INPUT);
  pinMode(15,INPUT);
  pinMode(16,INPUT);
  pinMode(17,INPUT);
  pinMode(18,INPUT);
  pinMode(19,INPUT);

  pinMode(left_enable,OUTPUT);
  pinMode(right_enable,OUTPUT);
  pinMode(left_forward,OUTPUT);
  pinMode(left_backward,OUTPUT);
  pinMode(right_forward,OUTPUT);
  pinMode(right_backward,OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  s1=digitalRead(14);
  s2=digitalRead(15);
  s3=digitalRead(16);
  s4=digitalRead(17);
  s5=digitalRead(18);
  s6=digitalRead(19);
  //s7=digitalRead(9);
  //s8=digitalRead(11);
//  Serial.print(s1);
//  Serial.print(s2);
//  Serial.print(s3);
//  Serial.print(s4);
//  Serial.print(s5);
//  Serial.print(s6);
//  Serial.println(" ");
//  delay(3000);

 if((s1==0) && (s2==0) && (s3==1) && (s4==1) && (s5==0) && (s6==0)){
    Forword();
    }
 else if((s1==0) && (s2==0) && (s3==0) && (s4==1) && (s5==0) && (s6==0)){
      Forword();
    }
 else if((s1==0) && (s2==0) && (s3==1) && (s4==0) && (s5==0) && (s6==0)){
     Forword();
    }
 else if((s1==0) && (s2==1) && (s3==1) && (s4==0) && (s5==0) && (s6==0)){
     Forword();
    }
 else if((s1==0) && (s2==0) && (s3==0) && (s4==1) && (s5==1) && (s6==0)){
     Forword();
    }
 else if((s1==1) && (s2==1) && (s3==0) && (s4==0) && (s5==0) && (s6==0)){
     Left();
    }
 else if((s1==1) && (s2==0) && (s3==0) && (s4==0) && (s5==0) && (s6==0)){
     Left();
    }
 else if((s1==0) && (s2==1) && (s3==0) && (s4==0) && (s5==0) && (s6==0)){
     Left();
    }
 else if((s1==1) && (s2==1) && (s3==1) && (s4==0) && (s5==0) && (s6==0)){
     Left();
    }
 else if((s1==1) && (s2==1) && (s3==1) && (s4==1) && (s5==0) && (s6==0)){
     Left();
    }
 
 else if((s1==0) && (s2==0) && (s3==0) && (s4==0) && (s5==1) && (s6==1)){
      Right();
    }
 else if((s1==0) && (s2==0) && (s3==0) && (s4==0) && (s5==0) && (s6==1)){
      Right();
    }
 else if((s1==0) && (s2==0) && (s3==0) && (s4==0) && (s5==1) && (s6==0)){
      Right();
    }
 else if((s1==0) && (s2==0) && (s3==0) && (s4==1) && (s5==1) && (s6==1)){
      Right();
    }
 else if((s1==0) && (s2==0) && (s3==1) && (s4==1) && (s5==1) && (s6==1)){
      Right();
    }
 
  else {
    Stop();
  }
 
 
//  Forword();
//  delay(2000);
//  Right();
//  delay(2000);
//  Left();
//  delay(5000);
//  Stop();
//  delay(2000);
}


void Forword(){
  analogWrite(left_enable,200);//200
  analogWrite(right_enable,200 );//200
  digitalWrite(right_backward,LOW);
  digitalWrite(right_forward,HIGH);
  digitalWrite(left_backward,LOW);
  digitalWrite(left_forward,HIGH);
}

void Right(){
  analogWrite(left_enable,230);
  analogWrite(right_enable,0);
  digitalWrite(right_backward,LOW);
  digitalWrite(right_forward,HIGH);
  digitalWrite(left_backward,LOW);
  digitalWrite(left_forward,HIGH);
}
void Left(){
  analogWrite(left_enable,0);
  analogWrite(right_enable,245);
  digitalWrite(right_backward,LOW);
  digitalWrite(right_forward,HIGH);
  digitalWrite(left_backward,LOW);
  digitalWrite(left_forward,HIGH);
}

void Stop(){
  analogWrite(left_enable,0);
  analogWrite(right_enable,0);
  digitalWrite(right_backward,LOW);
  digitalWrite(right_forward,HIGH);
  digitalWrite(left_backward,LOW);
  digitalWrite(left_forward,HIGH);
}
