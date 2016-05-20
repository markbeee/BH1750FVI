/*********************************************************
  Example sketch for light sensor BH1750FVI
  works with Arduino, ESP8266
  
  I2C Address is 0x23 if address pin is tied to GND
  You can change the address in the library if you pull
  the address pin to Vcc (I2C address = 0x5C)

  Markus Ulsass
  Hamburg, Germany
  ulsass@tradewire.de
  20-5-2016

  https://github.com/markbeee/BH1750FVI
**********************************************************/

#include <Wire.h> // I2C Arduino library
#include <BH1750FVI.h> // BH1750FVI Light sensor library

BH1750FVI LightSensor;
int lux;

void setup() {

  Serial.begin(9600);

  LightSensor.begin();
  LightSensor.setMode(Continuously_High_Resolution_Mode); // see datasheet page 5 for modes

  Serial.println("Light sensor BH1750FVI found and running");

}

void loop() {

  lux = LightSensor.getAmbientLight();
  Serial.print("Ambient light intensity: ");
  Serial.print(lux);
  Serial.println(" lux");
  delay(2000);

}