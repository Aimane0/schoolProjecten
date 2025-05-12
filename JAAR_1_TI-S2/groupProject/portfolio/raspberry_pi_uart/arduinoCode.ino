#include <SoftwareSerial.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Instellen van de one wire
float temp = 0.0;
int oneWireBus = 12;
OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);

// Instellen van UART
SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  // Open seriële communicaties en wacht:
  Serial.begin(9600);
  sensors.begin();
  mySerial.begin(9600);
}

void loop() {
  sensors.requestTemperatures();
  temp = sensors.getTempCByIndex(0);

  mySerial.println(temp);
  delay(2000);
}
