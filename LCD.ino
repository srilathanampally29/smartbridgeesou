#include<LiquidCrystal.h>
const int trigPin=4;
const int echoPin=2;
long duration;
int distance;
const int rs=22,en=23,d4=5,d5=18,d6=19,d7=21;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
void setup()
{
lcd.begin(16,2);
lcd.print(trigPin,OUTPUT);
lcd.print(echoPin,INPUT);
Serial.begin(9600);
}
void loop()
{
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=duration*0.034/4; 
  Serial.print("distance");
  Serial.println(distance);
  lcd.print("distance");
  lcd.println(distance);
}
