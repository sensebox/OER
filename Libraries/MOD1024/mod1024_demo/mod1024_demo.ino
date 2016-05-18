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

/*Test sketch for the MOD-1024 UV and RGBW light sensor*/

#include <Wire.h>
#include <MOD1024.h>

int x = 0;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  Serial.println("SDFS");
  mod1024.init();
  Serial.println("MOD1024 VEML6040 & VEML6070 UV and RGBW Light Sensor test sketch");
  Serial.println("Embedded Adventures (embeddedadventures.com)");
  mod1024.VEML6040_forceMode();
  mod1024.VEML6040_trigger();
  delay(500);
}

void loop() {
  measureLight();
  Serial.println();
  delay(400);
  mod1024.VEML6040_trigger();
}

//Read registers and print values
void measureLight() {
  uns16 uv, red, blue, green, white;
  uv = mod1024.getUV();
  red = mod1024.getRed();
  green = mod1024.getGreen();
  blue = mod1024.getBlue();
  white = mod1024.getWhite();
  Serial.println("MOD1024 Data");
  Serial.print("UV:\t");
  Serial.println(uv);
  Serial.print("Red:\t");
  Serial.print(red);
  Serial.print("\tGreen:\t");
  Serial.print(green);
  Serial.print("\tBlue:\t");
  Serial.print(blue);
  Serial.print("\tWhite:\t");
  Serial.println(white);
}

