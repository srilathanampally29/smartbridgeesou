
void setup()
{
Serial.begin(115200);  
}

void loop()
{
  int temperaturevalue=analogRead(2)/4;
 Serial.println("temperature value is");
 Serial.println(temperaturevalue);
 Serial.println("Temp(c)");
}
