/*
  senseBox Datenlogger Temperatur, Luftfeuchtigkeit und Luftdruck
Anschluss des HDC100x über I2C an den Arduino 
SDA - A4, SCL - A5, VCC - 5V, GND - GND

*/

#include <SPI.h> //wichtige Libraries für das Speichern von Daten auf SD-Karte
#include <SD.h>
#include <Wire.h> //I2C Library
#include <HDC100X.h> //Library für den HDC100x
#include "BMP280.h" //Library für den BMP280

HDC100X HDC1(0x43); //IC2 Adresse des HDC1000


BMP280 bmp;
#define P0 1013.25
double T,P,A;
float zeit;



const int chipSelect = 4; //

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }


  Serial.print("Initialisiere SD-Karte");

  // Überprüfe ob eine SD-Karte eingelegt ist.
  if (!SD.begin(chipSelect)) {
    Serial.println("Karte nicht gefunden");
    return;
  }
  Serial.println("Karte erfolgreich initialisiert");

  HDC1.begin(HDC100X_TEMP_HUMI,HDC100X_14BIT,HDC100X_14BIT,DISABLE);
  
 bmp.begin();
  bmp.setOversampling(4);

File dataFile = SD.open("datalog.csv", FILE_WRITE);
  dataFile.println(" Temperature(C); Luftfeuchtigkeit(%); Luftdruck (mBar); Höhe (m); Zeit(s) ");
  dataFile.close();
}

void loop() {

  //Auslesen der Sensoren und schreiben der Daten auf SD-Karte
  File dataFile = SD.open("datalog.csv", FILE_WRITE);

    float Temp = HDC1.getTemp(); //Auslesen der Temperatur
    dataFile.print(Temp); //Speichern der Temperatur
    dataFile.print(";");
    Serial.println(HDC1.getTemp()); //Anzeige der Temperatur im seriellen Monitor
    float Humi = HDC1.getHumi();
    dataFile.print(Humi);
    dataFile.print(";");
    Serial.println(HDC1.getHumi());
    char result = bmp.startMeasurment();
    result = bmp.getTemperatureAndPressure(T,P);
    double A = bmp.altitude(P,P0);
    zeit = millis();
    if(result!=0)
      {
        double A = bmp.altitude(P,P0);
        
        Serial.print("T = \t");Serial.print(T,2); Serial.print(" degC\t");
        Serial.print("P = \t");Serial.print(P,2); Serial.print(" mBar\t");
        Serial.print("A = \t");Serial.print(A,2); Serial.println(" m");
       
      }
    dataFile.print(P);
    dataFile.print(";");
    dataFile.print(A);
    dataFile.print(";");
    dataFile.print((zeit/1000));
    dataFile.println(";");
    
    

  // Wenn die Datei geöffnet ist
  if (dataFile) {
    dataFile.close();
  }
  // Falls die Datei nicht geöffnet werden kann, soll eine Fehlermeldung ausgegeben werden
  else {
    Serial.println("Fehler beim Öffnen!");
  }
  delay(1000); //Intervall des Speichern und Auslesen
}
