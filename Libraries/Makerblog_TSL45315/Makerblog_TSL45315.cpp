/*************************************************** 
  This is a library for the TSL45315 Lux sensor breakout board by Watterott
  These sensors use I2C to communicate, 2 pins are required to interface

  Written by Adi Dax/Makerblog.at  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

 #include <Arduino.h>

 #include "Makerblog_TSL45315.h"
 
 /*========================================================================*/
 /*                            CONSTRUCTORS                                */
 /*========================================================================*/

 /**************************************************************************/
 /*!
     Constructor
 */
 /**************************************************************************/
 Makerblog_TSL45315::Makerblog_TSL45315(uint8_t resolution) 
 {
	 _resolution = resolution;
	 _timerfactor = 0;
	 if (resolution == uint8_t(TSL45315_TIME_M1)) {
		 _timerfactor = 1;
	 } 
	 if (resolution == uint8_t(TSL45315_TIME_M2)) {
		 _timerfactor = 2;
	 } 
	 if (resolution == uint8_t(TSL45315_TIME_M4)) {
		 _timerfactor = 4;
	 } 
 }
  
 
 /*========================================================================*/
 /*                           PUBLIC FUNCTIONS                             */
 /*========================================================================*/
 boolean Makerblog_TSL45315::begin(void)
 {
	 Wire.begin();
	 Wire.beginTransmission(TSL45315_I2C_ADDR);
     Wire.write(0x80|TSL45315_REG_ID);
     Wire.endTransmission();
	 
     Wire.requestFrom(TSL45315_I2C_ADDR, 1);
     while(Wire.available())
     {
		 unsigned char c = Wire.read();
		 c = c & 0xF0;
		 if (c != 0xA0) {
			 return false;
		 }
     }
	 
     Wire.beginTransmission(TSL45315_I2C_ADDR);
     Wire.write(0x80|TSL45315_REG_CONTROL);
     Wire.write(0x03);
     Wire.endTransmission();

     Wire.beginTransmission(TSL45315_I2C_ADDR);
     Wire.write(0x80|TSL45315_REG_CONFIG);
     Wire.write(_resolution);
     Wire.endTransmission();
	 
	 return true;
 }
 
 
 uint32_t Makerblog_TSL45315::readLux(void)
 {
	 uint32_t lux;
	   
     Wire.beginTransmission(TSL45315_I2C_ADDR);
     Wire.write(0x80|TSL45315_REG_DATALOW);
     Wire.endTransmission();
     Wire.requestFrom(TSL45315_I2C_ADDR, 2);
     _low = Wire.read();
     _high = Wire.read();
     while(Wire.available()){ 
       Wire.read(); 
     }

     lux  = (_high<<8) | _low;
	 lux = lux * _timerfactor;
	 return lux;
 }
 
 
boolean Makerblog_TSL45315::powerDown(void)
{
    Wire.beginTransmission(TSL45315_I2C_ADDR);
    Wire.write(0x80|TSL45315_REG_CONTROL);
    Wire.write(0x00);
    Wire.endTransmission();
	return true;
}
 