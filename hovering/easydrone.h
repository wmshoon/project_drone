#include <SoftwareSerial.h>
#include <Servo.h> //라이브러리 불러오기
#include <Wire.h>

long a = 700;
#define MAX_SIGNAL 2100 // ends at 2150 but unstable
#define MIN_SIGNAL 1100 // starts at 1055 but unstable. 케바케로 안돌아가기도 한다.

Servo bldc0; //모터 선언
Servo bldc1; //모터 선언
Servo bldc2; //모터 선언
Servo bldc3; //모터 선언

void setup()
{

  Serial.begin(9600);

  bldc0.attach(6);
  bldc1.attach(9);
  bldc2.attach(10);
  bldc3.attach(11);

  Serial.println("시리얼 모니터를 키셨으면, 모터에서 삑-삑소리가 난 직후 아무키나 입력해주세요");
  bldc0.writeMicroseconds(MAX_SIGNAL);
  bldc1.writeMicroseconds(MAX_SIGNAL);
  bldc2.writeMicroseconds(MAX_SIGNAL);
  bldc3.writeMicroseconds(MAX_SIGNAL);
  while (!Serial.available())
  {
    ;
  }
  Serial.read();
  Serial.println("Sending minimum output");
  bldc0.writeMicroseconds(MIN_SIGNAL);
  bldc1.writeMicroseconds(MIN_SIGNAL);
  bldc2.writeMicroseconds(MIN_SIGNAL);
  bldc3.writeMicroseconds(MIN_SIGNAL);
}
void loop()
{
 if(Serial.available()>1)
  {
     a = Serial.parseInt();
  }
  bldc0.write(a);
  bldc1.write(a);
  bldc2.write(a);
  bldc3.write(a);
  Serial.println(a);
  
}
