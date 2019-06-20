#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHTPIN 2    // Digital pin connected to the DHT sensor

// Uncomment the type of sensor in use:
#define DHTTYPE    DHT11     // DHT 11
//#define DHTTYPE    DHT22     // DHT 22 (AM2302)
//#define DHTTYPE    DHT21     // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);

String readDHTTemperature() {
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  //float t = dht.readTemperature(true);
  // Check if any reads failed and exit early (to try again).
  
}

String readDHTHumidity() {
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  
}
void setup(){
  // Serial port for debugging purposes
  Serial.begin(115200);

  dht.begin();

  }
 
void loop(){
  float t = dht.readTemperature();
  Serial.print("Temperature:");
  Serial.println(t);
  delay(500);
  float h = dht.readHumidity();
  Serial.print("Humidity:");
  Serial.println(h);
  delay(500);  
}
