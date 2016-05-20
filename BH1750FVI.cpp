/*****************************************************
Library for light intensity sensor BH1750FVI 

Markus Ulsass, Hamburg, Germany
ulsass@tradewire.de
20-5-2016

https://github.com/markbeee/IKEA_hydroponics_control
******************************************************/

#include "Arduino.h"
#include "BH1750FVI.h"

BH1750FVI::BH1750FVI(){}
  
	void BH1750FVI::begin(void){
		
		Wire.begin(); 
		i2cWrite(Power_On); 
				
	}
   
	// Instruction set architecture modes (for details s. page 5 datasheet BH1750FVI)
	void BH1750FVI::setMode(uint8_t mode){
    
		switch(mode){
			case Power_Down:
			break;
			case Power_On:
			break;
			case Reset:
			break;
			case Continuously_High_Resolution_Mode:
			break;
			case Continuously_High_Resolution_Mode2:
			break;
			case Continuously_Low_Resolution_Mode:       
			break;
			case OneTime_High_Resolution_Mode:
			break;
			case OneTime_High_Resolution_Mode2:
			break;
			case OneTime_Low_Resolution_Mode:  
			break;
		}
		
		i2cWrite(mode);
	}
	
	void BH1750FVI::i2cWrite(uint8_t data){
		
		Wire.beginTransmission(i2cAddress);
		Wire.write(data);
		Wire.endTransmission();
		
	}
  
	uint16_t BH1750FVI::getAmbientLight(void){
	
		uint16_t ambientLightValue;
	
		Wire.beginTransmission(i2cAddress);
		Wire.requestFrom(i2cAddress, 2);
		ambientLightValue = Wire.read();
		ambientLightValue <<= 8;
		ambientLightValue |= Wire.read();
		Wire.endTransmission();
		ambientLightValue = ambientLightValue/1.2; // s. page 7 of datasheet for calculation
		return ambientLightValue;
    
	}