#Die senseBox:edu

Die SenseBox:edu ist ein Werkzeugkasten, der Schülerinnen und Schülern sowie Nachwuchsforscherinnen und -forschern das Programmieren spielerisch und greifbar vermitteln soll. Dazu werden einfache Schaltungen aufgebaut, die mit Hilfe eines Mikrokontrollers programmiert und gesteuert werden. Die verwendeten Mikrokontroller basieren auf der einsteigerfreundlichen Arduino Plattform, die mit einer C-ähnlichen Sprache über eine simple Programmieroberfläche (Abkürzung IDE, engl. für Integrated Development Environment) gesteuert werden. Zusammen mit dieser Anleitung und dem Bauteilsortiment vermittelt die SenseBox Edu einen praxisnahen Einstieg in die Programmierung sowie eine schrittweise Einführung zur Gestaltung eigener Technikprojekte aus den Bereichen Geoinformatik, Sensorik und Photonik. Wie zum Beispiel Projekte zur Thematik Zukunftsstadt.

##Inhalt der Kiste

<img src="https://github.com/sensebox/OER/blob/master/senseBox_edu/images/Kisteninhalt.png/"/>

1. Basisstation
Die Grundlage für unsere Experimente bildet die Basisstation. Sie besteht aus einem Arduino Uno Mikrokontroller, dem senseBox Shield und einem Steckbrett. Letzteres besteht aus jeweils zwei vertikalen Reihen für die Plus- und Minusanschlüsse sowie zweimal 30 horizontalen Reihen mit je fünf Bohrungen, die mit a bis e bzw. f bis j beschriftet sind. Die Plus- und Minusanschlüsse sowie die fünf horizontalen Bohrungen einer Reihe sind, wie unten dargestellt, leitend miteinander verbunden.

<center><img src="https://github.com/sensebox/OER/blob/master/senseBox_edu/images/Breadboard.png" width="300"></center>

Das senseBox Shield ist eine Erweiterungsplatine für den Mikrokontroller, und wird einfach auf ihn drauf gesteckt (daher die Bezeichnung Shield). Es bietet die Möglichkeit Messungen auf einer microSD Karte abzuspeichern und zukünftige Upgrades mit den Steckverbindungen auf der Oberseite freizuschalten. Des Weiteren ist in der Platine eine Uhr eingebaut (Abkürzung RTC, engl. für Real-Time Clock), die aktiviert wird, sobald die Batterie aus dem Kleinteileset eingebaut wurde.

2. Netzteil
Normalerweise wird der Mikrokontroller über ein USB Kabel mit einem Computer verbunden. Hast du ihn einmal programmiert, ist diese Verbindung nicht mehr nötig, da das aktuelle Programm fortlaufend auf ihm ausgeführt wird. Das einzige was dann benötigt wird, ist eine konstante Stromversorgung.

3. Batterypack
Durch das Batterypack lassen sich deine Experimente mobil nutzen! Das ist vor allem sinnvoll, wenn du beispielsweise Temperaturwerte an unterschiedlichen Orten messen willst.

4. Ethernet Shield
Hiermit lassen sich Messwerte direkt ins Internet übertragen und beispielsweise auf einer Kartenanwendung wie der OpenSenseMap darstellen.

5. Kabelsortiment
Neben dem bereits erwähnten USB Kabel, beinhaltet das Sortiment noch ein Verbindungskabel für die Batteriehalterung sowie die Steckkabel die zur Verbindung zwischen Steckbrett und Mikrokontroller notwendig sind.

6. Sensoren und Kleinteile
Hier haben wir Sensoren und andere Komponenten zusammengestellt, die für deine Experimente notwendig sind. Das Kleinteilset beinhaltet die folgenden Teile:
	* Leuchtdioden (Abküzung LED, engl. für Light-Emitting Diode)
	* Druckknöpfe
	* 470 Ω und 10 kΩ Widerstände
	* RGB-LED
	* Lichtabhängiger Widerstand (Abkürzung LDR.engl. für Light-Dependant Resistor)
	* Potentiometer
	* Mikrofon
	* Summer
	* Kombinierter Temperatur- und Luftfeuchtigkeitssensor (HDC 1008)
	* Luftdrucksensor (BMP 280)
	* Infrator-Distanzsensor (GP2YA60)
	* Ultraschall-Distanzsensor (HC-SR04)
	* Lichtsensor (TSL 45315)
	* UV-Sensor (VEML6070)
	* microSD-Karte mit Adapter
	* Batterie für das senseBox Shield
	