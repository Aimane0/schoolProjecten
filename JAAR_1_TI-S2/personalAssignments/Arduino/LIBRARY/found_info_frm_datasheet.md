### GENERAL ELECTRICAL SPECIFICATION
  - Supply Voltage\
      Min: 1.71 V\
      Max: 3.6 V\
      Operating Supply Current: 500 nA 


### HUMIDITY PARAMETER SPECIFICATION
  - Operating range\
      Degrees celsius: -40 to 85 °C\
      Relative humidity: 0 to 100 %

### PRESSURE SSENSOR SPECIFICATION
  - Operating temperature range\
      Operational: -40 to 85 °C\
      Full accuracy: 0 to 65 °C 

### TEMPERATURE SENSOR SPECIFICATION
  - Operating range\
      Operational: -40 to 85 °C\
      Full accuracy: 0 to 65 °C 

### DATA READOUT
  - To read out data after a conversion, it is strongly recommended to use a burst read and not address
every register individually. This will prevent a possible mix-up of bytes belonging to different
measurements and reduce interface traffic. Note that in I²C mode, even when pressure was not
measured, reading the unused registers is faster than reading temperature and humidity data
separately.
Data readout is done by starting a burst read from 0xF7 to 0xFC (temperature and pressure) or from
0xF7 to 0xFE (temperature, pressure and humidity). The data are read out in an unsigned 20-bit
format both for pressure and for temperature and in an unsigned 16-bit format for humidity. It is
strongly recommended to use the BME280 API, available from Bosch Sensortec, for readout and
compensation. For details on memory map and interfaces, please consult chapters 5 and 6
respectively.

  - Bladzijde 27, Table 18

  - ??????????????? 5. Global memory map and register description
5.1 General remarks
The entire communication with the device is performed by reading from and writing to registers.
Registers have a width of 8 bits. There are several registers which are reserved; they should not be
written to and no specific value is guaranteed when they are read. For details on the interface, consult
chapter 6. ???????????????????
