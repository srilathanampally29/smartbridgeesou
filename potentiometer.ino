void setup()
{
Serial.begin(115200);  
}

void loop()
{
 int potentiometervalue=analogRead(2)/4;
 Serial.println("potentiometer value is");
 Serial.println(potentiometervalue);
 Serial.println("volts"); 
}
