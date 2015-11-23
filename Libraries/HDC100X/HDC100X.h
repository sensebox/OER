/***********************

This library was written for the Texas Instruments 
HDC100X temperature and humidity sensor. 
It has been tested for the HDC1000 and the HDC1008
Buy the HDC1008 breakout board at: https://www.tindie.com/stores/RFgermany
This library is made by Florian Roesner.
Released under GNU GPL v2.0 license.

*************************/ 

#ifndef _HDC100X_H_
#define _HDC100X_H_

#include <inttypes.h>
#include "Wire.h"

#if (ARDUINO >= 100)
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#define HDC100X_DEFAULT_ADDR		0x40

#define HDC100X_TEMP_REG			0x00
#define HDC100X_HUMI_REG			0x01
#define	HDC100X_CONFIG_REG			0x02
#define HDC100X_ID1_REG				0xFB
#define HDC100X_ID2_REG				0xFC
#define HDC100X_ID3_REG				0xFD


#define HDC100X_RST					0x80
#define	HDC100X_TEMP_HUMI			0x16
#define	HDC100X_HUMI				1
#define	HDC100X_TEMP				0

#define HDC100X_14BIT				0x00
#define HDC100X_11BIT				0x01
#define HDC100X_8BIT				0x02

#define DISABLE						0
#define ENABLE						1



class HDC100X{
	public: 
		HDC100X();
		HDC100X(uint8_t address);
		HDC100X(bool addr0, bool addr1);
		
		uint8_t begin(uint8_t mode, uint8_t tempRes, uint8_t humiRes, bool heaterState);
		uint8_t begin(uint8_t mode, uint8_t resulution, bool heaterState);

		void setAddr(bool addr0, bool addr1);
		void setAddr(uint8_t address);
		void setDrPin(int8_t pin);

		uint8_t setMode(uint8_t mode, uint8_t tempRes, uint8_t humiRes);
		uint8_t setMode(uint8_t mode, uint8_t resolution);
		
		uint8_t setHeater(bool state);
		bool battLow(void);

		float getTemp(void);
		float getHumi(void);
		
		uint16_t getRawTemp(void);
		uint16_t getRawHumi(void);
		
		uint8_t getConfigReg(void);
		uint16_t read2Byte(uint8_t reg);

		uint8_t writeConfigData(uint8_t config);
		
	private:
  		uint8_t ownAddr;
		uint8_t dataReadyPin;
		uint8_t HDCmode;
  		void setRegister(uint8_t reg);

};

#endif _HDC100X_H_