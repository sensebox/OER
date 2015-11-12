<img src="https://github.com/sensebox/OER/blob/master/senseBox_edu/images/sensebox_logo_neu.png" width="200"/> 

#Station 2 - Messung digitaler Signale

##Ziele der Station
In dieser Station wirst du lernen, wie man einen digitalen Sensor ausliest und die eintreffenden Daten in einer Variable speichert und anzeigen lässt. Zu guter Letzt wirst du eine wichtige Kontrollstruktur kennenlernen: die if-else-Bedingung.

##Materialien
* Knöpfchen
* 10 kΩ Widerstand (orange)

##Grundlagen
Um Dir Informationen aus deinem Programm (z.B. den Wert einer Variable) anzeigen zu lassen, verwendest du den Seriellen Monitor.
Um Ausgaben im Seriellen Monitor zu ermöglichen, musst du folgenden Befehl zur setup Funktion hinzufügen:
```
Serial.begin (9600)
```
Die Zahl 9600 steht dabei die Schrittgeschwindigkeit (auch Baudrate genannt).
Zur Ausgabe der Informationen benutzt du in der loop-Funktion die Befehle

```
Serial.print(Variable);
Serial.println(Variable);	
Serial.print(“Hallo Welt”);
```
Eine Variable kann einfach in die Klammern geschrieben werden, möchtest du jedoch ein Wort oder einen Satz (eine solche Zeichenkette nennt sich String) anzeigen lassen, musst du diesen in Anführungszeichen stellen.
Der Anhang ‘ln’ hat zur Folge, dass jede Information in einer neuen Zeile (ln = line) angezeigt wird. Ein Sketch würde also wie folgt aussehen:

```
void setup(){
  Serial.begin (9600);
}

void loop(){
  Serial.println(„SenseBox rocks“);
}
```
Um eingehende Signale verarbeiten zu können, müssen sie in Variablen gespeichert werden. Eine Variable ist die Benennung einer Information mit einem Namen und Speicherplatz für die spätere Verwendung. Wie der Name schon vermuten lässt, können Variablen ihre Werte kontinuierlich verändern und stehen somit im Gegensatz zu Konstanten, deren Wert über den kompletten Programmablauf gleich bleibt. In Variablen können verschiedene Arten von Daten gespeichert werden, z.B. Zeichenketten (=Strings) oder ganze Zahlen (=int). Strings und Integer sind solche Datentypen, von denen du später noch weitere kennenlernen wirst. Jede Variable muss von einem bestimmten Datentyp sein.
Der erste Datentyp den du verwenden wirst, ist boolean. Boolean-Variablen können nur die Werte 1 oder 0, oder anders gesagt wahr oder falsch / an oder aus, annehmen.
Um eine Boolean-Variable anzulegen, benutzt man folgenden Befehl:

```
boolean TestVariable=0
```
Die so angelegte Variable hat einen Anfangswert von 0. Um die neue Variable jetzt mit einem Wert zu versehen, benutzt man folgenden Befehl:

```
TestVariable = digitalRead (2);  
```

digitalRead überprüft den aktuellen Status des Ports. Auch hier können wieder die Zustände HIGH (es fließt Strom) oder LOW (es fließt kein Strom) eintreten. Wichtig: Ist der Port nicht belegt, wird einer der beiden Zustände zufällig ausgegeben.  

##Aufbau

<image src="https://github.com/sensebox/OER/blob/master/senseBox_edu/images/aufbau_station_2.png"/>

##Aufgabe 1
Lass Dir die folgenden Sätze im seriellen Monitor anzeigen:

“Hallo Welt!”
“SenseBox rocks!”

##Aufgabe 2
Nachdem du einen digitalen Port in Station 1 schon als OUTPUT benutzt hast, verwendest du ihn jetzt als INPUT. Baue also die abgebildete Schaltung nach und schreibe einen Sketch, um den Button auszulesen! Benutze die oben erklärten Befehle zum seriellen Monitor, zur Definition von Variablen und Auslesen von digitalen Ports.

***Tipp:*** *Auch hier musst du, wie in Station 1, die jeweiligen Ports als INPUT oder OUTPUT deklarieren.*

##Aufgabe 3
Baue eine Schaltung, in der beim Drücken des Buttons, eine LED aufleuchtet.

***Tipp:*** *Die boolean Variable lässt sich analog zu HIGH oder LOW verwenden:*
´´´
digitalWrite (LED, boolean Variable);
``


