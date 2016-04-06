<img src="https://github.com/sensebox/OER/blob/master/senseBox_edu/images/sensebox_logo_neu.png" width="200"/> 

#Station 6 - Experimente mit Licht
Wenn du fern siehst, das Radio anschaltest, mit deinem Smartphone eine Nachricht schreibst oder Essen in der Mikrowelle warm machst, nutzt du dabei elektromagnetische Energie. Heutzutage sind alle Menschen ständig auf diese Energie angewiesen. Ohne sie würde das Leben in modernen Städten völlig anders sein, als du es kennst.

##Ziele der Station
In dieser Station verwendest du einen Lichtsensor, um die Beleuchtungsstärke des sichtbaren Lichts in Lux zu erfassen.

##Materialien
* Lichtsensor

##Grundlagen
Elektromagnetische Energie bewegt sich in Wellen durch den Raum. Ihr Spektrum reicht von sehr langen Radiowellen bis hin zur sehr kurzwelligen Gammastrahlung. Das menschliche Auge kann dabei nur einen sehr kleinen Teil dieses Spektrums wahrnehmen: das sichtbare Licht. Unsere Sonne ist dabei die Quelle der Energie über das gesamte Spektrum hinweg. Die Atmosphäre der Erde schützt uns davor, einem zu hohen Maß an Strahlung ausgesetzt zu werden, die für uns lebensgefährlich werden könnte.

Für uns ist die Intensität des sichtbaren Lichts besonders interessant. Um die sog. Beleuchtungsstärke des einfallenden Lichts im sichtbaren Teil des Spektrums zu messen, wird die Einheit Lux verwendet. Sie gibt das Verhältnis der Helligkeit in Lumen pro Quadratmeter an. Bei einem hellen Sonnentag beträgt sie über 100.000 Lux, in einer Vollmondnacht hingegen nur etwa 1 Lux.

Für diese Messung benutzt du im Folgenden den I2C Sensor TSL45315 von AMS-TAOS. Im Datenblatt des Sensors sieht man, dass seine Empfindlichkeit auf den sichtbaren Teil des Lichtspektrums angeglichen ist, der ungefähr zwischen 400 und 700 nm liegt.

Laut dem Datenblatt hat dieser Sensor eine Reichweite von 2 bis 200.000 Lux, bei einer Auflösung von 3 Lux. Des Weiteren muss der Sensor mit 3,3V betrieben werden.

##Aufbau

<image src="https://github.com/sensebox/OER/blob/master/senseBox_edu/images/Aufbau_station_6.png"/>

##Grundlagen
Zur manuellen Programmierung benutzt du dieses Mal nur die Wire-Bibliothek. Am Anfang brauchst du ein paar Konstanten, die mit der Direktive #define definiert werden. Anders als bei Variablen belegen sie einen festen Platz im Speicher, der sich nur auslesen, aber nicht beschreiben lässt. In unserem Falle soll die Busadresse sowie die folgenden Registeradressen des Sensors gespeichert werden. 

<image src="https://github.com/sensebox/OER/blob/master/senseBox_edu/images/Grundlagen_Station_6.png"/>

Diese Register werden zur Konfiguration und Kommunikation benötigt:
```
#include <Wire.h>
#define I2C_ADDR 		(0x29)
#define REG_CONTROL 	0x00
#define REG_CONFIG 		0x01
#define REG_DATALOW 	0x04
#define REG_DATAHIGH 	0x05
#define REG_ID			0x0A
```

In der Setup-Funktion soll nun eine Verbindung zu dem Sensor hergestellt werden und dem Kontrollregister der Befehl zum Hochfahren gegeben werden:

```
Wire.begin();
Wire.beginTransmission(I2C_ADDR);
Wire.write(0x80 | REG_CONTROL);
Wire.write(0x03); //Power on
Wire.endTransmission();
```

Als nächstes legen wir eine Belichtungszeit von 400 ms fest:

```
Wire.beginTransmisson(I2C_ADDR);
Wire.write(0x80 | REG_CONFIG);
Wire.write(0x00); //400 ms
Wire.endTransmission();
```

Um die Belichtungszeit zu verändern, kann man den entsprechenden Wert von 0x00 in 0x01 oder 0x02 ändern, um die Belichtungszeit auf 200 bzw. 100 ms im Konfigurationsregister des Sensors zu reduzieren.
In der Loop-Funktion geben wir nun den Befehl zum Start der Messroutine und lassen uns vom Sensor die Daten senden, die für die Berechnung der Beleuchtungsstärke benötigt werden:

```
Wire.beginTransmisson(I2C_ADDR);
Wire.write(0x80 | REG_DATALOW); 
Wire.endTransmission();
Wire.requestFrom(I2C_ADDR, 2); //2 Bytes anfordern
uint16_t low = Wire.read();
uint16_t high = Wire.read();
```

Falls der Sensor noch Daten sendet, sollten diese danach abgefangen werden, um Fehler im nächsten Durchgang zu vermeiden.

```
while(Wire.available()){ 
	Wire.read(); 
}
```

***Hinweis:*** *Ähnlich wie bei unserer loop-Funktion führt eine while-Schleife die Anweisungen in den geschweiften Klammern immer wieder aufs Neue aus. Abgebrochen wird sie erst dann, wenn die Bedingung nicht mehr erfüllt wird.*

Zu guter Letzt nutzt du die ausgelesenen Datenbytes, um Beleuchtungsstärke in Lux auszurechnen. Im Datenblatt findet sich die dazu passende Formel:

```
uint32_t lux; 
lux = (high << 8) | (low << 0);
lux = lux * 1; //Multiplikator für 400ms
```

Um diese Formel auf eine Belichtungszeit von 200 oder 100ms anzupassen, musst du nur den Multiplikator auf 2 bzw. 4 erhöhen.

##Aufgabe 1
Füge den Code aus dieser Lektion zusammen und ergänze eine Funktion um die Daten im Seriellen Monitor ausgeben zu lassen.

##Aufgabe 2
Ändere die Belichtungszeit des Sensors und vergleiche danach die Ergebnisse der Messungen. 

***Tipp:*** *Vergiss nicht, neben der Belichtungszeit im Konfigurationsregister auch die Berechnung des Lux-Wertes entsprechend anzupassen.*
