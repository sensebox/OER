/*************************************************** 
  This is a library for the TSL45315 Lux sensor breakout board by Watterott
  These sensor use I2C to communicate, 2 pins are required to  
  interface

  Written by Adi Dax/Makerblog.at  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#ifndef MAKERBLOG_TSL45315_H
#define MAKERBLOG_TSL45315_H

#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif 

#include <Wire.h>
 
#define TSL45315_I2C_ADDR 		(0x29)

#define TSL45315_REG_CONTROL  	(0x00)
#define TSL45315_REG_CONFIG   	(0x01)
#define TSL45315_REG_DATALOW  	(0x04)
#define TSL45315_REG_DATAHIGH 	(0x05)
#define TSL45315_REG_ID       	(0x0A)

// Sensing time for one measurement
#define TSL45315_TIME_M1		(0x00)	// M=1 T=400ms
#define TSL45315_TIME_M2		(0x01)	// M=2 T=200ms
#define TSL45315_TIME_M4		(0x02)	// M=4 T=100ms

class Makerblog_TSL45315 {
public:
	Makerblog_TSL45315(uint8_t resolution);
	boolean begin(void);
	uint32_t readLux(void);
	boolean powerDown(void);
	
	
private:
	uint16_t _low, _high, _timerfactor;
	uint8_t _resolution;
};

#endif // MAKERBLOG_TSL45315_H

