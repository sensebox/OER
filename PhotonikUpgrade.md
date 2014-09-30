#Photonik Upgrade
Um eure SenseBox als Photonik Messstation nutzen zu können benötigt ihr neben der SenseBox Basic folgende Hardware:
##Sensoren


|![Digital Light Sensor - Grove TSL2561](images/digitallight.jpg "Digital Light Sensor - Grove TSL2561")|![Grove UV Sensor - GUVA-S12D](images/uvsensor_resized.jpg "Grove UV Sensor - GUVA-S12D")|
|:--------:|:--------:|
|**Digital Light Sensor - Grove TSL2561**|**Grove UV Sensor - GUVA-S12D**|

##Aufbau
Auch hier ist der Aufbau, durch das einfache Stecksystem, kinderleicht. Nachdem ihr eure SenseBox Basic nach dieser Anleitung zusammengebaut habt, müsst ihr lediglich noch die neuen Sensoren anschließen.
Der Digital Light Sensor wird an einen der I2C-Ports angeschlossen. Welchen ihr genau benutzt ist egal, da es sich um einen Datenbus handelt, an dem Sensoren parallel angeschlossen werden können.
Der UV-Sensor wird an den analogen Port A3 angeschlossen. Falls ihr hier einen anderen Port verwendet, müsst ihr diese Änderung auch im Sketch der SenseBox durchführen.

Zusammengefasst noch einmal die Ports:
- Digital Light Sensor:    I2C
- UV-Sensor:               A3

##Programmierung

Um den Code auf eurer SenseBox aktualisieren zu benötigt ihr wieder die Arduino Software Version 1.0.5 von der offiziellen Homepage. Auch einige der Photonik Sensoren benötigen eigene Repositorys, die ihr HIER herunterladen könnt. Benötigt wird die Digital_Light_Sensor.zip. Die heruntergeladene Datei entpackt ihr und kopiert sie in das Arduino Installationsverzeichnis. Eine detailliertere Anleitung zum Einbinden von Repositorys findet ihr HIER.
Nachdem die Repositorys hinzugefügt sind, müsst ihr nur noch den angepassten Code für das Photonik Upgrade herunterladen und mit Hilfe der Arduino IDE auf eure SenseBox übertragen. Wenn ihr nicht mehr genau wisst wie man einen Sketch auf die Sensebox überträgt schaut HIER nach.

##Registrierung auf der OpenSenseMap





