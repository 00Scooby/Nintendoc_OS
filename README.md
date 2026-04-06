# 🎮 Nintendoc Battery Activation Tool & Charger v1.1

Das **Nintendoc Battery Activation Tool** ist ein massgeschneidertes Diagnose- und Aktivierungswerkzeug für Nintendo Switch Akkus (Joy-Con, Switch Lite, Switch V1/V2 & OLED). Es erlaubt das Auslesen von Spannungs- und Stromwerten in Echtzeit, hilft dabei, tiefentladene Akkus wieder "wachzuküssen", und fungiert als smarter Kapazitäts-Tester.

## ✨ Features
* **Multi-Connector Support:** Direkte Anschlüsse für Joy-Con, Switch Lite und Standard/OLED Batterien.
* **Pro English UI:** Cleanes, linksbündiges Interface mit dynamischem Text-Alignment (kein Zeilenumbruch mehr bei 100%).
* **Live-Monitoring:** 0.96" OLED-Display zur Anzeige von Spannung (V), Stromstärke (mA) und Leistung (mW) in Echtzeit.
* **Heavy-Duty Smoothing:** Integrierter 95/5 Software-Low-Pass-Filter für absolut tiefenentspannte, labornetzteilartige und flackerfreie Sensorwerte. Inklusive Noise-Gate für lautlose Standby-Werte.
* **Smarte Prozentkurve:** Keine ungenaue lineare Berechnung mehr! Die Prozentanzeige ist exakt an die nicht-lineare Entladekurve von Li-Ion Zellen (3.0V - 4.15V) angepasst.
* **Live Coulomb Counter (Charged Cap.):** Zählt präzise die eingeladenen Milliamperestunden (mAh) mit. Perfekt, um die echte Restkapazität und Gesundheit alter Akkus zu testen!
* **Barber-Pole Ladebalken:** Fliessend animierter, progressiver Ladebalken am unteren Bildschirmrand für sofortiges visuelles Feedback (10 FPS Refresh-Rate).
* **OLED Paging System:** Die unteren Diagnosewerte rotieren alle 5 Sekunden butterweich, um das kleine Display übersichtlich zu halten, ohne den I2C-Bus zu blockieren.
* **Custom Boot-Sequence:** Startet mit einem Nintendoc-Logo und einem sauberen Splash-Screen.
* **RAM-optimiert:** Verwendet Pointers (`const char*`) und das `F()`-Makro, um den knappen SRAM (2 KB) des ATmega328P zu schonen und I2C-Crashes zu verhindern.
* **USB-C Powered:** Einfache Stromversorgung über ein Standard-USB-C Kabel.

## 🛠 Hardware & Specs
* **MCU:** ATmega328P-AU (läuft auf 16 MHz via externem Quarz)
* **Sensor:** Adafruit INA219 (High-Side DC Current Sensor, I2C)
* **Display:** 0.96" SSD1306 OLED (I2C, 128x64 Pixel, Blau auf Schwarz)
* **Power:** Integrierter Laderegler für sicheres Handling und CC/CV-Ladung.

## 🚀 Installation & Flash-Anleitung

Dieses Projekt wurde mit **VS Code** und **PlatformIO** entwickelt.

### 1. Software vorbereiten
1. VS Code installieren.
2. Das **PlatformIO IDE** Plugin hinzufügen.
3. Repository klonen oder herunterladen.

### 2. Hardware flashen (WICHTIG!)
Verbinde deinen **USBasp Programmer** mit dem 6-Pin ICSP Header (`J1`) auf dem Board:
* **VCC -> VCC** (Wichtig: VCC weglassen, falls das Board bereits über USB-C mit Strom versorgt wird!)
* **GND -> GND**
* **MOSI, MISO, SCK, RESET** entsprechend markiert.

**Schritt A: 16 MHz Fuses setzen**
Da das Board über ISP (USBasp) programmiert wird und keinen eigenen USB-to-Serial-Wandler besitzt, muss der Chip zuerst auf den externen 16-MHz-Quarz konfiguriert werden. Führe dazu in PlatformIO einmalig den Task `Burn Bootloader` aus.

**Schritt B: Code Upload**
Damit `avrdude` beim anschliessenden Code-Upload nicht an den durch den Bootloader gesetzten Lock-Bits scheitert, muss in der `platformio.ini` zwingend das Erase-Flag (`-e`) gesetzt sein:

```ini
[env:uno]
platform = atmelavr
board = uno
framework = arduino
upload_protocol = usbasp
upload_flags = -e
lib_deps = 
    adafruit/Adafruit SSD1306 @ ^2.5.9
    adafruit/Adafruit GFX Library @ ^1.11.9
    adafruit/Adafruit INA219 @ ^1.2.3
```