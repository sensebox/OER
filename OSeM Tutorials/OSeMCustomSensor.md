## Manuelle konfiguration eines Sensors auf der OSeM

In dieser Anleitung wird beispielhaft die Anbindung eines SHT15 Sensors in das OSeM Netzwerk beschrieben. Für die Datenverarbeitung bzw. -übertragung nutzen wir ein Arduino Uno  mit Arduino Ethernet Shield. Die REST Schnittstelle bietet aber auch jeder anderen programmierbaren und mit dem Internet verbundenen Messstation die Möglichkeit, Messungen auf der OSeM zu veröffentlichen und zu teilen.

### Komponenten in der Übersicht
* Arduino Uno R3
* Arduino Ethernet Shield R3
* [Sparkfun SHT15 Breakout](https://www.sparkfun.com/products/8257)

### Verkabelung
* VCC zu 5V
* DATA zu Pin 6
* SCK zu Pin 7
* GND zu Arduino GND

![](https://github.com/sensebox/OER/blob/master/OSeM%20Tutorials/images/fritzing.png)

### SHT1x Bibliothek
Für Sensoren der SHT1x Serie von Sensirion gibt es bereits eine einfache Arduino-Schnittstelle. [Ladet die Bibliothek von Github herunter](https://github.com/practicalarduino/SHT1x) und entpackt sie in euren Arduino/libraries Ordner. Importiert die Bibliothek wie gehabt in eurem Arduino Sketch, und definiert zusätzlich den Daten- und Taktpin entsprechend der Verkabelung in Bild 1. Danach könnt ihr eine Verbindung zum Sensor herstellen:

```arduino
#include<sht1x.h>
#define dataPin 6
#define clockPin 7
SHT1x sht1x(dataPin, clockPin);
```

Nun lassen sich über zwei Funktionen die Temperatur in Grad Celsius, sowie die relative Luftfeuchte in Prozent als Gleitkommazahl abspeichern:

```arduino
float temp = sht1x.readTemperatureC();
float humi = sht1x.readHumidity();
```

### Manuelle Registrierung
Um einen Sensor mit der OSeM zu verbinden, müsst ihr ihn [zuerst dort registrieren](http://opensensemap.org/#/register). Falls ihr dabei keinen der SenseBox Bausätze nutzt, müsst ihr in Schritt 4 der Registrierung die manuelle Konfiguration auswählen. Wie unten in der Abbildung dargestellt, wird dort für jedes gemessene Phänomen ein neuer Sensor angelegt:

![](https://github.com/sensebox/OER/blob/master/OSeM%20Tutorials/images/registration_step4.png)

### OpenSenseMap API
Eine REST Schnittstelle regelt den Zugang zur Datenbank auf dem OSeM Server. Intern ist jede Messstation mit ihren Sensoren (bzw. Phänomenen) verknüpft, die bei der Registrierung angegeben wurden. In unserem Falle haben wir eine SenseBox ID für die Station, sowie jeweils eine Sensor ID für Temperatur- und Luftfeuchtigkeitsmessungen bei der Registrierung generiert. Die IDs werden euch nach der Registrierung per Mail zugeschickt. Jede Messung wird dann über das HTTP Protokoll mit der POST Operation an den Server gesendet. Dazu muss eine eindeutige URI angegeben werden die wie folgt aufgebaut aufgebaut ist:

```
http://opensensemap.org:8000/SenseBoxID/SensorID
```

Jede Messung wird einzelnd im Json Format über das value-Attribut an den Server gesendet. Nehmen wir an, wir wollen von unserer Station (ID 1234) einen Messwert des Thermometers (ID abcd) von 22,5 an den OSeM Server schicken, dann sähe die vollständige HTTP POST Operation folgendermaßen aus:

```
POST /boxes/1234/abcd HTTP/1.1
Host:opensensemap.org
Content-Type: application/json 
Connection: close 
Content-Length: 14

{“value“:22.5}
```
Achtung: Ab Zeile 7 werden die Json-Daten gesendet. Der Zeilenumbruch (\n) in Zeile 6 ist notwendig um die Operation korrekt auszuführen. 

### Arduino OSeM Client
Nach der Registrierung wird ein Arduino Sketch generiert, den ihr als Anhang in einer Bestätigungsmail zugeschickt bekommt. Ihr müsst diesen Sketch noch anpassen, indem ihr die SHT1x Bibliothek einfügt, sowie die benötigen Variablen und eine Sensorinstanz:

```arduino
#include <SPI.h>
#include <Ethernet.h>

#include<sht1x.h>
#define dataPin 6
#define clockPin 7
SHT1x sht1x(dataPin, clockPin);
 
//SenseBox ID
#define SENSEBOX_ID "1234"
//Sensor IDs
#define TEMPERATURESENSOR_ID "abcd"
#define HUMIDITYSENSOR_ID "efgh"
```

Innerhalb der if-Anweisung in der loop-Funktion, müsst ihr nacheinander die Sensoren auslesen und mit der Hilfsfunktion postFloatValue() hochladen. 

```arduino
void loop()
{
  //Upload der Daten mit konstanter Frequenz
  if (millis() - oldTime >= postInterval)
  {
    oldTime = millis();
    temperature = sht1x.readTemperatureC();
    postFloatValue(temperature, 1, temperatureSensorID);
    humidity = sht1x.readHumidity();
    postFloatValue(humidity, 0, humiditySensorID);
  }
}
```
Falls ihr ein Ethernet Modul nutzt welches nicht mit der Ethernet Bibliothek kompatibel ist müsst ihr den Sketch entsprechend anpassen. Solltet ihr weitere Fragen dazu haben, könnt ihr euch direkt an unseren Support unter der Adresse support@sensebox.de wenden.
