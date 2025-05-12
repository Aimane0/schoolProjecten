#include <Arduino.h>
#include "BME280.hpp"

BME280 BME280Sensor(0x76); // MAKING AN OBJECT WITH THE BME280 CLASS
int ledPinLow = 2;         // SETTING PIN FOR LED IN CASE OF TOO LOW HUMIDITY
int ledPinOk = 3;          // SETTING PIN FOR LED IN CASE HUMIDITY IS ACCORDING TO DESIRED SITUATION
int ledPinHigh = 4;        // SETTING PIN FOR LED IN CASE HUMIDITY IS TOO HIGH

const int in1Pin = 6;      // PIN IN1 ON THE BRIDGE
const int in2Pin = 5;      // PIN IN2 ON THE BRIDGE
const int enaPin = 9;      // PIN ENA ON THE BRIDGE

const int fanPin = 3;
const int fanSpeed = 255;

float minimum; // SAVES USER INPUT
float maximum;

float temp; // SAVES MEASSUREMENTS OF THE BME280
float pres;
float humi;

void setup()
{
  Serial.begin(115200); // FASTER AND BETTER ACCORDING TO HAGEN

  pinMode(ledPinLow, OUTPUT); // SETS THE PINS AS OUTPUT
  pinMode(ledPinOk, OUTPUT);
  pinMode(ledPinHigh, OUTPUT);

  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(enaPin, OUTPUT);

  pinMode(fanPin, OUTPUT);

  digitalWrite(ledPinLow, HIGH); // GIVE THE I2C TIME TO START UP!
  digitalWrite(ledPinOk, HIGH);
  digitalWrite(ledPinHigh, HIGH);

  delay(1000);

  digitalWrite(ledPinLow, LOW);
  digitalWrite(ledPinOk, LOW);
  digitalWrite(ledPinHigh, LOW);

  delay(1000);

  digitalWrite(enaPin, HIGH);

  BME280Sensor.begin();

  Serial.println("Give a minimum relative humidity percentage: ");
  while (Serial.available() == 0)
    ; // ASKS USER FOR INPUT

  minimum = Serial.parseFloat();

  Serial.println("Give a maximum relative humidity percentage: ");
  while (Serial.available() == 0)
    ; // ASKS USER FOR INPUT

  maximum = Serial.parseFloat();

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
  BME280Sensor.getAll();

  temp = BME280Sensor.getTemperature();
  pres = BME280Sensor.getPressure();
  humi = BME280Sensor.getHumidity();

  Serial.println("Temperature: " + String(temp));
  Serial.println("Pressure: " + String(pres));
  Serial.println("Humidity: " + String(humi));

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

    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, HIGH);
    Serial.println("HUMIDITY IS JUST RIGHT!!");
  }

  else if (humi > maximum)
  {
    digitalWrite(ledPinLow, LOW);
    digitalWrite(ledPinOk, LOW);
    digitalWrite(ledPinHigh, HIGH);

    digitalWrite(in1Pin, HIGH);
    digitalWrite(in2Pin, LOW);
    Serial.println("WARNING: HUMIDITY IS TOO HIGH!!");
  }

  if (temp > 28){
    analogWrite(fanPin, fanSpeed);
  }
  else if (temp < 28){
    analogWrite(fanPin, 1);
  }
  Serial.println("------------------------------");

  delay(2000);
}