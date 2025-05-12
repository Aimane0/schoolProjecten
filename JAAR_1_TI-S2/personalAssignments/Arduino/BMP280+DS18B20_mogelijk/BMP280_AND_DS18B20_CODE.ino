/***************************************************************************
  This is a library for the BMP280 humidity, temperature & pressure sensor

  Designed specifically to work with the Adafruit BMP280 Breakout
  ----> http://www.adafruit.com/products/2651

  These sensors use I2C or SPI to communicate, 2 or 4 pins are required
  to interface.

  Adafruit invests time and resources providing this open source code,
  please support Adafruit andopen-source hardware by purchasing products
  from Adafruit!

  Written by Limor Fried & Kevin Townsend for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ***************************************************************************/

/***************************************************************************

Deze code is klassikaal met ons gedeeld om de BMP280 uit te proberen.

 ***************************************************************************/
// BELANGRIJKE INFORMATIE!//
// DE BMP280 KAN GEBOUWD WORDEN ZOALS OP HET VOORBEELD! //
// DE ONE WIRE SENSOR MOET IN PIN 7! //


// ONDERDEEL BMP280
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>
// EIND BMP280

// ONDERDEEL DS18B20
#include <OneWire.h>
#include <DallasTemperature.h>
// EIND DS18B20

// ONDERDEEL BMP280
#define BMP_SCK (13)
#define BMP_MISO (12)
#define BMP_MOSI (11)
#define BMP_CS (10)
// EIND BMP280

// ONDERDEEL DS18B29
float temp = 0.0;
int oneWireBus = 7; // SENSOR IN PIN 7 STEKEN!
OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);
// EIND DS18B20

//Adafruit_BMP280 bmp; // I2C
Adafruit_BMP280 bmp(BMP_CS);  // hardware SPI
//Adafruit_BMP280 bmp(BMP_CS, BMP_MOSI, BMP_MISO,  BMP_SCK);

void setup() {
  // CODE BMP280
  Serial.begin(9600);
  Serial.println("1-Wire DS18B20 waterproof test");  //CODE DS18B20
  Serial.println(F("BMP280 test"));                                                   //CODE BMP280
  sensors.begin();                                                                    
  while (!Serial) delay(100);                                                         // wait for native usb
  unsigned status;
  //status = bmp.begin(BMP280_ADDRESS_ALT, BMP280_CHIPID);
  status = bmp.begin();
  if (!status) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring or "
                     "try a different address!"));
    Serial.print("SensorID was: 0x");
    Serial.println(bmp.sensorID(), 16);
    Serial.print("        ID of 0xFF probably means a bad address, a BMP 180 or BMP 085\n");
    Serial.print("   ID of 0x56-0x58 represents a BMP 280,\n");
    Serial.print("        ID of 0x60 represents a BME 280.\n");
    Serial.print("        ID of 0x61 represents a BME 680.\n");
    while (1) delay(10);
  }

  /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
}

void loop() {
  Serial.print(F("Temperature of BMP280 = "));
  Serial.print(bmp.readTemperature());
  Serial.println(" *C");

  Serial.print(F("Pressure of BMP280 = "));
  Serial.print(bmp.readPressure());
  Serial.println(" Pa");

  Serial.print(F("Approx altitude BMP280 = "));
  Serial.print(bmp.readAltitude(1013.25)); /* Adjusted to local forecast! */
  Serial.println(" m");

  Serial.println();

  sensors.requestTemperatures();
  temp = sensors.getTempCByIndex(0);

  Serial.print("Temperature reading DS18B20: ");
  Serial.println(temp);

  delay(5000);
}