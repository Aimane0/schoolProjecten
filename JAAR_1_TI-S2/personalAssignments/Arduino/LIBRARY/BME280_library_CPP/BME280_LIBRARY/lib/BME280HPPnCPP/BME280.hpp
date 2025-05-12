// LIBRARY FOR THE BME280
// DIGITAL HUMIDITY, PRESSURE AND TEMPERATURE SENSOR
// WRITEN BY AIMANE CHAKIRI
// LIBRARY BASED ON BOSCH BME280 DATASHEET
// LINK TO THE DATASHEET: https://www.mouser.com/datasheet/2/783/BST-BME280-DS002-1509607.pdf

#ifndef BME280_HPP
#define BME280_HPP

#include <stdint.h>
#include <Arduino.h>
#include <Wire.h>

class BME280
{
private:
    /// @brief Struct that contains the I2C address
    const uint8_t _sensor_address;

    /// @brief Struct that contains lsb and msb for raw data bytes
    /// @details The variables have exactly the same names as in the datasheet
    struct DataBits
    {
        uint8_t hum_lsb;    // 0xFE
        uint8_t hum_msb;    // 0xFD
        uint8_t temp_xlsb;  // 0xFC
        uint8_t temp_lsb;   // 0xFB
        uint8_t temp_msb;   // 0xFA
        uint8_t press_xlsb; // 0xF9
        uint8_t press_lsb;  // 0xF8
        uint8_t press_msb;  // 0xF7
    };
    DataBits dataBits;

    /// @brief Struct that contains the adc values in bytes
    /// @details The variables have exactly the same names as in the datasheet
    struct Adc
    {
        // RAW DATA VARIABLES
        int32_t adc_T;
        int32_t adc_P;
        int32_t adc_H;
        int32_t t_fine;
    };
    Adc adc;

    /// @brief Struct that contains calibration bytes
    /// @details The variables have exactly the same names as in the datasheet
    struct CalibrationData
    {
        // CALIBRATION VARIABLES FOR TEMPERATURE
        uint16_t dig_T1;
        int16_t dig_T2;
        int16_t dig_T3;

        // CALIBRATION VARIABLES FOR PRESSURE
        uint16_t dig_P1;
        int16_t dig_P2;
        int16_t dig_P3;
        int16_t dig_P4;
        int16_t dig_P5;
        int16_t dig_P6;
        int16_t dig_P7;
        int16_t dig_P8;
        int16_t dig_P9;

        // CALIBRATION FOR HUMIDITY
        uint8_t dig_H1;
        int16_t dig_H2;
        uint8_t dig_H3;
        int16_t dig_H4;
        int16_t dig_H5;
        int8_t dig_H6;
    };
    CalibrationData calibrationData;

    /// @brief Struct that contains register addresses
    struct Registers
    {
        const int BME280_CHIPID = 0xD0;            // REGISTER ADDRESS FOR CHIP ID
        const int BME280_CALIBRATIONREG1 = 0x88;   // REGISTER FOR BURST READING dig_T1 TILL dig_P9
        const int BME280_CALIBRATIONREG2 = 0xA1;   // REGISTER FOR dig_H1
        const int BME280_CALIBRATIONREG3 = 0xE1;   // REGISTER FOR BURST READING dig_H2 TILL dig_H6
        const int BME280_MEASUREMENTREG = 0xF7;    // REGISTER FOR BURST READING TEMPERATURE TILL PRESSURE REGISTERS OR TEMP TILL HUMIDITY REGISTERS
        const int BME280_HUMIDITYSAMPLING = 0xF2;  // REGISTER FOR SETTING HUMIDITY OVERSAMPLING
        const int BME280_PRESnTEMPSAMPLING = 0xF4; // REGISTER FOR SETTING PRESSURE AND TEMPERATURE
        const int BME280_CONTROLREGISTER = 0xF5;   // REGISTER FOR SPI, STANDBY AND FILTER COEFFICIENT
    };
    Registers registers;

    /// @brief Function to calibrate the recieved and fitting adc values 
    /// @param adc_T raw temperature data
    /// @return calibrated temperature
    float getCalibratedTemperature(int32_t adc_T);

    /// @brief Function to calibrate the recieved and fitting adc values
    /// @param adc_T raw pressure data
    /// @return calibrated pressure
    float getCalibratedPressure(int32_t adc_P);

    /// @brief Function to calibrate the recieved and fitting adc values 
    /// @param adc_T raw humidity data
    /// @return calibrated humidity
    float getCalibratedHumidity(int32_t adc_H);

public:
    /// @brief constructor of the class
    /// @param sensor_address I2C address
    BME280(uint8_t sensor_address);

    /// @brief starts the wire.h communication
    void begin();

    /// @brief gets the calibration data necessary to calibrate measurements
    void getCalibrationData();

    /// @brief gets the adc values
    void getAll();

    /// @brief gets the chip ID
    /// @return the chip ID 
    uint8_t getChipID();

    /// @brief sets chip configurations to indoor navigation
    void setSettings();

    /// @brief gets the measured temperature    
    /// @return temperature
    float getTemperature();

    /// @brief gets the measured pressure    
    /// @return pressure
    float getPressure();

    /// @brief gets the measured pressure    
    /// @return pressure
    float getHumidity();
};

#endif