#include "BME280.hpp"
#include <Arduino.h>
#include <Wire.h>
#include <stdint.h>

BME280::BME280(uint8_t sensor_address) : _sensor_address(sensor_address) {}

void BME280::begin()
{
    Wire.begin();
}

uint8_t BME280::getChipID()
{
    const int quantity = 1;
    Wire.beginTransmission(_sensor_address);
    Wire.write(registers.BME280_CHIPID);
    Wire.endTransmission();
    Wire.requestFrom(_sensor_address, quantity);

    int8_t chipID = Wire.read();

    return chipID;
}

void BME280::getCalibrationData()
{
    Wire.beginTransmission(_sensor_address);      // STARTS TRANSMISSION TO BME280
    Wire.write(registers.BME280_CALIBRATIONREG1); // WRITES FIRST ADDRESS OF CALIBRATION REGISTERS
    Wire.endTransmission();                       // ENDS TRANSMISSION
    Wire.requestFrom(_sensor_address, 24);        // REQUESTS BYTES FROM THE BME280

    // WRITES THE BITS REQUESTED FROM THE Wire.requestFrom(_sensor_address, 33)
    // THESE ARE CALIBRATION BYTES ACCORDING TO THE DATASHEET
    // NECESSARY TO CALCULATE THE READINGS DONE BY THE SENSOR
    calibrationData.dig_T1 = (uint16_t)((Wire.read() | Wire.read() << 8));
    calibrationData.dig_T2 = (int16_t)((Wire.read() | Wire.read() << 8));
    calibrationData.dig_T3 = (int16_t)((Wire.read() | Wire.read() << 8));

    calibrationData.dig_P1 = (uint16_t)((Wire.read() | Wire.read() << 8));
    calibrationData.dig_P2 = (int16_t)((Wire.read() | Wire.read() << 8));
    calibrationData.dig_P3 = (int16_t)((Wire.read() | Wire.read() << 8));
    calibrationData.dig_P4 = (int16_t)((Wire.read() | Wire.read() << 8));
    calibrationData.dig_P5 = (int16_t)((Wire.read() | Wire.read() << 8));
    calibrationData.dig_P6 = (int16_t)((Wire.read() | Wire.read() << 8));
    calibrationData.dig_P7 = (int16_t)((Wire.read() | Wire.read() << 8));
    calibrationData.dig_P8 = (int16_t)((Wire.read() | Wire.read() << 8));
    calibrationData.dig_P9 = (int16_t)((Wire.read() | Wire.read() << 8));

    Wire.beginTransmission(_sensor_address);      // STARTS TRANSMISSION TO BME280
    Wire.write(registers.BME280_CALIBRATIONREG2); // WRITES FIRST ADDRESS OF CALIBRATION REGISTERS
    Wire.endTransmission();                       // ENDS TRANSMISSION
    Wire.requestFrom(_sensor_address, 1);         // REQUESTS BYTES FROM THE BME280

    // Interessante feedback:
    // Probeer 0x88 tot en met 0xA1 te lezen als dat kan
    // Een reeks uitlezen gaat sneller dan dat niet doen.
    // Het verschil tussen 9F en A1 is namelijk maar 2 bytes

    calibrationData.dig_H1 = (uint8_t)(Wire.read());

    Wire.beginTransmission(_sensor_address);      // STARTS TRANSMISSION TO BME280
    Wire.write(registers.BME280_CALIBRATIONREG3); // WRITES FIRST ADDRESS OF CALIBRATION REGISTERS
    Wire.endTransmission();                       // ENDS TRANSMISSION
    Wire.requestFrom(_sensor_address, 8);         // REQUESTS BYTES FROM THE BME280

    calibrationData.dig_H2 = (int16_t)(Wire.read() | (Wire.read() << 8));
    calibrationData.dig_H3 = (uint8_t)(Wire.read());
    uint8_t e4 = Wire.read();
    uint8_t e5 = Wire.read();
    uint8_t e6 = Wire.read();
    calibrationData.dig_H6 = (int8_t)(Wire.read());

    calibrationData.dig_H4 = (int16_t)((e4 << 4) | (e5 & 0x0F)); // 0x0F == 0b00001111
                                                                 // BY USING THE & OPERATOR 0;3 STAY ONES IF THEY ARE, 4;7 TURN INTO 0's BECAUSE WE ONLY NEED 0;3

    calibrationData.dig_H5 = (int16_t)(((e5 & 0xF0) >> 4) | (e6 << 4)); // 0xF0 == 0b11110000
                                                                        // BY USING THE & OPERATOR 0;3 TURN INTO 0's IF THEY ARE 0 AND 4;7 STAY 1's
                                                                        // THE & OPERATOR COMPARES e5 and 0xF0
                                                                        // WHEN THE SAME INDEX IS A 1, THE & OPERATOR MAKES A NEW BYTE WITH A 1 ON THAT SAME INDEX
}

float BME280::getCalibratedTemperature(int32_t TT)
{
    // COMPENSATION FORMULAS CAN BE READ ON PAGE 25 AND 26; 4.2.3 Compensation formulas
    int32_t var1, var2, T;
    var1 = ((((TT >> 3) - ((int32_t)calibrationData.dig_T1 << 1))) * ((int32_t)calibrationData.dig_T2)) >> 11;
    var2 = (((((TT >> 4) - ((int32_t)calibrationData.dig_T1)) * ((TT >> 4) - ((int32_t)calibrationData.dig_T1))) >> 12) * ((int32_t)calibrationData.dig_T3)) >> 14;
    adc.t_fine = var1 + var2;
    T = (adc.t_fine * 5 + 128) >> 8;
    float finalTemperature = T / 100.0;

    return finalTemperature;
}

float BME280::getCalibratedPressure(int32_t P)
{
    // COMPENSATION FORMULAS CAN BE READ ON PAGE 25 AND 26; 4.2.3 Compensation formulas
    int64_t var1, var2, p;
    var1 = (adc.t_fine) - 128000;
    var2 = var1 * var1 * (int64_t)calibrationData.dig_P6;
    var2 = var2 + ((var1 * (int64_t)calibrationData.dig_P5) << 17);
    var2 = var2 + (((int64_t)calibrationData.dig_P4) << 35);
    var1 = ((var1 * var1 * (int64_t)calibrationData.dig_P3) >> 8) + ((var1 * (int64_t)calibrationData.dig_P2) << 12);
    var1 = (((((int64_t)1) << 47) + var1)) * ((int64_t)calibrationData.dig_P1) >> 33;

    p = 1048576 - P;
    p = (((p << 31) - var2) * 3125) / var1;
    var1 = (((int64_t)calibrationData.dig_P9) * (p >> 13) * (p >> 13)) >> 25;
    var2 = (((int64_t)calibrationData.dig_P8) * p) >> 19;
    p = ((p + var1 + var2) >> 8) + (((int64_t)calibrationData.dig_P7) << 4);
    uint32_t p2 = p;
    float Pa = p2 / 256;
    float hPa = Pa / 100;

    return hPa;
}

float BME280::getCalibratedHumidity(int32_t H)
{
    // COMPENSATION FORMULAS CAN BE READ ON PAGE 25 AND 26; 4.2.3 Compensation formulas
    int32_t v_x1_u32r;
    v_x1_u32r = (adc.t_fine - ((int32_t)76800));
    v_x1_u32r = (((((H << 14) - (((int32_t)calibrationData.dig_H4) << 20) - (((int32_t)calibrationData.dig_H5) * v_x1_u32r)) + ((int32_t)16384)) >> 15) * (((((((v_x1_u32r * ((int32_t)calibrationData.dig_H6)) >> 10) * (((v_x1_u32r * ((int32_t)calibrationData.dig_H3)) >> 11) + ((int32_t)32768))) >> 10) + ((int32_t)2097152)) * ((int32_t)calibrationData.dig_H2) + 8192) >> 14));
    v_x1_u32r = (v_x1_u32r - (((((v_x1_u32r >> 15) * (v_x1_u32r >> 15)) >> 7) * ((int32_t)calibrationData.dig_H1)) >> 4));
    v_x1_u32r = (v_x1_u32r < 0 ? 0 : v_x1_u32r);
    v_x1_u32r = (v_x1_u32r > 419430400 ? 419430400 : v_x1_u32r);
    float outputValue = (uint32_t)(v_x1_u32r >> 12);
    float humidity = outputValue / 1000.0;

    return humidity;
}

void BME280::getAll()
{
    // READING REGISTERS TO GET DATA ABOUT THE HUMIDITY, PRESSURE AND TEMP IS BASED ON ADDRESSES SHOWN IN CHAPTER 5.

    Wire.beginTransmission(_sensor_address);     // STARTS TRANSMISSION TO BME280
    Wire.write(registers.BME280_MEASUREMENTREG); // WRITES TO PRESS_MSB REGISTERS
    Wire.endTransmission();                      // ENDS TRANSMISSION
    Wire.requestFrom(_sensor_address, 8);        // REQUESTS BYTES FROM THE BME280, REQUESTING 8 TILL HUM_LSB

    dataBits.press_msb = Wire.read();  // 0xF7
    dataBits.press_lsb = Wire.read();  // 0xF8
    dataBits.press_xlsb = Wire.read(); // 0xF9
    dataBits.temp_msb = Wire.read();   // 0xFA
    dataBits.temp_lsb = Wire.read();   // 0xFB
    dataBits.temp_xlsb = Wire.read();  // 0xFC
    dataBits.hum_msb = Wire.read();    // 0xFD
    dataBits.hum_lsb = Wire.read();    // 0xFE

    // COMBING THE MSB LSB AND XLSB INTO A 32 BYTE BIT
    adc.adc_T = ((int32_t)dataBits.temp_msb << 12) | ((int32_t)dataBits.temp_lsb << 4) | (dataBits.temp_xlsb >> 4);

    adc.adc_P = ((int32_t)dataBits.press_msb << 12) | ((int32_t)dataBits.press_lsb << 4) | (dataBits.press_xlsb >> 4);

    adc.adc_H = ((int16_t)dataBits.hum_msb << 8) | (dataBits.hum_lsb);
}

float BME280::getTemperature()
{
    float temperature = getCalibratedTemperature(adc.adc_T);

    return temperature;
}

float BME280::getPressure()
{

    float pressure = getCalibratedPressure(adc.adc_P);

    return pressure;
}

float BME280::getHumidity()
{

    float humidity = getCalibratedHumidity(adc.adc_H);

    return humidity;
}


void BME280::setSettings()
{
    Wire.beginTransmission(_sensor_address);
    Wire.write(registers.BME280_HUMIDITYSAMPLING); // HUMIDITY OVERSAMPLING REGISTER
    Wire.write(0x01);                              // HUMIDITY OVERSAMPLING TIMES 1x
    Wire.endTransmission();

    Wire.beginTransmission(_sensor_address);
    Wire.write(registers.BME280_PRESnTEMPSAMPLING); // CONTROL REGISTER
    Wire.write(0x57);                               // PRESSURE AND TEMEPRATURE OVERSAMPLING 16X PRESS // 01010111
    Wire.endTransmission();

    Wire.beginTransmission(_sensor_address);
    Wire.write(registers.BME280_CONTROLREGISTER); // CONFIG REGISTER
    Wire.write(0x08);                             // SPI TURNED OFF = 0, T STANDBY 0.5 MS, FILTER COEFFICIENT 16, 0001000
    Wire.endTransmission();
}
