#define buttonPin 2
#define ledPin 13                                                                                                        
int buttonstate; 
void setup() 
{
  pinMode(ledPin,OUTPUT);
  pinMode(buttonPin,INPUT);
}
void loop()
{
buttonstate=digitalRead(buttonPin);
if(buttonstate==LOW)
{
  digitalWrite(ledPin,HIGH);
}
else
{
  digitalWrite(ledPin,LOW);
}
}
