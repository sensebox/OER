senseBox Home -- Bauanleitung
===================

> **Warnhinweise:**

> - Durch elektrostatische Entladung können die Bauteile beschädigt oder sogar zerstört werden! Daher solltet ihr euch z.B. an einem Heizungsrohr entladen, bevor ihr mit dem Aufbau anfangt.
> - Elektronische Bauteile und Leiterplatten können Chemikalien enthalten. Daher solltet ihr nach dem Aufbau oder Gebrauch euch die Hände waschen.
> - Elektronik sollte umweltfreundlich entsorgt und bei Sammelstellen abgegeben werden.

---
###0. Inhalt der SenseBox
Bevor es los geht, solltet ihr unbedingt überprüfen, Ob alle Bauteile vorhanden sind. Unterhalb findet ihr dazu eine Inventarliste.

<image src="https://github.com/sensebox/OER/blob/master/senseBox_home/images/01_contents.png"/>

**A. Basisstation bestehend aus drei Platinen:**

- Zu unterst der Mikrocontroller Wattuino Uno, der die angeschlossenen Sensoren ausließt und die Messungen ins Internet überträgt
- Das W5500 Ethernet Shield in der Mitte ist eine Netzwerkkarte und wird für die Internetverbindung benötigt
- Ganz oben in grün ist unser SenseBox Shield, an dem die Sensoren angeschlossen werden

**B. Grundausstattung mit vier Sensoren:**
 
- Kombiniertes Thermo- und Hygrometer HDC1008 – Temperatur in Grad Celsius (°C) und relative Luftfeuchte in Prozent (%)
- Barometer BMP280 – Luftdruck in Pascal (pa)
- Luxmeter TSL45315 – Beleuchtungsstärke des sichtbaren Lichts in Lux (lx)
- UV-Lichtsensor VEML6070 – Intensität der ultravioletten Strahlung in Mikrowatt pro Quadratzentimeter (μW/cm2)

**C. Anschlusskabel für Sensoren und USB-Verbindung**
 
- 1x USB-Kabel für den Anschluss des Mikrocontrollers an den Computer
- 1x langes Verbindungskabel für Thermometer bzw. Hygrometer
- 3x kurzes Verbindungskabel für Barometer, Luxmeter und UV-Lichtsensor

**D. Netzteil für den Stromanschluss**

---

### 1. Zusammenbau der SenseBox
Hier wird in nur wenigen Schritten eure Messstation zusammengebaut.
####1.1 Sensoren Anschließen
In Fach B der SenseBox befinden sich die vier kleinen Platinen mit den Sensoren. Die eigentlichen Sensoren sind nur wenige Millimeter groß und befinden sich auf der Oberseite der Platinen. Um einer Beschädigung vorzubeugen, solltet ihr die kleinen Sensoren nicht berühren, sondern die Platinen am Rand anfassen. Der Anschluss der Sensoren ist denkbar einfach: Benutzt die Verbindungskabel, um die Sensoren mit den mittleren Steckplätzen auf der Basisstation zu verbinden. Welchen Anschluss ihr dabei nutzt spielt keine Rolle.

<image src="https://github.com/sensebox/OER/blob/master/senseBox_home/images/02_connection.png"/>

Das Netzteil braucht ihr erst später, um die Station draußen aufzubauen.


#### 1.3 Zusätzliches Zubehör
Um die SenseBox draußen aufzubauen, braucht ihr noch ein ausreichend langes Netzwerkkabel, sowie ein Gehäuse. Bei dem Gehäuse müsst ihr darauf achten, dass es einen transparenten Deckel ohne Filterwirkung hat, damit sinnvolle Lichtmessungen gemacht werden können. Zusätzliche Kosten für ein Gehäuse belaufen sich 20 bis 30 Euro. Der Einbau der SenseBox in ein Gehäuse wird nicht in dieser Anleitung thematisiert, zusätzliche Tutorials dafür findet ihr aber auf unserer Homepage.

---

###2. Vorbereitung
Bevor die SenseBox aktiviert werden kann müsst ihr Treiber, sowie eine Software auf eurem Computer installieren. Außerdem ist es vor Inbetriebnahme der SenseBox ratsam, einen Testlauf durchzuführen, um zu überprüfen, ob die Sensoren korrekt funktionieren und die Kommunikation mit dem Internet reibungslos läuft. Wir erläutern hier die Installation für Windows 7.

Falls etwas bei dem Testlauf schief geht, meldet euch am besten bei unserem Support. Kontaktdaten und Ansprechpartner findet ihr im Anhang.

####2.1 Arduino Software installieren
Das Mainboard der SenseBox ist eine modifizierte Version des Arduino Uno Mikrocontrollers. Um ein Programm auf das Board zu laden, braucht ihr die integrierte Entwicklungsumgebung von Arduino, kurz Arduino IDE. So ladet ihr die neuste Version als Zip-Datei von der Arduino Homepage herunter:

[www.arduino.cc/en/main/software](https://www.arduino.cc/en/main/software)

<image src="https://github.com/sensebox/OER/blob/master/senseBox_home/images/03_arduino-dl.png"/>

Arduino ist ein Open Source Projekt und wird durch Spenden mit finanziert. Daher werdet ihr vor dem Download nach einer Spende gefragt, das könnt ihr überspringen indem ihr auf „Just Download“ klickt.

<image src="https://github.com/sensebox/OER/blob/master/senseBox_home/images/04_donate.png"/>

Legt auf eurer Festplatte einen neuen Ordner an und entpackt darin die Zip-Datei.

####2.2 Arduino Erweiterungen installieren
Um die Sensoren und die Netzwerkkarte nutzen zu können, müssen noch ein paar Erweiterungen installiert werden. Ladet auf der folgenden Seite die Dateien herunter, indem ihr rechts auf der Seite auf „Download ZIP“ klickt:

[github.com/sensebox/home](https://github.com/sensebox/home)

<image src="https://github.com/sensebox/OER/blob/master/senseBox_home/images/05_git-dl.png"/>

Integriert nun die beiden Ordner „examples“ und „libraries“ aus dem „home-master“ Verzeichnis in der „home-master.zip“ Datei in den Arduino Ordner. Wenn ihr gefragt werdet ob bestehende Dateien ersetz werden sollen, folgt den Anweisungen unten auf der Seite.

<image src="https://github.com/sensebox/OER/blob/master/senseBox_home/images/06_copy.png"/>

Setzt im folgenden Dialogfeld den Haken unten und bestätigt mit „Ja“. Daraufhin öffnet sich ein neues Fenster, in dem ihr wieder den Haken setzt, und „Kopieren und ersetzen“ auswählt.

<image src="https://github.com/sensebox/OER/blob/master/senseBox_home/images/07_replace.png"/>

####2.3 Treiber Installieren
Ladet zum Schluss noch einen aktuellen FTDI Treiber für euer Betriebssystem runter und installiert ihn. Den passenden Treiber findet ihr in einer Tabelle weiter unten auf der Seite:
[www.ftdichip.com/Drivers/VCP.htm](http://www.ftdichip.com/Drivers/VCP.htm)

<image src="https://github.com/sensebox/OER/blob/master/senseBox_home/images/08_driver.png"/>

Entpackt die Datei und installiert den Treiber mit einem Doppelklick auf „dpinst-x86.exe“. Falls ihr ein 64 Bit Betriebssystem nutzt, erscheint eine Meldung, woraufhin ihr die Anwendung „dpinst-amd64.exe“ ausführen müsst. Nachdem die Installation fertig ausgeführt wurde sollte folgender Dialog erscheinen:

<image src="https://github.com/sensebox/OER/blob/master/senseBox_home/images/09_ready.png"/>

Verbindet die SenseBox über das USB-Kabel mit eurem Computer. Wenn ihr die SenseBox zum ersten Mal mit dem Computer verbindet müsst ihr kurz warten, bis der Mikrocontroller von Windows erkannt wurde. Das kann unter Umständen ein paar Minuten dauern. Unten rechts in der Taskleiste wird dann eine entsprechende Meldung erscheinen:

<image src="https://github.com/sensebox/OER/blob/master/senseBox_home/images/10_tray.png"/>

####2.4 Sensoren und Internetverbindung testen
Weiter geht’s mit den folgenden Schritten:

 - Arduino Anwendung starten
 - Unter Werkzeuge → Board das Arduino Uno auswählen
 - Unter Werkzeuge → COM-Port den entsprechenden Anschluss wählen
 
Falls bei Schritt 3 mehrere Auswahlmöglichkeiten angezeigt werden, müsst ihr zuerst den richtigen COM-Port im Geräte Manager raus suchen. Dazu findet ihr eine ausführliche Beschreibung im Anhang. Ladet nun das Programm, um die Sensoren zu testen und übertragt es auf die Messstation:

 - In der Menüleiste Datei → Beispiele → SenseBox → _01_sensor_test auswählen
 - Das Programm über das **Pfeil** Icon auf den Mikrocontroller laden
 - Warten bis das Programm übertragen wurde
 - Den seriellen Monitor über das **Lupe** Icon starten

Ihr könnt durch experimentieren überprüfen, ob Temperatur, Luftfeuchtigkeit oder
Beleuchtungsstärke sich verändern. Der Luftdruck lässt sich nicht ohne weiteres beeinflussen. Er sollte grob, je nach Höhenlage und Wetterverhältnissen, zwischen 60.000 Pa und 100.000 Pa liegen. Die Intensität des UV-Lichts kann nur mit speziellen Lampen oder durch direkte Sonneneinstrahlung getestet werden. In einem geschlossen Raum sollte keine bzw. nur minimale UV-Strahlung gemessen werden können.

<image src="https://github.com/sensebox/OER/blob/master/senseBox_home/images/11_serial1.png"/>

Nun wird noch die Internetverbindung getestet:

- Seriellen Monitor (Fenster mit den Messwerten) schließen
- Netzwerkkabel von eurem Heimnetzwerk mit der SenseBox verbinden
- In Menüleiste Datei → Beispiele → SenseBox → _02_network_test auswählen
- Das Programm über das **Pfeil** Icon auf den Mikrocontroller laden
- Den seriellen Monitor über das **Lupe** Icon starten

Wenn die Verbindung klappt, bekommt ihr eine entsprechende Meldung im seriellen Monitor angezeigt.

<image src="https://github.com/sensebox/OER/blob/master/senseBox_home/images/12_serial2.png"/>

---

###3. Online Aktivierung
Hier wird die Einbindung der SenseBox in unser Sensornetzwerk durch die Registrierung auf der OpenSenseMap beschrieben.

####3.1 Registrierung auf der OpenSenseMap
Ein Software-Programm für einen Arduino Mikrocontroller könnt ihr an der Dateiendung „.ino“ erkennen. Eine solche Ino-Datei benötigt ihr, um eure SenseBox mit der OpenSenseMap im Internet zu verbinden. Den passenden Sketch bekommt ihr zusammen mit einer E-Mail zugeschickt, wenn ihr eure Station bei auf der OpenSenseMap registriert.
Öffnet dazu die folgende Internetseite und wählt die Option "Registrierung" aus. Folgt dort den 5 Schritten zur Registrierung.
[www.opensensemap.org](http://www.opensensemap.org)

#### <i class="icon-folder-open"></i> Serieller Monitor

Bei Schritt 4 der Registrierung wirst du nach einem Hardware Setup gefragt. Wähle dort die „senseBox:home“ aus und setze danach den Haken bei „senseBox:home mit Ethernet“.

####3.2 Programm auf die Station laden
Nachdem ihr den Anhang der Email herunter geladen habt, müsst ihr dieses Programm auf eure SenseBox laden. Wie man genau ein Programm auf den Mikrocontroller lädt, ist bereits in Abschnitt 2.3 ausführlich erklärt worden. Hier die Schritte in der Übersicht:

- Arduino Anwendung öffnen
- In der Menüleiste Datei → Öffnen auswählen und die „sensebox.ino“ Datei auswählen
- Dialog mit „Ja“ bestätigen
- Das Programm über das **Pfeil** Icon auf den Mikrocontroller laden
- Warten bis das Programm übertragen wurde

Wenn alles richtig gelaufen ist, könnt ihr nun auf der OpenSenseMap eure Station auswählen und verfolgen wie kontinuierlich Messungen übertragen werden. Probiert es aus und sucht dort eure SenseBox!
