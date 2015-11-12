<img src="https://github.com/sensebox/OER/blob/master/senseBox_edu/images/sensebox_logo_neu.png" width="200"/> 

# Programmierung des Arduino Uno
Hier lernst du Schritt für Schritt wie man das Arduino Uno anschließt, Treiber installiert und es programmiert. 

##Arduino Software installieren und konfigurieren
Lade als erstes die aktuelle Arduino Software  für Dein Betriebssystem herunter. Schließe nun das Arduino Uno mit dem beigefügten USB-Kabel an deinen Computer an. Bei aktuellen Betriebssystemen sollten die passenden Treiber automatisch installiert werden. 

Starte nun die Arduino Entwicklungsumgebung (kurz Arduino IDE). Sind die Treiber korrekt installiert worden, kannst du nun unter dem Reiter "Tools" -> "Board" das richtige Arduino Board auswählen. Bei der SenseBox arbeitest du mit dem "Arduino Uno". 

<image src="https://github.com/sensebox/OER/blob/master/senseBox_edu/images/Auswahlen_Arduino.png"/>

Als nächstes musst du einen seriellen Port auswählen, über den die Kommunikation zwischen Computer und Mikrokontroller läuft. Wähle dazu unter "Tools" -> "Serieller Port" den Anschluss aus, der von dem Treiber beim Anschließen des Arduino Uno geladen wurde.  
Sollten Probleme bei der Installation der Treiber auftauchen, z.B. weil das Arduino Uno von einem älteren Betriebssystem nicht erkannt wurde, kannst du hier Anleitungen für andere Betriebssysteme (z.B. Windows XP, Vista, 7) finden.

##Arduino IDE verwenden
Die Arduino IDE ist einfach aufgebaut. Im weißen Codefenster wird programmiert.

<image src="https://github.com/sensebox/OER/blob/master/senseBox_edu/images/Aufbau_Arduino_IDE.png"/>

Im schwarz hinterlegten Bereich werden Dir Status- und Fehlermeldungen angezeigt. Im oberen Bereich findest du die wichtigsten Bedienelemente, die im Folgenden noch kurz erklärt werden:
* Mit dem Häkchen kannst du Dein Arduino Programm (auch Sketch genannt) auf Fehler überprüfen lassen. Diesen Vorgang nennt  man auch Kompilieren. 
* Mit dem Pfeil nach rechts wird der Sketch auf den Arduino-Mikrokontroller hochgeladen.
* Mit dem Blatt, dem Pfeil nach oben und dem Pfeil nach unten kannst du einen neuen Sketch anlegen, einen bereits vorhandenen Sketch öffnen oder deinen aktuellen Sketch speichern.
* Mit der Lupe öffnest du den Seriellen Monitor. Die Funktion des Seriellen Monitors lernst du noch in Station 2 kennen.
