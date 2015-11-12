<img src="https://github.com/sensebox/OER/blob/master/senseBox_edu/images/sensebox_logo_neu.png" width="200"/> 

# Station 3 - Auswerten analoger Signale

Straßenlaternen gehen in Städten immer zu bestimmten Uhrzeiten an und aus. Um Strom zu sparen, könnte man je nach Helligkeit die Laternen automatisch an- und ausschalten. 

## Ziel der Station
In dieser Station wirst du lernen einen analogen Sensor auszulesen und die Messwerte einer Variable zuzuordnen. Außerdem verwendest du zum ersten Mal die if-else Kontrollstruktur.

## Materialien
* LDR
* 10 kΩ Widerstand

## Grundlagen
Der Photowiderstand (Abkürzung LDR, engl. für Light Dependent Resistor) ist ein analoger, lichtabhängiger Widerstand, der eine einfache Möglichkeit bietet die Helligkeit zu messen. Ist der Lichteinfall hoch, sinkt der Widerstandswert, ist er gering, steigt er. 
In Abhängigkeit von den Lichtverhältnissen ändert sich der Widerstandswert des LDR und die Spannung fällt ab. Um diese Veränderung zu messen, benötigen wir den zweiten konstanten Widerstand zum Vergleich.

Zum Auslesen des LDRs verwendet man den Befehl analogRead(). Der Befehl liest einen bestimmten analogen Pin aus. Der Arduino-Mikrokontroller hat einen 10 Bit Konverter, um analoge in digitale Signale umzuwandeln. Er wandelt Spannungswerte von 0 bis 5 Volt in ganzzahlige Werte von 0 bis 1023 um. Ein beispielhafter Befehl wäre also analogRead(A2), wenn ein analoger Sensor am analogen Eingang 2 angeschlossen ist.

##Aufbau

<image src="https://github.com/sensebox/OER/blob/master/senseBox_edu/images/LDR_analog_Sensor.png"/>

##Aufgabe 1
Baue die abgebildete Schaltung nach und benutze die Befehle analogRead( ) und Serial.println(), um Dir die gemessenen Daten im seriellen Monitor anzeigen zu lassen.

***Tipp:***  *Denke daran die Variablen entsprechend deiner Schaltung zu benennen und den seriellen Monitor (s. Station 2) zu starten.*

##Grundlagen
Eine wichtige Kontrollstruktur beim Programmieren sind if-else-Bedingungen. Eine if-Abfrage prüft ob eine Bedingung wahr ist. Wenn sie wahr ist, wird der darauffolgende Block mit Anweisungen ausgeführt, ist sie falsch wird er übersprungen oder man definiert einen alternativen else-Block mit Anweisungen.
```
if (Sensorwert < 100){
 //Block mit Anweisungen für wahr
}
else {
 //Block mit Anweisungen für falsch
}
```

##Aufgabe 2
Baue jetzt eine intelligente Straßenbeleuchtung. Erweitere hierfür die Schaltung um eine LED und schreibe einen Sketch, der diese bei einer bestimmen Helligkeit aufleuchten lässt. 

***Tipp:*** *Verwende dazu die if-else-Bedingung*

## Aufgabe 3

Erweitere die Schaltung aus Aufgabe 2 so, dass sie als Lichtampel arbeitet. Das heißt, je nach Helligkeit im Raum sollte eine von drei LEDs aufleuchten, um so ablesen zu können, ob es hell oder dunkel ist.