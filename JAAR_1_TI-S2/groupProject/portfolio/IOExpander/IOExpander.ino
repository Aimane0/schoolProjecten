#include <Wire.h>
bool ack;
uint8_t var = 0b11110111;
int counter = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(SDA, OUTPUT);
  pinMode(SCL, OUTPUT);


  digitalWrite(SDA, HIGH);
  delay(1);
  digitalWrite(SCL, HIGH);
  delay(1);
  digitalWrite(SDA, LOW);
  delay(1);
  
  Wire.begin();
  Wire.beginTransmission(0b0100000);
  Wire.endTransmission();
  Serial.begin(9600);
  delay(1000); // to prevent glitch at start

}

void loop() {
  Wire.beginTransmission(0b0100000);
  Wire.write(var);
  Wire.endTransmission();

  delay(250);
  if(counter >= 3 && counter < 6){
    var = var << 1;
    var = var | 0b00000001;
  }
  else if(counter > 5){
    counter = 0;
  }
  if(counter < 3){
    var = var >> 1;
  }
  counter++;
}
