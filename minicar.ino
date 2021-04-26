#include <SoftwareSerial.h>
int X_signal = A0;  //X축 PIN
int X=0;//x축 값
int Y_signal = A1;  //Y축 PIN
int Y=0;//y축 값
int BLUETOOTH_TX=2;
int BLUETOOTH_RX=3;
SoftwareSerial mySerial(BLUETOOTH_TX,BLUETOOTH_RX);

void setup() 

{
  Serial.begin(9600);   //시리얼모니터
  mySerial.begin(9600);  //블루투스 시리얼
  pinMode(BLUETOOTH_TX, INPUT_PULLUP);
  }

void loop()
{        
   int X=analogRead(X_signal);
   int Y=analogRead(Y_signal); 
 Serial.print("X: ");
 Serial.println(X);
 Serial.print("Y: ");
 Serial.println(Y);

if(Y>=750&&Y<=800)
{
  if(X>=800&&X<=810){ mySerial.write("I");}
  else if(X>=811){mySerial.write("C");}
  else if(X<=800){mySerial.write("G");}
}

else if(Y<=799)
{
  if(X>=800&&X<=810){ mySerial.write("E");}
  else if(X>=811){mySerial.write("D");}
  else if(X<=800){mySerial.write("F");}
}

 else if(Y=1023)
{
  if(X>=800&&X<=810){ mySerial.write("A");}
  else if(X>=811){mySerial.write("B");}
  else if(X<=800){mySerial.write("H");}
}
  delay(100);
}

