#include <Arduino.h>
#include <SoftwareSerial.h>

const int in1Pin = 6;  // PIN IN1 ON THE BRIDGE
const int in2Pin = 5;  // PIN IN2 ON THE BRIDGE
const int enaPin = 9;  // PIN ENA ON THE BRIDGE

const int fanPin = 3;
const int fanSpeed = 255;

SoftwareSerial mySerial(10, 11);  // RX, TX

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);

  pinMode(fanPin, OUTPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);

  digitalWrite(enaPin, HIGH);
}

void loop() {
  float temp = (mySerial.readStringUntil('\n')).toFloat();
  mySerial.read();
  float pres = (mySerial.readStringUntil('\n')).toFloat();
  mySerial.read();
  float humi = (mySerial.readStringUntil('\n')).toFloat();
  mySerial.read();
  float soil = (mySerial.readStringUntil('\n')).toFloat();
  mySerial.read();
  if (!(temp == 0.00 || pres == 0.00 || humi == 0.00 || soil == 0.00)) {
    Serial.println("temp" + String(temp));
    Serial.println(pres);
    Serial.println(humi);
    Serial.println(soil);

    if (temp > 28) {
      analogWrite(fanPin, fanSpeed);
    } 
    else if (temp < 28) {
      analogWrite(fanPin, 30);
    }

    if (humi > 60) {
      digitalWrite(in1Pin, HIGH);
      digitalWrite(in2Pin, LOW);
      delay(2000);
    }

    else if (humi < 40) {
      digitalWrite(in1Pin, LOW);
      digitalWrite(in2Pin, HIGH);
      delay(2000);
    }
  }
}
