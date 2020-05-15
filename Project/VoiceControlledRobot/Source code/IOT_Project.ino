#include <SoftwareSerial.h> // TX RX software library for bluetooth
#include <Servo.h>  //servo library
Servo myservo;  
SoftwareSerial mySerial(2,3);  // Connect the TXD pin of BT module to pin 2 of the Arduino and the RXD pin of BT module to pin 3 of Arduino.
#include <DHT.h>
#include <math.h>

#define DHTPIN 13
#define DHTTYPE DHT22
DHT dht(DHTPIN,DHTTYPE);

int Rightmotor1 = 7; //pin 1 of Rightmotor 
int Rightmotor2 = 8; //pin2 of Rightmotor 
int leftmotor1 = 9;//pin1 of leftmotor 
int leftmotor2 = 11;//pin2 of leftmotor 
int en1=5; //enable pin for Rightmotor 
int en2=6; // enable pin for leftmotor

char t;

void setup()
{
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(Rightmotor1,OUTPUT);  // attach Right Motor 1st wire to pin 4
  pinMode(Rightmotor2,OUTPUT); // attach Right Motor 1st wire to pin 5
  pinMode(leftmotor1,OUTPUT);// attach Right Motor 1st wire to pin 6
  pinMode(leftmotor2,OUTPUT);// attach Right Motor 1st wire to pin 7
  pinMode(en1,OUTPUT);  //attach motor drivers rightmotor enable pin to PWM pin 9 of arduino        
  pinMode(en2,OUTPUT);//attach motor drivers leftmotor enable pin to PWM pin 10 of arduino
 
  Serial.begin(9600); //Setup usb serial connection to computer
  mySerial.begin(9600);//Setup Bluetooth serial connection to android
  
} 

void loop()
{   
  if(Serial.available()){
  t = Serial.read();
   }
  
    if(t == '1' or t == 'f'){  //if forward received do following 
      digitalWrite(Rightmotor1, HIGH);  ////////////FORWARD ////////////////////////
      digitalWrite(Rightmotor2, LOW);
      digitalWrite(leftmotor1, LOW);
      digitalWrite(leftmotor2, HIGH);
       analogWrite(en1,200);// for controlling speed of Rightmotor vary the value from 0 to 255
       analogWrite(en2,200);// for controlling speed of leftmotor vary the value from 0 to 255
        delay(50);
     }
    
    else if(t == '3' or t == 'b'){  //if Back received do following 
       
      digitalWrite(Rightmotor1, LOW);  ////////////BACK/////////////////////////////
      digitalWrite(Rightmotor2, HIGH);
      digitalWrite(leftmotor1, HIGH);
       digitalWrite(leftmotor2, LOW);
       analogWrite(en1,200);
       analogWrite(en2,200);
       delay(50);
     }
    

    else if(t == '2' or t =='l'){  //if left received do following 
       digitalWrite(Rightmotor1,LOW);/////////////LEFT////////////////////////////
      digitalWrite(Rightmotor2, HIGH);
      digitalWrite(leftmotor1, LOW);
       digitalWrite(leftmotor2, HIGH);
       analogWrite(en1,200);
       analogWrite(en2,200);
       delay(50);
     }
    

    else if(t == '4' or t == 'r'){   //if Right received do following 
      digitalWrite(Rightmotor1, HIGH);/////////////RIGHT////////////////////////
      digitalWrite(Rightmotor2, LOW);
      digitalWrite(leftmotor1, HIGH);
       digitalWrite(leftmotor2, LOW);
       analogWrite(en1,200);
       analogWrite(en2,200);
       delay(50);
    }

    else if(t == '5' or t =='s'){  //if stop received do following 
      digitalWrite(Rightmotor1, LOW); ///////////stop/////////////////
      digitalWrite(Rightmotor2, LOW);
      digitalWrite(leftmotor1, LOW);
       digitalWrite(leftmotor2, LOW);
       
    } 

  else if(t =='6' or t=='g'){
    float humidity = dht.readHumidity();
 
    float temp = dht.readTemperature();
   
    int light=analogRead(A1);

     Serial.print("Temp : ");
      Serial.print((int)temp);
      Serial.print("|");
      Serial.print("Hum : ");
      Serial.print((int)humidity);
    Serial.print("|");
    Serial.print("Light : ");
    Serial.print((int)light);
    delay(300);
    system("cls");
    if(light<=10)
    {
      digitalWrite(2,HIGH);
      digitalWrite(4,HIGH);
    }
    else{
      digitalWrite(2,LOW);
      digitalWrite(4,LOW);
    }
    }
      }
  
     
//    if (indicator ="y"){
//       digitalWrite(Trig, LOW);   
//        delayMicroseconds(2);
//       digitalWrite(Trig, HIGH);  
//      delayMicroseconds(20);
//      digitalWrite(Trig, LOW);   
//     float  time= pulseIn(Echo, HIGH); 
//     distance=time*340/20000; 
//     Serial.write(distance);
//   
//    }
//}

//float Distance() {
//  digitalWrite(Trig, LOW);   
//  delayMicroseconds(2);
//  digitalWrite(Trig, HIGH);  
//  delayMicroseconds(20);
//  digitalWrite(Trig, LOW);   
//  int Fdistance = pulseIn(Echo,HIGH);  
//  Fdistance= Fdistance / 58;       
//  Serial.println(Fdistance);  
//  return Fdistance;
//}