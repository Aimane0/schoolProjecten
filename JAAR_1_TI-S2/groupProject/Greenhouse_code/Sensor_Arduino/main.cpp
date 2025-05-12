#include <Arduino.h>
#include "BME280.hpp"
#include <SoftwareSerial.h>

BME280 BME280Sensor(0x76); // MAKING AN OBJECT WITH THE BME280 CLASS
int ledPinLow = 2;         // SETTING PIN FOR LED IN CASE OF TOO LOW HUMIDITY
int ledPinOk = 3;          // SETTING PIN FOR LED IN CASE HUMIDITY IS ACCORDING TO DESIRED SITUATION
int ledPinHigh = 4;        // SETTING PIN FOR LED IN CASE HUMIDITY IS TOO HIGH

int soilOk = 5;            // SETTING PINS FOR SOIL SENSOR
int soilLow = 6;           // SETTING PINS FOR SOIL SENSOR

float minimum = 40;        // HARD CODE MAXIMUM RELATIVE HUMIDITY
float maximum = 60;        // HARD CODE MINIMUM RELATIVE HUMIDITY

float temp; // SAVES MEASSUREMENTS OF THE BME280
float pres;
float humi;

const int dry = 595; // value for dry sensor
const int wet = 239; // value for wet sensor

SoftwareSerial mySerial(10, 11); // RX, TX 

void setup()
{
  Serial.begin(115200); // FASTER AND BETTER ACCORDING TO HAGEN
  mySerial.begin(9600); // SERIAL CONNECTION FOR UART

  pinMode(ledPinLow, OUTPUT); // SETS THE PINS AS OUTPUT
  pinMode(ledPinOk, OUTPUT);
  pinMode(ledPinHigh, OUTPUT);
  pinMode(soilOk, OUTPUT);
  pinMode(soilLow, OUTPUT);

  digitalWrite(ledPinLow, HIGH); // GIVE THE I2C TIME TO START UP!
  digitalWrite(ledPinOk, HIGH);
  digitalWrite(ledPinHigh, HIGH);
  digitalWrite(soilOk, HIGH);
  digitalWrite(soilLow, HIGH);

  delay(1000);

  digitalWrite(ledPinLow, LOW);
  digitalWrite(ledPinOk, LOW);
  digitalWrite(ledPinHigh, LOW);
  digitalWrite(soilOk, LOW);
  digitalWrite(soilLow, LOW);

  delay(1000);

  BME280Sensor.begin();

  uint8_t chipID = BME280Sensor.getChipID();

  BME280Sensor.getCalibrationData();

  BME280Sensor.setSettings();

  delay(2000);
  
  Serial.print("CHIP ID IN HEX: ");
  Serial.println(chipID, HEX);

  delay(2000);
}

void loop()
{
  int soilSensorVal = analogRead(A0); // sensor value for the soil

  BME280Sensor.getAll();
 
  int soilHumidity = map(soilSensorVal, wet, dry, 100, 0); // for soil humidity
  temp = BME280Sensor.getTemperature();
  pres = BME280Sensor.getPressure();
  humi = BME280Sensor.getHumidity();

  Serial.println("Temperature: " + String(temp));
  Serial.println("Pressure: " + String(pres));
  Serial.println("Humidity: " + String(humi));

  // UART SERIAL TO SEND DATA TO RASPBERRY PI
  mySerial.println(String(temp));
  delay(1);
  mySerial.println(String(pres));
  delay(1);
  mySerial.println(String(humi));
  delay(1);
  mySerial.println(String(soilHumidity));

  // IF STATEMENTS FOR THE HARDWARE APPLICATION
  // TURNS ON DIFFERENT LIGHTS DEPENDING ON THE HUMIDITY

  if (humi < minimum)
  {
    digitalWrite(ledPinLow, HIGH);
    digitalWrite(ledPinOk, LOW);
    digitalWrite(ledPinHigh, LOW);
    Serial.println("WARNING: HUMIDITY IS TOO LOW!!");
  }

  else if (humi >= minimum && humi <= maximum)
  {
    digitalWrite(ledPinLow, LOW);
    digitalWrite(ledPinOk, HIGH);
    digitalWrite(ledPinHigh, LOW);
    Serial.println("HUMIDITY IS JUST RIGHT!!");

  }

  else if (humi > maximum)
  {
    digitalWrite(ledPinLow, LOW);
    digitalWrite(ledPinOk, LOW);
    digitalWrite(ledPinHigh, HIGH);
    Serial.println("WARNING: HUMIDITY IS TOO HIGH!!");
  }

  if (soilHumidity < 30)
  {
    digitalWrite(soilLow, HIGH);
    digitalWrite(soilOk, LOW);
    Serial.println("WARNING: SOIL HUMIDITY IS TOO LOW!!");
  }

  else if (soilHumidity >= 30)
  {
    digitalWrite(soilLow, LOW);
    digitalWrite(soilOk, HIGH);
    Serial.println("SOIL HUMIDITY IS JUST RIGHT!!");

  }

  Serial.println("------------------------------");

  delay(2000);
}
