#include <SPI.h>
#include <Ethernet.h>
#include <EthernetUdp.h>
#include <RV8523.h>
#include <Wire.h>

/*
 Zeitsynchronisation für das senseShield

 Synchronisiert eine RV8523 RTC (Real Time Clock) wie sie auf dem Senseshield verbaut ist anhand eines Ntp-Servers zu GMT+1 (ohne Sommerzeit)
 Für weitere Informationen zu NTP Servern und dem Aufbau des NTP siehe
 http://de.wikipedia.org/wiki/Network_Time_Protocol

 Dieser Code basiert auf dem Beispiel eines NTPClient in der Standart Ethernet-library. 
 Weitere informationen unter https://www.arduino.cc/en/Tutorial/UdpNtpClient
 
 erstellt am  4 Sep 2010
 by Michael Margolis
 modifiziert am 17 Sep 2010
 by Tom Igoe
 modifiziert am 2.9.2015
 by Arturo Guadalupi
 modifiziert am 06 Apr 2016
 by SpeckiJ

 */

// Instanz der UDP Klasse aus der Arduino Standart-Ethernet-Bibliothek
EthernetUDP udp;

// Eine feste MAC Adresse sowie IP werden vergeben.
// Der Aufbau der IP Adresse hängt von den lokalen Netzwerkeinstellungen ab.
byte mac[] = {
  0xDF, 0xAD, 0xBE, 0xEF, 0xFA, 0xED
};

byte ip[] = { 192, 168, 0, 15 };

// Initialisierung der Real Time Clock
RV8523 rtc;

// Deklaration interner Variablen
char string[ 17 ] = { "" };
unsigned int localPort = 8888;      // Lokaler Port für UDP-Pakete

// Adresse des Synchronisierungsservers
char timeServer[] = "de.pool.ntp.org";

const int NTP_PACKET_SIZE = 48; // NTP Informationen befinden sich in den ersten 48 bytes der Nachricht

byte packetBuffer[ NTP_PACKET_SIZE]; // Buffer für Ein-/Ausgehende Pakete

void setup()
{
  // Start des Seriellen Monitors
  Serial.begin(9600);

  // Start von Ethernet und UDP Verbindungen
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Keine Netzwerkkonfiguration über DHCP möglich! Versuche über statische IP zu verbinden.");
    Ethernet.begin(mac, ip);
    if (udp.begin(localPort) == 0) {
      Serial.println("Keine Netzwerkkonfiguration anhand der statischen IP möglich!");
      while (true); // Keine Netzwerkverbindung möglich, Arduino bricht das Programm ab.
    }
  } else {
    udp.begin(localPort);
  }

  // RTC schaltet bei Stromverlust auf die interne Batterie um
  rtc.batterySwitchOver(1);

  Serial.println("Initialisierung erfolgreich!");
}

void loop()
{
  sendNTPpacket(timeServer); // NTP Paket wird an den Server gesendet

  // Auf Antwort des Servers warten
  delay(1000);
  if ( udp.parsePacket() ) {
    Serial.println("Verbindung zum Server hergestellt - Synchronisation läuft");
    udp.read(packetBuffer, NTP_PACKET_SIZE); // Paket in den Buffer schreiben

    // Der Zeitstempel beginnt bei Byte 40 des empfangenen Pakets und ist 4 Bytes lang
    // Dies entspricht zwei "words". Diese werden zuerst extrahiert:

    unsigned long highWord = word(packetBuffer[40], packetBuffer[41]);
    unsigned long lowWord = word(packetBuffer[42], packetBuffer[43]);

    // Beide "words" werden zu einem long kombiniert
    // Dies ist die NTP Zeit (Sekunden die seit dem 1.1.1900 vergangen sind)
    unsigned long secsSince1900 = highWord << 16 | lowWord;

    // Umwandlung von NTP zu normaler Zeit:
    // Unix Zeit beginnt am 1.1.1970. (in Sekunden 2208988800)
    const unsigned long seventyYears = 2208988800UL;
    // Siebzig Jahre von NTP Zeit abziehen:
    unsigned long epoch = secsSince1900 - seventyYears;

    // Updaten der Real Time Clock:
    updateTime(epoch);

    Serial.println("Synchronisation erfolgreich! Nächste Synchronisation in 30 Sekunden.");
    Serial.println("");
    delay(30000);
  } else {
    Serial.println("Keine Verbindung zum Server. Erneuter Versuch in 10 Sekunden.");
    delay (10000);
  }
}

// Senden einer NTP Anfrage an den Zeitserver an der angegeben Adresse
unsigned long sendNTPpacket(char *address)
{
  // internen Buffer auf 0 setzen
  memset(packetBuffer, 0, NTP_PACKET_SIZE);
  
  // Variablen für das NTP Paket setzen
  // (Für nähere Informationen: Link siehe oben)
  packetBuffer[0] = 0b11100011;   // LI, Version, Modus
  packetBuffer[1] = 0;     // Stratum
  packetBuffer[2] = 6;     // Polling Interval
  packetBuffer[3] = 0xEC;  // Peer Clock Precision
  // 8 bytes of zero for Root Delay & Root Dispersion
  packetBuffer[12]  = 49;
  packetBuffer[13]  = 0x4E;
  packetBuffer[14]  = 49;
  packetBuffer[15]  = 52;

  // Senden des NTP Paketes an den Zeitserver auf Port 123
  udp.beginPacket(address, 123);
  udp.write(packetBuffer, NTP_PACKET_SIZE);
  udp.endPacket();
}

void updateTime(unsigned long epoch) {

  // Berechnung von Stunde/Minute/Sekunde basierend auf Unix Zeit
  int stunde_ntp = (epoch % 86400L) / 3600;
  int minute_ntp = (epoch % 3600) / 60;
  int sekunde_ntp = (epoch % 60);

  // Umrechnung von GMT zu GMT+1
  stunde_ntp += 1;

  // Berechnung von Tag/Monat/Jahr basierend auf Unix Zeit (Epoch)
  int tag_ntp;
  int monat_ntp;
  int jahr_ntp;
  
  calculateDMYfromUnix(&tag_ntp, &monat_ntp, &jahr_ntp, epoch);

  // Setzen der RTC
  rtc.set(sekunde_ntp, minute_ntp, stunde_ntp, tag_ntp, monat_ntp, jahr_ntp);

  // Auslesen der RTC - Ausgabe in den Seriellen Monitor
  int seconds_rtc, minute_rtc, hour_rtc, day_rtc, month_rtc, year_rtc;
  rtc.get(&seconds_rtc, &minute_rtc, &hour_rtc, &day_rtc, &month_rtc, &year_rtc);
  Serial.print("Aktuelle Zeit: ");
  Serial.print(year_rtc);
  Serial.print("/");
  Serial.print(month_rtc);
  Serial.print("/");
  Serial.print(day_rtc);
  Serial.print("  ");
  Serial.print(hour_rtc);
  Serial.print(":");
  Serial.print(minute_rtc);
  Serial.print(":");
  Serial.println(seconds_rtc);
}
void calculateDMYfromUnix(int *tag_ntp, int *monat_ntp, int *jahr_ntp, long epoch) {
  
  // Lokale Variablen Initialisieren
  static unsigned short const tage[4][12] =
  {
    {   0,  31,  60,  91, 121, 152, 182, 213, 244, 274, 305, 335},
    { 366, 397, 425, 456, 486, 517, 547, 578, 609, 639, 670, 700},
    { 731, 762, 790, 821, 851, 882, 912, 943, 974, 1004, 1035, 1065},
    {1096, 1127, 1155, 1186, 1216, 1247, 1277, 1308, 1339, 1369, 1400, 1430},
  };

  // Epoch in Tage Umrechnen:
  epoch /= 60; // Sek -> Min
  epoch /= 60; // Min -> Hour
  epoch /= 24; // Hour -> Day

  // 4-Jahres Zyklen die seit Epoch vollständig vergangen sind
  int jahreszyklen = epoch / (365 * 4 + 1) * 4;
  // Abziehen der vollständigen Zyklen von Epoch
  epoch %= 365 * 4 + 1;

  // Aktelles Jahr berechnen (Position des Jahres innerhalb des letzten noch nicht vollständigen Zyklus)
  int jahr;
  for (jahr = 3; jahr > 0; jahr--)
  {
    if (epoch >= tage[jahr][0]) // Wenn Tage größer sind als Tage bis zum Anfang des Jahres --> Datum nach dem 1.1. des Jahres
      break;
  }

  // Aktueller Monat
  int monat;
  for (monat = 11; monat > 0; monat--)
  {
    if (epoch >= tage[jahr][monat]) // Wenn Tage größer sind als Tage bis zum Anfang des Monats --> Datum nach dem 1. des Monats
      break;
  }
  monat += 1; // Array Index geht von 0-11 --> Monate um eins verschoben

  *jahr_ntp  = jahreszyklen + jahr;
  *monat_ntp = monat;
  *tag_ntp   = epoch - tage[jahr][monat] + 1; // Verschiebung durch Array Index 
}
