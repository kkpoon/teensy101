#include <dht11.h>

#define DHT11PIN 14
dht11 DHT11;

void setup()
{
  Serial.begin(38400);
}

void loop()
{
  int chk = DHT11.read(DHT11PIN);

  switch (chk)
  {
  case 0: 
    //Serial.println("OK"); 
    break;
  case -1: 
    Serial.println("Checksum error"); 
    break;
  case -2: 
    Serial.println("Time out error"); 
    break;
  default: 
    Serial.println("Unknown error"); 
    break;
  }
  Serial.print("Humidity (%): ");
  Serial.println((float)DHT11.humidity, 2);
  Serial.print("Temperature (oC): ");
  Serial.println((float)DHT11.temperature, 2);
  delay(2000);
}
