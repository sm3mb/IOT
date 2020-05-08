#include<Servo.h>
int Echo = A4;  
int Trig = A5; 
int Rightmotor1 = 7; //pin 1 of Rightmotor 
int Rightmotor2 = 8; //pin2 of Rightmotor 
int leftmotor1 = 9;//pin1 of leftmotor 
int leftmotor2 = 11;//pin2 of leftmotor 
int en1=5; //enable pin for Rightmotor 
int en2=6; // enable pin for leftmotor


//int rightDistance = 0, leftDistance = 0, middleDistance = 0;
void setup(){
   pinMode(Trig,OUTPUT);
   pinMode(Echo,INPUT);
   pinMode(Rightmotor1,OUTPUT);  // attach Right Motor 1st wire to pin 4
  pinMode(Rightmotor2,OUTPUT); // attach Right Motor 1st wire to pin 5
  pinMode(leftmotor1,OUTPUT);// attach Right Motor 1st wire to pin 6
  pinMode(leftmotor2,OUTPUT);// attach Right Motor 1st wire to pin 7
  pinMode(en1,OUTPUT);  //attach motor drivers rightmotor enable pin to PWM pin 9 of arduino        
  pinMode(en2,OUTPUT);//attach motor drivers leftmotor enable pin to PWM pin 10 of arduino
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  Serial.begin(9600);
}

void loop(){
  
digitalWrite(Trig, LOW);   
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);  
  delayMicroseconds(20);
  digitalWrite(Trig, LOW);   
  int Fdistance = pulseIn(Echo,HIGH);  
  Fdistance= Fdistance / 58;       
  Serial.write(Fdistance);
  if(Fdistance>300)
  {
    digitalWrite(Rightmotor1, HIGH);  ////////////FORWARD ////////////////////////
      digitalWrite(Rightmotor2, LOW);
      digitalWrite(leftmotor1, LOW);
      digitalWrite(leftmotor2,HIGH);
       analogWrite(en1,200);// for controlling speed of Rightmotor vary the value from 0 to 255
       analogWrite(en2,200);// for controlling speed of leftmotor vary the value from 0 to 255
       digitalWrite(2,LOW);
       digitalWrite(4,LOW);
        delay(200);
  }
  else if(Fdistance<50)
  {
    digitalWrite(Rightmotor1, LOW);  ////////////FORWARD ////////////////////////
      digitalWrite(Rightmotor2,HIGH);
      digitalWrite(leftmotor1, HIGH);
      digitalWrite(leftmotor2, LOW);
       analogWrite(en1,200);// for controlling speed of Rightmotor vary the value from 0 to 255
       analogWrite(en2,200);// for controlling speed of leftmotor vary the value from 0 to 255
       digitalWrite(2,HIGH);
       digitalWrite(4,HIGH);
        delay(200);
    
  }
}