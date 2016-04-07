#include <Wire.h>
#include <HDC100X.h>

HDC100X HDC1(0x43);


#define LED 13
bool state = false;

void setup(){
	Serial.begin(9600);
	HDC1.begin(HDC100X_TEMP_HUMI,HDC100X_14BIT,HDC100X_14BIT,DISABLE);
}
 
void loop(){
    Serial.print(" Humidity: ");
    Serial.print(HDC1.getHumi()); 
    Serial.print("%, Temperature: ");     
    Serial.print(HDC1.getTemp());
    Serial.println("C");
    delay(500);
}
