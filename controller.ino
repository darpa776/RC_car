#include <PWM.h>
int32_t frequency = 1000000;
#include <SoftwareSerial.h>
int BLUETOOTH_TX=2;
int BLUETOOTH_RX=3;
SoftwareSerial mySerial(BLUETOOTH_TX,BLUETOOTH_RX);
//모터A 컨트롤
int IN1=4;
int IN2=5;
int A_enable=9;
//모터B 컨트롤
int IN3=6;
int IN4=7;
int B_enable=10;
void setup() 
{InitTimersSafe();
bool success1 =SetPinFrequencySafe(5,frequency);
bool success2 =SetPinFrequencySafe(6,frequency);
if(success1)
{ pinMode(A_enable,OUTPUT);}
 if(success2)
 { pinMode(B_enable,OUTPUT);}
  Serial.begin(9600);   //
  mySerial.begin(9600); //블루투스 시리얼
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
 
  pinMode(BLUETOOTH_TX,INPUT_PULLUP);
}
void loop()
{
  if(mySerial.available())
  {
    char a= mySerial.read();
   
  
if(a=='I')
  { Serial.println(a);
    digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        analogWrite(A_enable, 0);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        analogWrite(B_enable, 0);
         //delay(3000);
  }
  else if(a=='A')
  {     
     Serial.println(a);
     digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        pwmWrite(A_enable, 170);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        pwmWrite(B_enable, 150);
        //delay(3000);
  }
 else if(a=='B')
  {  Serial.println(a); 
    digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        pwmWrite(A_enable, 120);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        pwmWrite(B_enable, 130);
        //delay(3000);
  }
  else if(a=='C')
  {     
     Serial.println(a);
     digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        pwmWrite(A_enable, 100);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        pwmWrite(B_enable, 150);
        //delay(3000);
  }
  else if(a=='D')
  {  Serial.println(a);    
    digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        pwmWrite(A_enable, 100);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        pwmWrite(B_enable, 150);
        //delay(3000);
  }
  else if(a=='E')
  {  Serial.println(a);    
    digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        pwmWrite(A_enable, 150);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        pwmWrite(B_enable, 130);
        //delay(3000);
  }
  else if(a=='F')
  {  Serial.println(a);    
    digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        pwmWrite(A_enable, 130);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        pwmWrite(B_enable, 120);
        //delay(3000);
  }
  else if(a=='G')
  {  Serial.println(a);    
    digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        pwmWrite(A_enable, 150);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        pwmWrite(B_enable, 100);
        //delay(3000);
  }
  else if(a=='H')
  {  Serial.println(a);   
    digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        pwmWrite(A_enable, 150);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        pwmWrite(B_enable, 100);
        //delay(3000);
  }
  }/*
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        pwmWrite(A_enable, 255);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        pwmWrite(B_enable, 255);
        delay(3000);*/
}
 
