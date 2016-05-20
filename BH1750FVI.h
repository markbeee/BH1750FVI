/*****************************************************
Library for light intensity sensor BH1750FVI 

Markus Ulsass, Hamburg, Germany
ulsass@tradewire.de
20-5-2016

https://github.com/markbeee/IKEA_hydroponics_control
******************************************************/
  
#ifndef BH1750FVI_h
#define BH1750FVI_h

#include "Arduino.h"
#include "Wire.h"

// I2C Address if address pin is pulled to GND, else if tied to Vcc use 0x5c
#define i2cAddress 0x23

// Instruction set architecture modes (for details s. page 5 datasheet BH1750FVI)

#define Power_Down 0x00

#define Power_On 0x01

#define Reset 0x07

#define Continuously_High_Resolution_Mode 0x10

#define Continuously_High_Resolution_Mode2 0x11

#define Continuously_Low_Resolution_Mode 0x13

#define OneTime_High_Resolution_Mode 0x20

#define OneTime_High_Resolution_Mode2 0x21

#define OneTime_Low_Resolution_Mode 0x23
  
  class BH1750FVI {    
    
	public:
    BH1750FVI();
    void begin(void);
    void setMode(uint8_t mode);
    uint16_t getAmbientLight(void);
    
    private:
    void i2cWrite(uint8_t data);  
	
  };
  
#endif