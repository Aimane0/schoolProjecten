#include "ToFSensor.hpp"
#include <Arduino.h>
#include <Wire.h>

ToFSensor::ToFSensor() : dataBits(), registers(), measurement() {}

// Defines BEGIN function
void ToFSensor::begin() {
    Wire.begin();
}

// Defines GETMODE
void ToFSensor::requestMode() {
    Wire.beginTransmission(registers.I2CADRESS);
    Wire.write(registers.MODE);
    Wire.endTransmission();
    Wire.requestFrom(registers.I2CADRESS, 1);

    if (Wire.available()) {
        dataBits.MODE = Wire.read();
    }
}

void ToFSensor::printMode() {
    Serial.println(dataBits.MODE);
}

void ToFSensor::requestBytes() {
    Wire.beginTransmission(registers.I2CADRESS);
    Wire.write(registers.DIST_LSB_ADRESS);
    Wire.endTransmission();
    Wire.requestFrom(registers.I2CADRESS, 2);

    dataBits.DISTANCE_LSB = Wire.read();
    dataBits.DISTANCE_MSB = Wire.read();
    
}

void ToFSensor::shiftBytes() {
    measurement.MEASUREMENT = (dataBits.DISTANCE_MSB << 8) | dataBits.DISTANCE_LSB;
}

uint16_t ToFSensor::getDistance() {
    return measurement.MEASUREMENT;
}