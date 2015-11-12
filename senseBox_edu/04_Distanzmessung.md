<img src="https://github.com/sensebox/OER/blob/master/senseBox_edu/images/sensebox_logo_neu.png" width="200"/> 

#Station 4 - Distanzmessung
Städtischer Verkehr belastet die Umwelt und stresst die Bürger. Ähnlich verhält es sich mit der Parkplatzsuche. durch automatisierte Verkehrszählung und automatische Erkennung von freien Parklücken können Verkehrsströme und Parkplatzsuche besser gesteuert werden. Aber wie lassen sich Verkehr und die Belegung von Parklücken sinnvoll messen?

##Ziel der Station
In dieser Station wirst du zwei Arten der elektronischen Distanzmessung kennenlernen. Dazu wirst du einen Ultraschall- und einen Infrarot-Distanzsensor programmieren.

##Materialien
* Ultraschall-Distanzsensor
* IR-Distanzsensor

##Grundlagen
Die beiden Arten der Distanzmessung, mit denen du dich beschäftigen wirst, sind die Messung mittels Infrarotlicht und Ultraschallwellen.
Die Entfernungsmessung mit Infrarotlicht erfolgt durch eine sog. Triangulation. Eine Triangulation ist eine geometrische Methode, Distanzen durch genaue Winkelmessung innerhalb eines Dreiecks zu ermitteln. Damit der Sensor Entfernungen messen kann, benötigt er zwei Bauteile: eine IR-Diode und eine sogenannte ortsauflösende Photodiode. Die IR-Diode sendet einen Infrarotstrahl aus und das von einem Objekt reflektierte Licht wird von der ortsauflösenden Photodiode empfangen. Ändert sich nun die Entfernung des Objektes vom Sensor, ändert sich auch der Winkel, in dem das Licht reflektiert und wieder empfangen wird. Mit dem gemessenen Winkel wird mit Hilfe der Winkelfunktionen die Entfernung des Objektes von der Lichtquelle errechnet. 

Die zweite Methode eine Distanz mit Hilfe elektronischer Sensoren zu messen, ist die Ultraschall-Distanzmessung. Ein Ultraschall-Distanzsensor bestimmt die Entfernung eines Objektes, indem er die Zeit misst, die ein Schallimpuls zum Objekt hin und zurück benötigt. Der Ultraschallsensor besteht aus zwei Membranen. Die eine produziert den Schall und die andere empfängt das Echo, also fast so wie Lautsprecher und Mikrofon. Wurde ein Schallimpuls ausgesendet, startet eine Stoppuhr, welche die Zeit misst, bis das Echo die zweite Membran erreicht. Aus der gemessenen Zeit lässt sich dann mit Hilfe der Schallgeschwindigkeit (1235,5 km/h) die vom Schall zurückgelegte Strecke errechnen. Die Entfernung zum Objekt entspricht der Hälfte der zurückgelegten Strecke.

##Aufbau
<image src="https://github.com/sensebox/OER/blob/master/senseBox_edu/images/Aufbau_Station_4_IR.png"/>

##Aufgabe 1
Baue die oben abgebildete Schaltung nach und schreibe einen Sketch, der Dir die Entfernungen von Objekten anzeigen kann.

***Tipp:*** *Der in der SenseBox verwendete Infrarot Distanzmesser gibt ein analoges Signal aus und kann nur Distanzen zw. 10 und 80cm messen. Der gemessene Wert kann mit einer Formel in die Distanz in Zentimetern umgerechnet werden:

Distanz =  4800/(Sensorwert - 20)

Informationen wie die Umrechnungsformeln der Sensoren gibt es immer in den Datenblättern der Hersteller.*

##Aufgabe 2
Baue den Aufbau zum Ultraschallsensor nach und erweitere den Sketch in den Grundlagen so, dass Dir die Entfernungen im Seriellen Monitor angezeigt werden.

##Aufbau
<image src="https://github.com/sensebox/OER/blob/master/senseBox_edu/images/Aufbau_Station_4_US.png"/>

##Grundlagen

```
int Sender = 7;
int Empfaenger = 9;
int time = 0;
int distance = 0;
```
int deklariert eine Integer-Variable. Integer Variablen können Werte von -32.768 bis 32.767 annehmen.

```
void setup(){
  pinMode(Sender, OUTPUT);
  pinMode(Empfaenger, INPUT);
}

void loop(){	
digitalWrite(Sender, HIGH);
  delayMicroseconds(10);
  digitalWrite(Sender, LOW);
```
In diesem Abschnitt des Sketches wird das Ultraschall-Signal ausgesendet. Mit dem Befehl delayMicroseconds wird die Dauer des Impulses festgelegt.
```
  time =pulseIn(Empfaenger, HIGH);
  distance=time /58;
  delay(100);
}
```
Dieser Abschnitt dient dazu, die Zeit vom Aussenden des Impulses bis zum Empfangen des Echos zu stoppen und in der Variable time zu speichern. Im nächsten Schritt wird mit Hilfe der Umrechnungsformel aus der Zeit eine angenäherte Distanz berechnet.

##Aufgabe 3
Wir wollen nun einen Verkehrszähler auf Basis des Ultraschallsensors bauen. Simuliere die Straße auf dem Tisch und teste den Verkehrszähler im kleinen Maßstab

***Tipp:*** *Lege eine Variable an, in der die Anzahl der gezählten Fahrzeuge gespeichert wird. Um den Wert einer Variable schrittweise zu erhöhen, verwendet man die folgende Anweisung zaehler++;. Um Mehrfachzählungen eines einzelnen Fahrzeugs zu verhindern, musst du eine zusätzliche Bedingung erstellen. Die Bedingung deaktiviert nach einer erfolgreichen Zählung den Zählvorgang und gibt diesen erst wieder frei, nachdem eine zuvor definierte Maximaldistanz gemessen wurde.*
