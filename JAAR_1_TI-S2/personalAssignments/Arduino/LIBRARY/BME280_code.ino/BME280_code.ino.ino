// LIBRARY FOR THE BME280
// DIGITAL HUMIDITY, PRESSURE AND TEMPERATURE SENSOR
// WRITEN BY AIMANE CHAKIRI
// LIBRARY BASED ON BOSCH BME280 DATASHEET
// LINK TO THE DATASHEET: https://www.mouser.com/datasheet/2/783/BST-BME280-DS002-1509607.pdf

#include <Wire.h>

#define BME280_ADDRESS 0x76  // I2C ADDRESS OF THE BME280 SENSOR

// VARIABELS TO SAVE THE REQUESTED REGISTER DATA
// HUM = HUMIDITY
// TEMP = TEMPERATURE
// PRESS = PRESSURE
// LSB = LEAST SIGNIFICANT BYTE
// XLSB = ?
// MSB = MOST SIGNIFICANT BYTE
uint8_t hum_lsb;     // 0xFE
uint8_t hum_msb;     // 0xFD
uint8_t temp_xlsb;   // 0xFC
uint8_t temp_lsb;    // 0xFB
uint8_t temp_msb;    // 0xFA
uint8_t press_xlsb;  // 0xF9
uint8_t press_lsb;   // 0xF8
uint8_t press_msb;   // 0xF7
uint8_t config;      // 0xF5

// RAW DATA VARIABLES
int32_t adc_T;
int32_t adc_P;
int32_t adc_H;
int32_t t_fine;

// COMPENSATION PARAMETERS
//
// UNSIGNED SHORT = uint16_t
// SIGNED SHORT = int16_t
// UNSIGNED CHAR = uint8_t
// SIGNED CHAR = int8_t

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

void setup() {
  Wire.begin();        // STARTS WIRE.H
  Serial.begin(9600);  // STARTS SERIAL CONNECTION

  delay(2000);

  // REQUESTS CHIP ID
  Wire.beginTransmission(BME280_ADDRESS);
  Wire.write(0xD0);
  Wire.endTransmission();
  Wire.requestFrom(BME280_ADDRESS, 1);

  int8_t chipID = Wire.read();

  // PRINTS CHIP ID, SHOULD BE 60
  Serial.print("CHIP ID IN HEX: ");
  Serial.println(chipID, HEX);

  Wire.beginTransmission(BME280_ADDRESS);  // STARTS TRANSMISSION TO BME280
  Wire.write(0x88);                        // WRITES FIRST ADDRESS OF CALIBRATION REGISTERS
  Wire.endTransmission();                  // ENDS TRANSMISSION
  Wire.requestFrom(BME280_ADDRESS, 24);    // REQUESTS BYTES FROM THE BME280

  // WRITES THE BITS REQUESTED FROM THE Wire.requestFrom(BME280_ADDRESS, 33)
  // THESE ARE CALIBRATION BYTES ACCORDING TO THE DATASHEET
  // NECESSARY TO CALCULATE THE READINGS DONE BY THE SENSOR
  dig_T1 = (uint16_t)((Wire.read() | Wire.read() << 8));
  dig_T2 = (int16_t)((Wire.read() | Wire.read() << 8));
  dig_T3 = (int16_t)((Wire.read() | Wire.read() << 8));

  dig_P1 = (uint16_t)((Wire.read() | Wire.read() << 8));
  dig_P2 = (int16_t)((Wire.read() | Wire.read() << 8));
  dig_P3 = (int16_t)((Wire.read() | Wire.read() << 8));
  dig_P4 = (int16_t)((Wire.read() | Wire.read() << 8));
  dig_P5 = (int16_t)((Wire.read() | Wire.read() << 8));
  dig_P6 = (int16_t)((Wire.read() | Wire.read() << 8));
  dig_P7 = (int16_t)((Wire.read() | Wire.read() << 8));
  dig_P8 = (int16_t)((Wire.read() | Wire.read() << 8));
  dig_P9 = (int16_t)((Wire.read() | Wire.read() << 8));

  Wire.beginTransmission(BME280_ADDRESS);  // STARTS TRANSMISSION TO BME280
  Wire.write(0xA1);                        // WRITES FIRST ADDRESS OF CALIBRATION REGISTERS
  Wire.endTransmission();                  // ENDS TRANSMISSION
  Wire.requestFrom(BME280_ADDRESS, 1);     // REQUESTS BYTES FROM THE BME280
  
                                           // Interessante feedback:
                                           // Probeer 0x88 tot en met 0xA1 te lezen als dat kan
                                           // Een reeks uitlezen gaat sneller dan dat niet doen.
                                           // Het verschil tussen 9F en A1 is namelijk maar 2 bytes

  dig_H1 = (uint8_t)(Wire.read());

  Wire.beginTransmission(BME280_ADDRESS);  // STARTS TRANSMISSION TO BME280
  Wire.write(0xE1);                        // WRITES FIRST ADDRESS OF CALIBRATION REGISTERS
  Wire.endTransmission();                  // ENDS TRANSMISSION
  Wire.requestFrom(BME280_ADDRESS, 8);     // REQUESTS BYTES FROM THE BME280

  dig_H2 = (int16_t)(Wire.read() | (Wire.read() << 8));
  dig_H3 = (uint8_t)(Wire.read());
  uint8_t e4 = Wire.read();
  uint8_t e5 = Wire.read();
  uint8_t e6 = Wire.read();
  dig_H6 = (int8_t)(Wire.read());

  dig_H4 = (int16_t)((e4 << 4) | (e5 & 0x0F)); // 0x0F == 0b00001111
                                               // BY USING THE & OPERATOR 0;3 STAY ONES IF THEY ARE, 4;7 TURN INTO 0's BECAUSE WE ONLY NEED 0;3

  dig_H5 = (int16_t)(((e5 & 0xF0) >> 4) | (e6 << 4)); // 0xF0 == 0b11110000
                                                      // BY USING THE & OPERATOR 0;3 TURN INTO 0's IF THEY ARE 0 AND 4;7 STAY 1's
                                                      // THE & OPERATOR COMPARES e5 and 0xF0
                                                      // WHEN THE SAME INDEX IS A 1, THE & OPERATOR MAKES A NEW BYTE WITH A 1 ON THAT SAME INDEX

  // CONFIGURATION SETTINGS
  Wire.beginTransmission(BME280_ADDRESS);
  Wire.write(0xF2);  // HUMIDITY OVERSAMPLING REGISTER
  Wire.write(0x01);  // HUMIDITY OVERSAMPLING TIMES 1x
  Wire.endTransmission();

  Wire.beginTransmission(BME280_ADDRESS);
  Wire.write(0xF4);  // CONTROL REGISTER
  Wire.write(0x2F);  // PRESSURE AND TEMEPRATURE OVERSAMPLING 16X PRESS, 2x TEMP // 01010111
  Wire.endTransmission();

  Wire.beginTransmission(BME280_ADDRESS);
  Wire.write(0xF5);  // CONFIG REGISTER
  Wire.write(0x08);  // SPI TURNED OFF = 0, T STANDBY 0.5 MS, FILTER COEFFICIENT 16, 0001000
  Wire.endTransmission();

  delay(1000);
}

void loop() {
  //readTemperatureAndPressure();
  readBurstAll();
  delay(3000);
}

// FUNCTIONS

void readTemperatureAndPressure() {
  Wire.beginTransmission(BME280_ADDRESS);
  Wire.write(0xF7);
  Wire.endTransmission();
  Wire.requestFrom(BME280_ADDRESS, 6);

  press_msb = Wire.read();   // 0xF7
  press_lsb = Wire.read();   // 0xF8
  press_xlsb = Wire.read();  // 0xF9
  temp_msb = Wire.read();    // 0xFA
  temp_lsb = Wire.read();    // 0xFB
  temp_xlsb = Wire.read();   // 0xFC

  // COMBING THE MSB LSB AND XLSB INTO A 32 BYTE BIT
  adc_T = ((int32_t)temp_msb << 12) | ((int32_t)temp_lsb << 4) | (temp_xlsb >> 4);

  adc_P = ((int32_t)press_msb << 12) | ((int32_t)press_lsb << 4) | (press_xlsb >> 4);

  calibrateTemperature(adc_T);
  calibratePressure(adc_P);
}

void readBurstAll() {
  // READING REGISTERS TO GET DATA ABOUT THE HUMIDITY, PRESSURE AND TEMP IS BASED ON ADDRESSES SHOWN IN CHAPTER 5.

  Wire.beginTransmission(BME280_ADDRESS);  // STARTS TRANSMISSION TO BME280
  Wire.write(0xF7);                        // WRITES TO PRESS_MSB REGISTERS
  Wire.endTransmission();                  // ENDS TRANSMISSION
  Wire.requestFrom(BME280_ADDRESS, 8);     // REQUESTS BYTES FROM THE BME280, REQUESTING 8 TILL HUM_LSB

  press_msb = Wire.read();   // 0xF7
  press_lsb = Wire.read();   // 0xF8
  press_xlsb = Wire.read();  // 0xF9
  temp_msb = Wire.read();    // 0xFA
  temp_lsb = Wire.read();    // 0xFB
  temp_xlsb = Wire.read();   // 0xFC
  hum_msb = Wire.read();     // 0xFD
  hum_lsb = Wire.read();     // 0xFE

  // COMBING THE MSB LSB AND XLSB INTO A 32 BYTE BIT
  adc_T = ((int32_t)temp_msb << 12) | ((int32_t)temp_lsb << 4) | (temp_xlsb >> 4);

  adc_P = ((int32_t)press_msb << 12) | ((int32_t)press_lsb << 4) | (press_xlsb >> 4);

  adc_H = ((int16_t)hum_msb << 8) | (hum_lsb);

  calibrateTemperature(adc_T);
  calibratePressure(adc_P);
  calibrateHumidity(adc_H);
}

// FUNCTIONS FOR CALIBRATING RAW DATA
void calibrateTemperature(int32_t adc_T) {

  // COMPENSATION FORMULAS CAN BE READ ON PAGE 25 AND 26; 4.2.3 Compensation formulas
  int32_t var1, var2, T;
  var1 = ((((adc_T >> 3) - ((int32_t)dig_T1 << 1))) * ((int32_t)dig_T2)) >> 11;
  var2 = (((((adc_T >> 4) - ((int32_t)dig_T1)) * ((adc_T >> 4) - ((int32_t)dig_T1))) >> 12) * ((int32_t)dig_T3)) >> 14;
  t_fine = var1 + var2;
  T = (t_fine * 5 + 128) >> 8;
  float finalTemperature = T / 100.0;

  Serial.println("Temperature in celsius: " + String(finalTemperature));
}

void calibratePressure(int32_t adc_P) {

  // COMPENSATION FORMULAS CAN BE READ ON PAGE 25 AND 26; 4.2.3 Compensation formulas
  int64_t var1, var2, p;
  var1 = (t_fine)-128000;
  var2 = var1 * var1 * (int64_t)dig_P6;
  var2 = var2 + ((var1 * (int64_t)dig_P5) << 17);
  var2 = var2 + (((int64_t)dig_P4) << 35);
  var1 = ((var1 * var1 * (int64_t)dig_P3) >> 8) + ((var1 * (int64_t)dig_P2) << 12);
  var1 = (((((int64_t)1) << 47) + var1)) * ((int64_t)dig_P1) >> 33;

  p = 1048576 - adc_P;
  p = (((p << 31) - var2) * 3125) / var1;
  var1 = (((int64_t)dig_P9) * (p >> 13) * (p >> 13)) >> 25;
  var2 = (((int64_t)dig_P8) * p) >> 19;
  p = ((p + var1 + var2) >> 8) + (((int64_t)dig_P7) << 4);
  uint32_t p2 = p;
  float Pa = p2 / 256;
  float hPa = Pa / 100;
  if (hPa < 7) {
    Serial.println("Measuring hPa");
  } else {
    Serial.println("Pressure in hPa: " + String(hPa));
  }
}

void calibrateHumidity(int32_t adc_H) {

  // COMPENSATION FORMULAS CAN BE READ ON PAGE 25 AND 26; 4.2.3 Compensation formulas
  int32_t v_x1_u32r;
  v_x1_u32r = (t_fine - ((int32_t)76800));
  v_x1_u32r = (((((adc_H << 14) - (((int32_t)dig_H4) << 20) - (((int32_t)dig_H5) * v_x1_u32r)) + ((int32_t)16384)) >> 15) * (((((((v_x1_u32r * ((int32_t)dig_H6)) >> 10) * (((v_x1_u32r * ((int32_t)dig_H3)) >> 11) + ((int32_t)32768))) >> 10) + ((int32_t)2097152)) * ((int32_t)dig_H2) + 8192) >> 14));
  v_x1_u32r = (v_x1_u32r - (((((v_x1_u32r >> 15) * (v_x1_u32r >> 15)) >> 7) * ((int32_t)dig_H1)) >> 4));
  v_x1_u32r = (v_x1_u32r < 0 ? 0 : v_x1_u32r);
  v_x1_u32r = (v_x1_u32r > 419430400 ? 419430400 : v_x1_u32r);
  float outputValue = (uint32_t)(v_x1_u32r >> 12);
  float humidity = outputValue / 1000.0;

  Serial.println("Humidity in %RH: " + String(humidity));
}