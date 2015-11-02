#Station 5 - Der serielle Datenbus und die Verwendung von Software Bibliotheken
Damit wir täglich den Wetterbericht im Internet, im Fernsehen, in der Zeitung oder in Apps sehen können, werden nicht nur Satellitendaten ausgewertet. Auch Daten von Wetterstationen am Boden spielen eine wichtige Rolle bei der Vorhersage. Aber wie funktioniert die Messung und Darstellung von Temperaturwerten? 

##Ziele der Station
In dieser Station beschäftigst du dich mit einem Umweltsensor, mit dem Temperatur und Luftfeuchtigkeit gemessen werden kann. Wir lernen dabei die Verwendung von Softwarebibliotheken und die Kommunikation über den seriellen Datenbus kennen.

##Materialien
*Kombinierter Temperatur- und Luftfeuchtigkeitsensor

##Grundlagen
Der HDC1008 aus der Serie HDX100X von Texas Instruments ist ein kombinierter Temperatur- und Luftfeuchtigkeitssensor. Detaillierte Informationen über einen Sensor findet man im entsprechenden Datenblatt des Herstellers. Sich ein solches Datenblatt genauer anzuschauen, ist im Voraus immer eine gute Idee, um mehr über Auflösung der Messwerte, Betriebsbedingungen oder Anwendungsbeispiele zu erfahren.
Dem Datenblatt des HDC1008 ist beispielsweise zu entnehmen, dass der Sensor die Luftfeuchtigkeit von 0% bis 100% sowie die Temperatur von -40°C bis 125°C bei einer Genauigkeit von ±4% bzw. von ±0,2°C liefert. 

Die Kommunikation des Sensors mit dem Mikrokontroller läuft über den seriellen Datenbus I2C (engl. für Inter-Integrated Circuit). Anders als bei einfachen digitalen oder analogen Eingängen, können an den Datenbus mehrere I2C-Geräte (wie z.B. Sensoren oder Displays) parallel geschaltet werden. Jedes Gerät hat dabei eine eindeutige Kennung, damit der Datenbus jedes Einzelne davon zuordnen und separat ansprechen kann. 

Die I2C-Anschlüsse befinden sich beim Arudino Uno auf den Pins A4 (SDA) und A5 (SCL). Zusätzlich muss der Sensor noch mit einer Betriebsspannung von 3V bis 5V versorgt werden (s. Datenblatt). Die entsprechenden Anschlüsse am Sensor mit der Bezeichnung VCC (eng. für Voltage at the Common Collector; Bezeichnung für die Hauptbetriebsspannung) und GND (engl. für Ground; Bezeichnung für das Bezugspotential) müssen mit dem 3,3V bzw. mit dem GND Anschluss am Arduino Uno verbunden werden.

##Aufbau
<img src="https://github.com/sensebox/OER/blob/master/senseBox_edu/images/aufbau_station_5.png/"/>

##Grundlagen
Für die meisten gängigen Sensoren werden vom Hersteller oder auch von der Open Source Community Softwareerweiterungen (sog. Bibliotheken oder Libraries) angeboten. Bibliotheken bieten alle Funktionen an, die zur Kommunikation benötigt werden. 

Lade die HDC100X Bibliothek für Arduino herunter und kopiere den Inhalt aus dem Ordner in der Zip-Datei in den libraries Ordner der Arduino Installation auf deiner Festplatte, sodass die folgende Ordnerstruktur entsteht:

```
arduino-1.x.x/libraries/HDC100X/
    |-- examples/
        |-- readTempHumi/
            |-- readTempHumi.ino
    |-- KEYWORDS.txt
    |-- HDC100X.h
    |-- HDC100X.cpp
```
***Hinweis:*** **Wenn neue Bibliotheken installiert werden, muss die Arduino IDE neu gestartet werden, damit die Änderungen korrekt übernommen werden!
**
Um alle zusätzlichen Funktionen der Bibliothek nutzen zu können, muss sie an oberster Stelle in eurem Programm mit der Direktive #include <name.h> eingebunden werden. In unserem Fall brauchen wir neben der HDC100X Bibliothek noch die Wire Bibliothek (Standarterweiterung für I2C Geräte), also steht in den ersten beiden Zeilen:

```
#include <Wire.h>
#include <HDC100X.h>        
```
***Hinweis:*** **Anders als bei regulären Befehlen, steht am Ende der include Direktive kein Semikolon.**
In allen darauf folgenden Zeilen können nun die Funktionen der Bibliotheken genutzt werden. Als erstes muss eine Verbindung zur Sensoradresse angegeben werden. Bei diesem Sensor lautet die Adresse 0x43 (s. Datenblatt).

```
HDC100X HDC(0x43);
```

durch diesen Befehl hast du nun den Sensor HDC vom Typ HDC100X angelegt. Jetzt muss dieser Sensor in der Setup-Funktion wie folgt gestartet werden:

```
HDC.begin(HDC100X_TEMP_HUMI, HDC100X_aufbau, HDC100X_14BIT, DISABLE);
```
Die Argumente der begin-Funktion geben dabei an, dass Temperatur und Luftfeuchte gemessen werden, jeweils in einer Auflösung von 14 Bit, und dass das Heizelement des Sensors deaktiviert werden soll.
Nachdem du den Sensor, wie oben beschrieben, initialisiert hast, kannst du zwei Befehle in der loop-Funktion nutzen, um einen Temperatur- bzw. Feuchtigkeitswert ausgeben zu lassen:

```
HDC.getHumi();
HDC.getTemp();
```
***Tipp:*** **Beim Speichern der Messwerte sollten die Variablen den gleichen Datentypen haben wie die Rückgabewerte der Messfunktionen. In unserem Fall sind das beides float Werte.**

##Aufgabe 1
Baue die oben beschriebene Schaltung nach und versuche den HDC1008 auszulesen und Dir die gemessenen Daten im seriellen Monitor anzeigen zu lassen.

***Tipp:*** **Benutze dazu das Beispiel aus der HDC100X Bibliothek.**
