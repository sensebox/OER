<img src="https://github.com/sensebox/OER/blob/master/senseBox_edu/images/sensebox_logo_neu.png" width="200"/> 

# Station 1 - Einfache Steuerung einer Leuchtdiode

Lichtsignale umgeben uns in unserem Alltag. Vor allem im Straßenverkehr blinkt und leuchtet es ständig. Aber wie funktioniert z.B. eine Ampel?

## Ziele der Station

In dieser Station lernst du den Arduino Uno Mikrokontroller kennen und startest mit der Programmierung eines ersten simplen Programmes. Hierzu lernst du den generellen Aufbau des Arduino-Programmcodes und die ersten Kontrollstrukturen kennen.

## Materialien
* LED
* 470 Ω Widerstand (blau)

## Grundlagen
Ein Arduino Programm (auch Sketch genannt) hat einen sehr einfachen Aufbau, der aus zwei Hauptbestandteilen besteht. Diese zwei benötigten Teile enthalten Blöcke von Anweisungen:

```
void setup(){
    //Anweisungen
  }
  void loop(){
    //Anweisungen
  }
```
Die setup-Funktion wird nur einmal beim Start des Programmes ausgeführt. In der loop-Funktion werden hingegen alle Anweisungen fortlaufend in einer endlosen Schleife wiederholt. Beide Funktionen sind zwingend notwendig um das Programm erfolgreich kompilieren und ausführen zu können.
Mit einem doppelten Schrägstrich „//“ lassen sich Kommentare zum Programmcode hinzufügen. Es ist immer wichtig seinen Programmcode zu kommentieren, damit auch andere nachvollziehen können, was an einer bestimmten Stelle passiert.

Beginnen wir mit einem Sketch, um eine LED zum Leuchten zu bringen:
```
void setup() {
  pinMode(13, OUTPUT); // Deklariere den Port, an dem die LED            
                        // angeschlossen ist, als Ausgang
}

void loop() {
  digitalWrite(13, HIGH); // Schalte die LED an
}
´´´
Vor der setup-Funktion kann mit dem Befehl int led = 13 dem Port 13, an dem die LED angeschlossen ist, ein Name gegeben. Indem man dem Port einen Namen gibt, kann er im Verlauf des Sketches immer wieder angesprochen werden ohne die Nummer des Ports wiederholen zu müssen. So werden spätere Änderungen an der Schaltung erleichtert, da man an nur einer Stelle im Sketch den Port ändern muss.
In der setup-Funktion wird mit dem Befehl pinMode(led, OUTPUT) der Port der LED als Output, also Ausgang, definiert. Ohne diesen Befehl leuchtet die LED nicht, da kein Strom an den Port geschickt wird. Im letzten Schritt der Programmierung wird in der loop-Funktion die LED schließlich angeschaltet. Dazu benutzt man den Befehl digitalWrite(led, HIGH).

***WICHTIG:*** *Jede Anweisung wird jeweils mit einem Semikolon abgeschlossen. Solltest du einmal das Semikolon vergessen, wird sich das Programm melden und dir den Fehler anzeigen. Das Programm kann deinen Sketch allerdings nicht auf logische Fehler überprüfen.*

##Aufbau
<image src="https://github.com/sensebox/OER/blob/master/senseBox_edu/images/Aufbau_Station_1.png"/>

##Aufgabe 1
Erstelle eine Schaltung in der die LED mit dem Arduino verbunden wird. Nachdem du alles verkabelt hast, kopiere deinen Sketch in die Arduino IDE.

##Aufgabe 2
Erstelle einen Sketch, in dem die LED blinkt. Die Schaltung kann aus der ersten Aufgabe übernommen werden.

***Tipp:*** *Mit dem Befehl delay(1000); kann der Programmcode unterbrochen werden. 1000 gibt dabei die Zeit in Millisekunden an. 
Um eine LED auszuschalten, benötigst du den Befehl  digitalWrite(LED, LOW);*

##Aufgabe 3
Wir wollen nun den Verkehr in einer Stadt steuern. Baue dazu eine Verkehrsampel! Nutze hierfür die anderen LEDs, Widerstände und weitere digitale Anschlüsse.

***WICHTIG:*** *Es muss immer ein Widerstand (470 Ohm, blau) vor eine LED geschaltet werden! 
*


