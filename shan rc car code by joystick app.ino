#include <SoftwareSerial.h>
#include<Servo.h>
SoftwareSerial BT(2, 3); // RX, TX

Servo my_servo;
#define enA 6
#define in1 4
#define in2 5



int xAxis=140, yAxis=140;

int motorSpeedA = 0;
int motorSpeedB = 0;

void setup() {
  my_servo.attach(9);
pinMode(enA, OUTPUT);

pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);

Serial.begin(9600);
BT.begin(9600); // Default communication rate of the Bluetooth module

}

void loop() {
  
  // Read the incoming data from the Smartphone Android App
  while (BT.available() >= 2) {
    xAxis = BT.read();
    delay(10);
    yAxis = BT.read();
   Serial.print(xAxis);
   Serial.print(",");
   Serial.println(yAxis);
  }
  delay(10);
  
  

if (xAxis > 130 && xAxis <150 && yAxis > 130 && yAxis <150)
{
  digitalWrite(in1, LOW);
digitalWrite(in2, LOW); 
my_servo.write(90);
Serial.println("stop");
}
int joyvaly=map(yAxis,60,220,0,180);
  my_servo.write(joyvaly);                              //turn left & right
  Serial.println(joyvaly);

if(xAxis>=150)
  {                                                     //forward  
  xAxis=map(xAxis,150,220,0,255);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(enA,xAxis);
  Serial.println("forward");
  Serial.println(xAxis);

  }
  else if (xAxis<=130){                               //backward
    xAxis=map(xAxis,130,60,0,255);
   digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  analogWrite(enA,xAxis);
  Serial.println("backward");
  Serial.println(xAxis);

  }
 else {
   digitalWrite(in1, LOW);
digitalWrite(in2, LOW); 
my_servo.write(90);
Serial.println("stop");
 }
}



