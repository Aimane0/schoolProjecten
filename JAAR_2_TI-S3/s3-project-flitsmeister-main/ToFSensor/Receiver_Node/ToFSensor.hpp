#ifndef TOFSENSOR_HPP
#define TOFSENSOR_HPP

#include <stdint.h>
#include <Arduino.h>
#include <Wire.h>

class ToFSensor {
private:
    /// @brief Struct for receiving and saving the most and least significant bytes
    struct DataBits {
        uint8_t DISTANCE_LSB;
        uint8_t DISTANCE_MSB;
        uint8_t MODE;
    };
    DataBits dataBits;

    /// @brief Struct that contains addresses necessary for I2C communication
    struct Registers {
        uint8_t I2CADRESS = 0x10;
        uint8_t DIST_LSB_ADRESS = 0x00;
        uint8_t DIST_MSB_ADRESS = 0x01;
        uint8_t MODE = 0x23;
    };
    Registers registers;

    struct Measurement {
        uint16_t MEASUREMENT;
    };
    Measurement measurement;

public:
    ToFSensor();

    /// @brief Starts the wire protocol
    void begin();

    /// @brief Checks if mode is in continuous ranging mode
    void requestMode();

    /// @brief Prints the mode that the sensor is set in
    void printMode();

    /// @brief Requests the least and most significant bytes necessary for getting the measured distance
    void requestBytes();

    /// @brief Shifts the most and least significant bytes to make a 16-bit integer that shows the measured distance
    void shiftBytes();

    /// @brief Returns a uint16_t that is the measured distance
    uint16_t getDistance();
};

#endif