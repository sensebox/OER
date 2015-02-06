# SenseBox Home (2015) - Bauanleitung

In dieser Anleitung wird schrittweise beschrieben, wie die SenseBox Home zusammengebaut und programmiert wird. Außderdem wird erläutert, wie die Station aufgestellt und angeschlossen werden sollte, damit die Datenübertragung auf die OpeneSenseMap reibungslos funktioniert. 

Viel Spaß mit eurer neuen Messstation wünscht euch

das SenseBox-Team

## 1. Inventarliste

Die unten aufgeführte Hardware wird benötigt, um die Umweltstation anhand dieser Anleitung zusammen zu bauen.

### 1.1 Basiskomponenten

|![Arduino Uno](images/uno_top.png "Arduino Uno")|![Ethernet Shield](images/w5200_top.png "Ethernet Shield")|![Grove Base Shield](images/base_top.png "Grove Base Shield")|
|:------:|:------:|:------:|
|**Arduino Uno R3**|**W5200 Ethernet Shield V2.0**|**Grove - Base Shield V1.3**|

### 1.2 Sensoren

|![Grove Barometer - Sensor BMP085](images/pressure_bmp085.png "Grove Barometer - Sensor BMP085")|![Grove Temperatur/Luftfeuchtigkeit - Sensor DHT11](images/temp_dht11.png "Grove Temperatur/Luftfeuchtigkeit - Sensor DHT11")|
|:--------:|:--------:|
|**Grove Barometer - Sensor BMP085**|**Grove Temperatur/Luftfeuchtigkeit - Sensor DHT11**|
|![Grove Helligkeit - Sensor GL5528](images/light.png "Grove Helligkeit - Sensor GL5528")|![Grove Lautstärke - Sensor LM386](images/sound.png "Grove Lautstärke - Sensor LM386")|
|**Grove Helligkeit - Sensor GL5528**|**Grove Lautstärke - Sensor LM386**|

### 1.3 Zubehör

|![Netzteil (9V, 0.6A)](images/power_supply.png "Netzteil (9V, 0.6A)")|![Universal 4-Pin Kabel für Grove Sensoren](images/grove_cable.png "Universal 4-Pin Kabel für Grove Sensoren")|
|:---------:|:---------:|
|**Netzteil (9V, 0.6A)**|**Universal 4-Pin Kabel für Grove Sensoren**|
|![USB-Kabel (Typ A/B)](images/usb_cable.png "USB-Kabel (Typ A/B)")|![Netzwerkkabel](images/lan_cable.png "Netzwerkkabel")|
|**USB-Kabel (Typ A/B)**|**Netzwerkkabel (nicht im Lieferumfang enthalten)**|

## 2. Aufbau

Durch das Stecksystem dauert der Aufbau eurer Station nur wenige Minuten. Vorweg ein paar wichtige Hinweise die es zu beachten gilt.

### 2.1 Warnhinweise

* Durch elektrostatische Entladung können die Bauteile beschädigt oder sogar zerstört werden! Daher solltet ihr euch z.B. an einem Heizungsrohr entladen bevor ihr mit dem Aufbau anfangt.
* Elektronische Bauteile und Leiterplatten können herstellungbedingt Chemikalien enthalten. Daher solltet ihr nach dem Aufbau oder Gebrauch euch die Hände waschen.
* Elektronik sollte umweltfreundlich entsorgt werden und bei Sammelstellen abgegeben werden.

### 2.2 Basisstation aufbauen

Der Kern unserer Station besteht aus drei Komponenten: dem *Arduino Uno* Mikrokontroller, dem *Ethernet Shield* und dem *Grove Base Shield*.

Steckt als erstes das *Grove Base Shield* auf das *Arduino Uno*. Daran werden die Sensoren wie folgt angeschlossen:

* A0: Sound Sensor
* A1: Temperatur und Luftfeuchte Sensor
* I2C: Digitaler Lichtsensor 
* I2C: Barometer

Steckt nun das *Ethernet Shield* auf das *Grove Base Shield* mit den Sensoren. Es erweitert die Station0 mit der Möglichkeit eine Internetverbindung aufzubauen und als Webclient mit dem OpenSenseMap Server zu kommunizieren.

*Wichtig*: Achtet beim Stapeln der Schields darauf, dass alle Anschlüsse und Steckerleisten korrekt gesteckt sind und keine Kabel beschädigt werden!

### 2.4 Station mit dem Netzwerk verbinden

Bevor der Code hochgeladen wird, solltet ihr die Messstation durch ein Netzwerkkabel mit eurem Heimnetzwerk verbinden. Die Station ist darauf ausgerichtet, dass das angeschlossene Netzwerk DHCP unterstützt. Falls das nicht der Fall sein sollte, solltet ihr eine feste IP (entsprechend der Netzwerkeinstellungen) in der ino-Datei einstellen.

## 3. Programmierung

Hier beschreiben wir Schritt für Schritt wie man das *Arduino Uno* anschließen, installieren und programmieren muss. Diejenigen, die bereits Erfahrung im Umgang mit *Arduino-Boards* haben, können direkt die zusätzlichen Bibliotheken installieren und den SenseBox Sketch auf das Board laden. Für Arduino Einsteiger empfiehlt sich hingegen ein Blick auf [Erste Schritte mit Arduino](http://arduino.cc/de/Guide/HomePage), auf der die ersten Schritte mit dem Arduino ausführlich erklärt werden.

### 3.1 Arduino Software installieren

Ladet als erstes das Installationsprogramm für die *Arduino Software Version 1.0.5* von der [offiziellen Homepage](http://arduino.cc/en/Main/OldSoftwareReleases) herunter und installiert es.
Danach wechselt ihr in eurem Browser auf [unsere *Github* Seite](https://github.com/sensebox/arduino) und ladet dort die zip-Datei mit den benötigten Software-Bibliotheken über den Button am rechten Fensterrand herunter. In dieser Datei befindet sich der Ordner "arduino-master", in dem sich wiederum drei Ordner mit Bibliotheken befinden, um die die *Arduino* Software erweitert werden muss.

Dazu öffnet ihr das *Arduino* Installationsverzeichnis (bei Windows in der Regel unter C:/Programme/Arduino zu finden). Dort befindet sich das Verzeichnis "libraries", in welches ihr die drei Ordner aus der zip-Datei ("Barometer_Sensor", "EthernetV2_0" und "Humidity_Temperature_Sensor") kopiert.

|![Bibliotheken kopieren](images/move_files.png "Bibliotheken kopieren")|
|:-------:|
|**Kopieren der Bibliotheken**|

*Wichtig*: Falls die *Arduino* Software bereits gestartet wurde, müsst ihr nun das Programm neustarten, damit die neuen Bibliotheken korrekt geladen werden.

### 3.2 Arduino IDE konfigurieren

Nachdem ihr die Bibliotheken installiert habt, könnt ihr mit dem USB-Kabel die Station an den Rechner anschließen und die *Arduino Entwicklungsumgebung* (kurz: Arduino IDE) öffnen.

Dort müsst ihr unter dem Reiter "Tools" -> "Board" das richtige *Arduino Board* auswählen. In unserem Fall also "Arduino Uno".

|![Arduino Board auswählen](images/choose_board.png "Arduino Board auswählen")|
|:-------:|
|**Arduino Board auswählen**|

Außerdem müsst ihr einen seriellen Port angeben, über den die Kommunikation zwischen Computer und Mikrokontroller läuft. Wählt dazu unter "Tools" -> "Serieller Port" den COM-Port aus, der von dem Treiber beim Anschließen des Arduino Uno geladen werden sollte.

|![COM-Port auswählen](images/choose_port.png "COM-Port auswählen") |
|:-------:|
|**COM-Port auswählen**|

Falls euch dort kein COM-Port zur Auswahl vorgeschlagen wird, lest bitte den [entsprechenden Abschnitt zur Fehlerbehebung](http://arduino.cc/en/pmwiki.php?n=Guide/Windows) auf der Arduino Homepage.

### 3.3 Registrierung auf der OpenSenseMap

Ein Software-Programm für einen *Arduino Mikrokontroller* nennt man auch Sketch. Seit der *Arduino IDE Version 1.0* werden alle Sketch-Dateien ausschließlich durch die Dateiendung ".ino" gekennzeichnet. Eine solche ino-Datei benötigt ihr nun, um eure Station zu programmieren. Den passenden Sketch zu der SenseBox Umweltstation bekommt ihr, wenn ihr eure Station bei uns auf der OpenSenseMap registriert.
Wählt dazu auf [OpenSenseMap](http://www.opensensemap.org/) die Option "Registrierung" aus. Folgt dort den 5 Schritten zur Registrierung. 

*Wichtig*: Der Standort eurer Station sollte möglichst genau angegeben werden, damit die Messdaten räumlich korrekt zugeordnet werden können.

### 3.4 Übertragung der Daten

Nach erfolgreicher Registrierung wird euch von uns eine ino-Datei zu der angegebenen Mail-Adresse geschickt. Ladet diese Datei herunter und öffnet sie in der *Arduino IDE*.

*Wichtig*: Der erzeugte Code ist genau auf eure Station und eure SenseBox ID angepasst und ist daher nicht für andere SenseBox Stationen gültig.

### 3.4 Sketch auf das Arduino Board hochladen

Der Sketch wird auf das *Arduino Uno* geladen, indem ihr auf das Pfeil-Symbol links in der Werkzeugleiste der Arduino IDE klickt. Nach einer kurzen Weile bekommt ihr eine Rückmeldung vom Programm, dass der Sketch kompiliert und hochgeladen wurde. Um nun zu testen ob das Programm mit den Einstellungen funktioniert, ruft ihr den seriellen Monitor über den Button mit der Lupe rechts in der Werkzeugleiste auf. 

Das sich daraufhin öffnende Fenster zeigt einige Statusmeldungen und die Kommunikation mit dem OpenSenseMap Server an.

*Wichtig*: Am unteren Rand des Fensters kann man die Übertragungsrate (Baud-Rate) einstellen. Sie muss auf 9600 gesetzt werden.

Wenn alles richtig angeschlossen und das Netzwerk über DHCP konfiguriert wird, könnt ihr den Monitor verfolgen wie kontinuierlich Messungen übertragen werden, und in der Serverantwort die http-Statusmeldung "201 Created" zurückgegeben wird.

## 4. Aufstellen

Hier geben wir einen Vorschlag wie die Station aufgestellt werden kann. Wichtig ist, dass die SenseBox in einem wasserfesten Gehäuse installiert wird und die Sensoren vor direkter Sonneneinstrahlung geschützt werden!

Benötigt wird folgendes:
* kleines geschlossenes Schutzgehäuse (IP 55)
* keines belüftetes (oder nach unten hin offenes) Schutzgehäuse
* Heißkleber

### 4.1 Standortwahl

Die Platzwahl einer Messstation wirkt sich direkt auf die gemessenen Werte aus. Daher solltet ihr euch gut überlegen wo ihr eigentlich messen wollt, bevor ihr die Station fest installiert. Natürlich kann sich der Standort der Station über die Zeit hin ändern, allerding werden die Messungen erst richtig aussagekräftig, wenn man eine längere Zeitreihe an einem Standort aufnimmt.
Damit die Messdaten für die Forschung, aber auch für Bürger interessant werden, empfehlen wir die Station draußen an einem festen Standort zu installieren um möglichst repräsentative Daten für eure Umgebung zu sammeln. Dabei müssen einige Punkte beachtet werden:

* Basisstation muss vor Wasserschäden geschützt werden
* Sensoren sollten vor direkter Sonneneinstrahlung abgeschirmt werden
* Stromversorgung und Netzwerkanschluss muss gewährleistet werden

### 4.2 Wasserfestes Gehäuse

Der Hauptteil der SenseBox Home (*Arduino Uno, Ethernet Shield* und *Grove Base Shield*) muss unter allen Umständen wasserdicht eingeschlossen werden. Daher sollte der Basisteil der Station in einem Gehäuse der Schutzart *IP55* untergebracht werden. Solche Gehäuse sind in jedem Baumarkt oder im Internet erhältlich.
Für die einzelnen Sensoren ist weiterhin folgendes zu beachten:

Barometer sollte..
* ..vor direkter Sonneneinstrahlung geschützt werden.
* ..mit möglichst konstanter Temperatur betrieben werden

Thermometer sollte..
* ..vor direkter Sonneneinstrahlung geschützt werden.
* ..von anderen Wärmequellen getrennt werden.
* ..Luftzufuhr von außen bekommen.

Lichtsensor sollte..
* ..vor direkter Sonneneinstrahlung geschützt werden
* ..nicht in einem undurchsichtigen Gehäuse untergebracht sein

Mikrofon sollte..
* ..nicht in einem komplett geschlossenen Gehäuse untergebracht sein

### 4.3 Exemplarischer Aufbau

Wie bereit erwähnt, muss vor allem das Gehäuse mit der Basisstation Regen- und Spritzwasser abhalten, damit kein Kurzschluss entstehen und die Station nicht beschädigt wird. Dazu wird die Basisstation (siehe folgende Abbildung) mit Heißkleber in ein IP55 Gehäuse geklebt. In dem selben Gehäuse sollte der Drucksensor untergebracht werden, der am besten unter konstanten Temperaturbedingungen arbeitet, was durch die Eigenwärme des Arduino gewährleistet wird.

Die analogen Sensoren (Schall, Temperatur & Luftfeuchte) sollten separat in einem durchlüfteten Gehäuse angebracht werden, für das folgendes gelten muss:

* Regenabweisend und nach oben hin geschlossen 
* Luftdurchlässig durch Belüftungslöcher o. Ä.

*Wichtig*: Die Kabel aller Sensoren, Netzwerk- und Stromkabel müssen nach unten aus dem Gehäuse geleitet werden! Außerdem muss der Stromanschluss unbedingt wasserfest angebracht werden!

|![Exemplarischer Stationsaufbau](images/aufbau.png "Exemplarischer Stationsaufbau") |
|:-------:|
|**Exemplarischer Stationsaufbau**|
