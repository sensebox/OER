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

#include "MOD1024.h"
#include "Wire.h"
#include "Arduino.h"

void VEMLClass::init() {
	VEML6070_init();
	delay(1);
	VEML6040_init();
	delay(1);
}

void VEMLClass::VEML6070_init() {
	VEML6070_write(0x02);
}

void VEMLClass::VEML6070_write(uns8 cmd) {
	Wire.beginTransmission(VEML6070_ADDR);
	Wire.write(cmd);
	Wire.endTransmission();
	VEML6070_command = cmd;
}

uns16 VEMLClass::getUV() {
	VEML6070_write(VEML6070_command);
	uns8 msb, lsb;
	Wire.requestFrom(VEML6070_ADDR+1, 1);
	if (Wire.available()) {
		msb = Wire.read();
	}
	Wire.requestFrom(VEML6070_ADDR+0, 1);
	delay(1);
	if (Wire.available()) {
		lsb = Wire.read();
	}
	return (msb << 8) | lsb;
}

void VEMLClass::VEML6070_setIT(uns8 it) {
	it = (VEML6070_command & 0xF3) | (it << 2);
	VEML6070_write(it);
	VEML6070_command = it;
	delay(1);
}

void VEMLClass::VEML6040_init() {
	VEML6040_enableSensor();
}

void VEMLClass::VEML6040_write(uns8 addr, uns8 lsb) {
	Wire.beginTransmission(VEML6040_ADDR);  
	Wire.write(addr); 
	Wire.write(lsb); 
	Wire.write(0x00);
	Wire.endTransmission(false); 
}

uns16 VEMLClass::VEML6040_read(uns8 addr) {
	uns8 msb = 0x00, lsb = 0x00;
	Wire.beginTransmission(VEML6040_ADDR);
	Wire.write(addr);
	Wire.requestFrom(VEML6040_ADDR, 2);
	while (Wire.available()) {
		lsb = Wire.read();
		msb = Wire.read();
	}
	Wire.endTransmission(false);
	return (msb << 8) | lsb;
}

void VEMLClass::VEML6040_setIT(uns8 it) {
	uns16 conf = VEML6040_read(VEML6040_CONF);
	conf &= 0x0003;
	it = it << 4;
	VEML6040_write(VEML6040_CONF, (conf | it));
}

void VEMLClass::VEML6040_forceMode() {
	uns16 conf = VEML6040_read(VEML6040_CONF);
	conf &= 0x0072;
	conf |= 0x0002;
	VEML6040_write(VEML6040_CONF, conf);
}

void VEMLClass::VEML6040_autoMode() {
	uns16 conf = VEML6040_read(VEML6040_CONF);
	conf &= 0x0070;
	VEML6040_write(VEML6040_CONF, conf);
}

void VEMLClass::VEML6040_trigger() {
	uns16 conf = VEML6040_read(VEML6040_CONF);
	conf &= 0x0072;
	VEML6040_write(VEML6040_CONF, (conf | 0x0004));
	delay(1);
	VEML6040_write(VEML6040_CONF, (conf & 0x0070));
}

uns16 VEMLClass::getRed() {
	return VEML6040_read(0x08);
}

uns16 VEMLClass::getGreen() {
	return VEML6040_read(0x09);
}

uns16 VEMLClass::getBlue() {
	return VEML6040_read(0x0A);
}

uns16 VEMLClass::getWhite() {
	return VEML6040_read(0x0B);
}

void VEMLClass::VEML6040_enableSensor() {
	uns16 conf = VEML6040_read(VEML6040_CONF);
	conf &= 0x00FE;
	VEML6040_write(VEML6040_CONF, conf);
	delay(1);
}

void VEMLClass::VEML6040_disableSensor() {
	uns16 conf = VEML6040_read(VEML6040_CONF);
	conf &= 0x00FE;
	conf |= 0x000;
	VEML6040_write(VEML6040_CONF, conf);
	delay(1);
}

VEMLClass mod1024;