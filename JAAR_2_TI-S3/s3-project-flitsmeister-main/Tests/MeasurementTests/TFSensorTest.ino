// ESP32 besturing van de startende TF Luna 

#include <Wire.h>
#include <Arduino.h>

// I2C address volgens datasheet
#define I2C_ADRESS 0x10        // I2C-adres volgens datasheet
#define DIST_LOW_ADRESS 0x00   // LSB adres
#define DIST_HIGH_ADRESS 0x01  // MSB adres

uint16_t distance;

void viewDistance() {
  Wire.beginTransmission(I2C_ADRESS); // Transmission beginnen naar I2C adres
  Wire.write(DIST_LOW_ADRESS);  // Begint transmission bij de LSB
  Wire.endTransmission();
  Wire.requestFrom(I2C_ADRESS, 2);  // Vraag 2 bytes op de LSB en MSB

  if (Wire.available() >= 2) {        
    uint8_t dist_low = Wire.read();   // Lees LSB
    uint8_t dist_high = Wire.read();  // Lees MSB

    // Combineer tot 16 bytes
    uint16_t measuredDistance = (dist_high << 8) | dist_low;

    distance = measuredDistance;
  }
}

void setup() {
  Wire.begin();
  Serial.begin(115200);
}

void loop() {
  viewDistance();

  // PAS DEZE DRIE INTEGERS AAN OM DE FOUTMARGE AAN TE PASSEN!
  int goal = 30;
  int minValue = goal - 6;
  int maxValue = goal + 6;

  if (distance < minValue || distance > maxValue){
  Serial.println("Distance is outside of the margin of error");
  } else {
  Serial.println(distance);
  }

  delay(300);  // Herhaal met korte pauze
}
