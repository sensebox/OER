# SenseBox Photonik - Bauanleitung

In dieser Anleitung wird schrittweise beschrieben, wie die SenseBox Photonik zusammengebaut und programmiert wird. Außderdem wird erläutert, wie die Station aufgestellt und angeschlossen werden sollte, damit die Datenübertragung auf die OpeneSenseMap reibungslos funktioniert. 

Viel Spaß mit eurer neuen Messstation wünscht euch das SenseBox-Team!

## 1. Inventarliste

Die unten aufgeführte Hardware wird benötigt, um die Umweltstation anhand dieser Anleitung zusammen zu bauen.

### 1.1.a Basiskomponenten der Ethernet Version

|<img src="images/uno_top.png" width="250"/>|<img src="images/Base_Shield_v2.png" width="250"/>|<img src="http://arduino.cc/en/uploads/Main/ArduinoEthernetShield_R3_Front.jpg" width="250"/>|
|:------:|:------:|:------:|
|**Arduino Uno R3**|**Seeed Studio - Base Shield V2**|**Arduino Ethernet Shield R3**|

### 1.1.b Basiskomponenten der WiFi Version

|<img src="images/uno_top.png" width="250"/>|<img src="images/Base_Shield_v2.png" width="250"/>|<img src="images/adafruit-wifi-shield.jpg" width="250"/>|
|:------:|:------:|:------:|
|**Arduino Uno R3**|**Seeed Studio - Base Shield V2**|**CC3000 WiFi Shield**|

### 1.2 Sensoren

|![Grove Barometer - Sensor BMP085](images/pressure_bmp085.png "Grove Barometer - Sensor BMP085")|<img src="http://g01.s.alicdn.com/kf/HT1DC5xFGNXXXagOFbXn/221117824/HT1DC5xFGNXXXagOFbXn.jpg" width="170"/>|
|:--------:|:--------:|
|**Grove Barometer - Sensor BMP085**|**Grove Temperatur/Luftfeuchtigkeit - Sensor DHT22**|
|<img src="images/UV_Sensor_01.jpg" width="170"/> |<img src="images/Digital_Light_Sensor.jpg" width="170"/>|
|**Grove UV - Sensor GUVA-S12D**|**Grove Digital Light Sensor - Sensor TSL2561**|

### 1.3 Zubehör

|<img src="images/power_supply.png" width="250"/>|<img src="images/grove_cable.png" width="250"/>|
|:---------:|:---------:|
|**Netzteil (9V, 0.6A)**|**Universal 4-Pin Kabel für Grove Sensoren**|
|![USB-Kabel (Typ A/B)](images/usb_cable.png "USB-Kabel (Typ A/B)")|![Netzwerkkabel](images/lan_cable.png "Netzwerkkabel")|
|**USB-Kabel (Typ A/B)**|**Netzwerkkabel (nur für Ethernet Version. Nicht im Lieferumfang enthalten!)**|

## 2. Aufbau

Durch das Stecksystem dauert der Aufbau eurer Station nur wenige Minuten. Vorweg ein paar wichtige Hinweise die es zu beachten gilt.

### 2.1 Warnhinweise

* Durch elektrostatische Entladung können die Bauteile beschädigt oder sogar zerstört werden! Daher solltet ihr euch z.B. an einem Heizungsrohr entladen bevor ihr mit dem Aufbau anfangt.
* Elektronische Bauteile und Leiterplatten können herstellungbedingt Chemikalien enthalten. Daher solltet ihr euch nach dem Aufbau die Hände waschen.
* Elektronik sollte umweltfreundlich entsorgt werden und bei Sammelstellen abgegeben werden.

### 2.2 Basisstation aufbauen

Der Kern unserer Station besteht aus drei Komponenten: dem *Arduino Uno* Mikrokontroller, dem *Seeed Studio Base Shield* und dem *Ethernet Shield bzw. WiFi Shield*.

Steckt als erstes das *Base Shield* auf das *Arduino Uno*. Daran werden die Sensoren wie folgt angeschlossen:

* A0: UV Sensor
* A1: Temperatur und Luftfeuchte Sensor
* I2C: Digitaler Lichtsensor 
* I2C: Barometer

Steckt nun das *Ethernet Shield* bzw. das  *WiFi Shield* auf das *Seeed Studio Base Shield* mit den Sensoren. Es erweitert die Station mit der Möglichkeit eine Internetverbindung aufzubauen und als Webclient mit dem OpenSenseMap Server zu kommunizieren.

*Wichtig*: Achtet beim Stapeln der Schields darauf, dass alle Anschlüsse und Steckerleisten korrekt gesteckt sind und keine Kabel beschädigt werden!

### 2.3 Station mit dem Netzwerk verbinden (nur für Ethernet-Version)

**Beim Aufbau der WiFi-Version kann dieser Punkt übersprungen werden**

Bevor der Code hochgeladen wird, solltet ihr die Messstation durch ein Netzwerkkabel mit eurem Heimnetzwerk verbinden. Die Station ist darauf ausgerichtet, dass das angeschlossene Netzwerk DHCP unterstützt. Falls das nicht der Fall sein sollte, solltet ihr eine feste IP (entsprechend der Netzwerkeinstellungen) in dieser Zeile der ino-Datei einstellen:

`IPAddress ip(192,168,1,111);`


## 3. Programmierung

Hier beschreiben wir Schritt für Schritt wie man das *Arduino Uno* anschließen, installieren und programmieren muss. Diejenigen, die bereits Erfahrung im Umgang mit *Arduino-Boards* haben, können direkt die zusätzlichen Bibliotheken installieren und den SenseBox Sketch auf das Board laden. Für Arduino Einsteiger empfiehlt sich hingegen ein Blick auf [Erste Schritte mit Arduino](http://arduino.cc/de/Guide/HomePage), auf der die ersten Schritte mit dem Arduino ausführlich erklärt werden.

### 3.1 Arduino Software installieren

Ladet als erstes das die *Arduino Software* (Version 1.0.5) passend zu eurem Betriebssystem herunter:

[Arduino 1.0.5 für Windows](http://arduino.googlecode.com/files/arduino-1.0.5-r2-windows.zip)

[Arduino 1.0.5 für Linux](http://arduino.googlecode.com/files/arduino-1.0.5-linux32.tgz)

[Arduino 1.0.5 für MAC OS X](http://arduino.googlecode.com/files/arduino-1.0.5-macosx.zip)


*Hinweis: Da bei den neueren Verionen der Arduino Software Probleme beim kompilieren der Software auftreten können empfehlen wir die oben genannte Version.*

Damit die Sensoren einwandtfrei funktionieren braucht ihn noch einige Software Bibliotheken. Die findet ihr gepackt als zip-Datein unter dem folgenden Link:

[Arduino Bibliotheken für die SenseBox](https://github.com/sensebox/arduino/archive/master.zip)

In dieser Datei befindet sich der Ordner "arduino-master", in dem sich wiederum fünf Ordner mit Bibliotheken befinden, um die die *Arduino Software* erweitert werden muss.

Dazu öffnet ihr das Arduino Installationsverzeichnis auf eurer Festplatte. Dort befindet sich das Verzeichnis "libraries", in welches ihr die drei Ordner aus der zip-Datei ("Adafruit_CC3000", "Barometer_Sensor", "Digital_Light_Sensor", "EthernetV2_0" und "Humidity_Temperature_Sensor") kopiert.

**Startet nun das Program neu damit die Änderungen übernommen werden!**

### 3.2 Arduino IDE konfigurieren

Nachdem ihr die Bibliotheken installiert habt, könnt ihr mit dem USB-Kabel die Station an den Rechner anschließen und die *Arduino Entwicklungsumgebung* (kurz: Arduino IDE) öffnen.

Dort müsst ihr unter dem Reiter "Tools" -> "Board" das richtige *Arduino Board* auswählen. In unserem Fall also "Arduino Uno".

|<img src="images/choose_board.png" width="600"/>|
|:-------:|
|**Arduino Board auswählen**|

Außerdem müsst ihr einen seriellen Port angeben, über den die Kommunikation zwischen Computer und Mikrokontroller läuft. Wählt dazu unter "Tools" -> "Serieller Port" den COM-Port aus, der von dem Treiber beim Anschließen des Arduino Uno geladen werden sollte.

|<img src="images/choose_port.png" width="600"/>|
|:-------:|
|**COM-Port auswählen**|

Falls euch dort kein COM-Port zur Auswahl vorgeschlagen wird, lest bitte den [entsprechenden Abschnitt zur Fehlerbehebung](http://arduino.cc/en/pmwiki.php?n=Guide/Windows) auf der Arduino Homepage.

### 3.3 Registrierung auf der OpenSenseMap

Ruft auf der [OpenSenseMap](http://www.opensensemap.org) die Registrierung auf und legt dort eine neue SenseBox Photonik an.
Im Folgenden stehen ein paar Hinweise zu den 5 Schritten der Registrierung.

  1. User Anlegen
    * Euren Namen und eine gültige E-Mail-Adresse angeben, damit unser Support Team Euch erreichen kann und wir nach der Registrierung den Software-Sketch an die richtige Adresse senden können
  2. Meine Box
    * Gebt im ersten Pflichtfeld einen Stationsnamen ein und legt im zweiten Pflichtfeld fest ob sich die Station später drinnen oder draußen befinden soll
    * Optinal könnt Ihr noch ein Gruppenzeichen angeben. Wenn ihr nach 'Gruppenkennzeichen' sucht, könnt Ihr dann alle Stationen in Eurem eigenen Netzwerk anzeigen lassen
  3. Standort
    * Ihr könnt einen Standort direkt über die Karte auswählen oder auch nach einer Adresse suchen (über das Symbol mit der Lupe, links oben im Kartenfenster)
  4. Hardware Setup
    * SenseBox Photonik auswählen und dabei angeben ob Ihr die WiFi- oder Ethernet-Version erhalten habt
  5. Download
    * Überfrüft noch einmal Eure Eingaben und ladet danach den Software-Sketch für Eure SenseBox herunter

### 3.4 Übertragung der ino-Datei auf die SenseBox

Nach erfolgreicher Registrierung wird euch von uns eine ino-Datei zu der angegebenen Mail-Adresse geschickt. Ladet diese Datei herunter und öffnet sie in der *Arduino IDE*.

*Wichtig*: Der erzeugte Code ist genau auf eure Station und eure SenseBox ID angepasst und ist daher nicht für andere SenseBox Stationen gültig.

### 3.5 WiFi Einstellungen (WiFi-Version)

**Kapitel 3.5 ist nur für die WiFi Version gültig**

Um die Station mit eurem WLAN-Zugangspunkt zu verbinden braucht ihr eure Netzwerkkennung (SSID) und das zugehörige Passwort. Eure SSID und euer Passwort müsst ihr einmal in der ino-Datei angeben. Dazu öffnet die Datei und passt die folgenden Zeilen an:

`// WLAN parameters`

`#define WLAN_SSID "WLAN_Name"`

`#define WLAN_PASS "WLAN_Passwort"`

Des weiteren solltet ihr wissen, welche Verschlüsselung euer WLAN-Router benutzt. Die unterstützten Verschlüsselungsmethoden sind WPA, WPA2 und WEP. Meistens wird WPA2 genutzt, daher ist diese Verschlüsselung als Standart eingestellt. Falls ihr das ändern wollt, veränder folgende Zeile:

`// Security can be WLAN_SEC_UNSEC, WLAN_SEC_WEP, WLAN_SEC_WPA or WLAN_SEC_WPA2`

`#define WLAN_SECURITY WLAN_SEC_WPA2`

*Hinweis*: Zeilen im Code die mit `//` beginnen sind einfache Kommentare und werden vom Compiler nicht mit übersetzt und auch nicht mit auf das Board geladen. Sie dienen einfach zur besseren Orientierung oder zur Dokumentation.

### 3.6 Sketch auf das Arduino Board hochladen

Der Sketch wird auf das *Arduino Uno* geladen, indem ihr auf das Pfeil-Symbol links in der Werkzeugleiste der Arduino IDE klickt. Nach einer kurzen Weile bekommt ihr eine Rückmeldung vom Programm, dass der Sketch kompiliert und hochgeladen wurde. Um nun zu testen ob das Programm mit den Einstellungen funktioniert, ruft ihr den seriellen Monitor über den Button mit der Lupe rechts in der Werkzeugleiste auf. 

Das sich daraufhin öffnende Fenster zeigt einige Statusmeldungen und die Kommunikation mit dem OpenSenseMap Server an.

*Wichtig*: Am unteren Rand des Fensters kann man die Übertragungsrate (Baud-Rate) einstellen. Sie muss auf 9600 gesetzt werden.

Wenn alles richtig angeschlossen und das Netzwerk über DHCP konfiguriert wird, könnt ihr den Monitor verfolgen wie nach einiger Zeit kontinuierlich Messungen übertragen werden, und in der Serverantwort die http-Statusmeldung "201 Created" zurückgegeben wird.

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

Der Hauptteil der SenseBox Photonik (*Arduino Uno, Ethernet Shield/WiFi Shield* und *Seeed Studio Base Shield*) muss unter allen Umständen wasserdicht eingeschlossen werden. Daher sollte der Basisteil der Station in einem Gehäuse der Schutzart *IP55* untergebracht werden. Solche Gehäuse sind in jedem Baumarkt oder im Internet erhältlich.
Für die einzelnen Sensoren ist weiterhin folgendes zu beachten:

Barometer sollte..
* ..vor direkter Sonneneinstrahlung geschützt werden.
* ..mit möglichst konstanter Temperatur betrieben werden

Thermometer sollte..
* ..vor direkter Sonneneinstrahlung geschützt werden.
* ..von anderen Wärmequellen getrennt werden.
* ..Luftzufuhr von außen bekommen.

Lichtsensor sollte..
* ..nicht in einem undurchsichtigen Gehäuse untergebracht sein
