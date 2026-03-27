#include <LiquidCrystal.h>

#include <Wire.h>


void setup() {

Wire.begin();

Serial.begin(9600);

Serial.println("Scanning I2C...");

for(byte a = 1; a < 127; a++) {
  Wire.beginTransmission(a);
  if (Wire.endTransmission() == 0) {
    Serial.print("Found address at 0x");
    Serial.println(a, HEX);
  }
}

}

void loop() {
  // put your main code here, to run repeatedly:

}
