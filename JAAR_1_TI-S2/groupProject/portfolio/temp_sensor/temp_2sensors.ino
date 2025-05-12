//1-Wire Arduino sketch for DS18B20 waterproof temperature sensor

#include <OneWire.h>
#include <DallasTemperature.h>

float temp = 0.0;
float temp2 = 0.0;
int oneWireBus = 12;
OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  Serial.println("1-Wire Arduino sketch for DS18B20 waterproof temperature sensor");
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures();
  temp = sensors.getTempCByIndex(0);
  temp2 = sensors.getTempCByIndex(1);


  Serial.print("Temperature reading pin 1: ");
  Serial.println(temp);
  Serial.print("Temperature readin pin 2: ");
  Serial.println(temp2);

  delay(5000);
}
