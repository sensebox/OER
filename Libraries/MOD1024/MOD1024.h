/*

Copyright (c) 2016, Embedded Adventures
All rights reserved.

Contact us at source [at] embeddedadventures.com
www.embeddedadventures.com

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

- Redistributions of source code must retain the above copyright notice,
  this list of conditions and the following disclaimer.

- Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in the
  documentation and/or other materials provided with the distribution.

- Neither the name of Embedded Adventures nor the names of its contributors
  may be used to endorse or promote products derived from this software
  without specific prior written permission.
 
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
THE POSSIBILITY OF SUCH DAMAGE.

*/

// EML6040/VEML6070 MOD-1024 UV and RGBW light sensor Arduino library
// Written originally by Embedded Adventures

#ifndef __MOD1024_h
#define	__MOD1024_h

#define uns8 	unsigned char
#define uns16	unsigned int

//UV Sensor VEML6070 definitions
#define VEML6070_ADDR	0x38

//RGBW Sensor VEML6040 definitions
#define VEML6040_ADDR	0x10
#define VEML6040_CONF	0x00

class VEMLClass {
private:
	/*Holds previous command byte written to VEML6070*/
	uns8 VEML6070_command;
	
	/*Initialize VEML6070. IT = 0*/ 
	void VEML6070_init();
	
	/*Write cmd to VEML6070, then store cmd to VEML6070_command*/
	void VEML6070_write(uns8 cmd);
	
	/*Initialize VEML6040. IT = 0, auto-mode*/
	void VEML6040_init();
	
	/*Write lsb to register addr in VEML6040. MSB is 0x00*/
	void VEML6040_write(uns8 addr, uns8 lsb);
	
	/*Read register addr in VEML6040*/
	uns16 VEML6040_read(uns8 addr);
	
public:
	/*Initialize VEML6040 and VEML6070*/
	void init();
	
	/*Get UV measurement*/
	uns16 getUV();
	
	/*Set integration time for VEML6070 measurement. 0 = 1/2T, 1 = T, 2 = 2T, 3 = 4T */
	void VEML6070_setIT(uns8 it);
	
	/*Get red light measurement*/ 
	uns16 getRed();
	
	/*Get green light measurement*/ 
	uns16 getGreen();
	
	/*Get blue light measurement*/ 
	uns16 getBlue();
	
	/*Get white light measurement*/ 
	uns16 getWhite();
	
	/*Enable light sensor in VEML6040*/
	void VEML6040_enableSensor();
	
	/*Disable light sensor in VEML6040*/
	void VEML6040_disableSensor();
	
	/*Set integration time for VEML6040 measurement. 0 = 40ms, 1 = 80ms, 2 = 160ms, 3 = 320ms, 4 = 640ms,  = 1280ms */
	void VEML6040_setIT(uns8 it);
	
	/*Set VEML6040 to forced measurement mode. Must be triggered to start a measurement*/
	void VEML6040_forceMode();
	
	/*Set VEML6040 to auto measurement mode*/
	void VEML6040_autoMode();
	
	/*Triggers a measurement during forced mode*/
	void VEML6040_trigger();
};

extern VEMLClass mod1024;

#endif