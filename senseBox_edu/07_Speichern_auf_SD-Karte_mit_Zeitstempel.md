<img src="https://github.com/sensebox/OER/blob/master/senseBox_edu/images/sensebox_logo_neu.png" width="200"/> 

#Station 7 - Speichern auf SD-Karte mit Zeitstempel
Um Veränderungen von Umweltphänomenen bestimmen zu können, müssen Zeitreihen betrachtet werden. Erst wenn die Entwicklung über die Zeit betrachtet wird, lassen sich Rückschlüsse auf die Umgebung ziehen, aber auch Vorhersagen machen. 

##Ziele der Station
Diese Station soll Dir alle Grundlagen vermitteln um deinen eigenen Datenlogger zu bauen.

##Grundlagen
Auf dem SenseBox Shield befinden sich neben allerlei Anschlüssen auch eine Batteriehalterung und ein Kartenslot für eine microSD-Karte. Die Batterie ist an eine interne Uhr (Abkürzung RTC, engl. für Real Time Clock) angeschlossen und wird dazu benötigt, Messungen mit korrektem Zeitstempel in eine Datei auf der SD-Karte zu speichern. Um die RTC nutzen zu können, musst du die RV-8523 Bibliothek herunterladen und wie in Station 5 beschrieben in die Arduino IDE einbinden. Danach wird sie wie gehabt über die Direktive #include geladen und mit dem folgenden Aufruf angelegt:

```
#include <RV8523.h> 
RV8523 rtc;
```

In der setup() Funktion muss bei ihrer ersten Nutzung einmal die Uhrzeit auf RTC gesetzt und dann gestartet werden:

```
rtc.set(0, 0, 8, 20, 4, 2015); //08:00:00 20.04.2015 
rtc.start();
```

Die sechs Argumente der set() Funktion geben erst die Uhrzeit (Sekunden, Minuten, Stunden) und dann das Datum (Tag, Monat, Jahr) an. Uhrzeit und Datum kannst du danach mit den folgenden Befehlen auslesen:

```
uint8_t sec, min, hour, day, month;
uint16_t year;
rtc.get(&sec, &min, &hour, &day, &month, &year);
```

##Aufgabe 1
Schreibe ein Programm, dass die Uhrzeit ausliest und im seriellen Monitor anzeigt.

##Grundlagen
Im ersten Schritt musst du die Library für das SenseBox-Shield einbinden und einen Pin definieren, der für die Datenverbindung benötigt wird. Auf dem SenseBox Shield ist das der Pin 4.

```
#include <SD.h> 
int chipSelect = 4;
```

In der setup-Funktion musst du dann die SD-Funktion über den Datenpin aktiveren, sowie eine Datei anlegen, in die deine Messungen gespeichert werden:

```
SD.begin(chipSelect);
File dataFile = SD.open ("Data.csv", FILE_WRITE); 
```

Auf dem so erzeugten dataFile kannst du, ähnlich wie beim seriellen Monitor, die Funktion print() anwenden, um die Daten in die Datei zu schreiben. Wichtig dabei ist, dass die Datei vor dem Schreibvorgang geöffnet und danach wieder geschlossen wird.

```
dataFile = SD.open ("Data.csv", FILE_WRITE);
dataFile.print (“SenseBox rocks schools!”);
dataFile.close();
```

##Aufgabe 2
Implementiere einen Datenlogger mit der SD-Bibliothek und lasse ein paar Sätze in eine neue Datei abspeichern.

###Aufgabe 3
Schließe einen beliebigen Sensor aus den vorherigen Stationen an und lasse seine Werte zusammen mit einem Zeitstempel in eine csv-Datei speichern.

***Tipp:*** *Schaue dir vorher im Internet an, wie eine csv-Datei aufgebaut ist*
