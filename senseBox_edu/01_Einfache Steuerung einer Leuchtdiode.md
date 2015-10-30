# Station 1 - Einfache Steuerung einer Leuchtdiode

Lichtsignale umgeben uns in unserem Alltag. Vor allem im Straßenverkehr blinkt und leuchtet es ständig. Aber wie funktioniert z.B. eine Ampel?

## Ziele der Station

In dieser Station lernst du den Arduino Uno Mikrokontroller kennen und startest mit der Programmierung eines ersten simplen Programmes. Hierzu lernst du den generellen Aufbau des Arduino-Programmcodes und die ersten Kontrollstrukturen kennen.

## Materialien
- LED
- 470 Ω Widerstand (blau)

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



