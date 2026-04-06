# Changelog

Alle bemerkenswerten Änderungen an diesem Projekt werden in dieser Datei dokumentiert.

Das Format basiert auf [Keep a Changelog](https://keepachangelog.com/de/1.0.0/), 
und dieses Projekt hält sich an [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [1.1.0] - 2026-04-06

### Added
- **Pro English UI:** Komplett englische Benutzeroberfläche für einen professionelleren Look.
- **Barber-Pole Progress Bar:** Animierter Ladebalken am unteren Displayrand für direktes optisches Feedback.
- **Noise-Gate:** Rauschen um den Nullpunkt (-1 mA bis 2 mA) wird im Standby gnadenlos auf 0 gesetzt.
- **Li-Ion Lookup-Table:** Smarte, nicht-lineare Berechnung der Batterieprozente anhand echter Spannungskurven (3.0V - 4.15V).

### Changed
- **Pure Plug & Play:** Fehleranfällige Profil-Auswahl entfernt. Der Code fokussiert sich jetzt 100% auf Live-Messung und Coulomb Counting, unabhängig vom angeschlossenen Akku-Typ.
- **Highspeed Refresh:** Die Loop-Ausführung für Display und Sensor wurde von 4 FPS auf 10 FPS (100ms) hochgezogen, um die Animation flüssig zu halten.

### Fixed
- **Heavy-Duty Smoothing:** Der Software-Stossdämpfer wurde von 80/20 auf 95/5 angezogen. Strom (mA) und Leistung (mW) tanzen nicht mehr wild herum, sondern gleiten sauber.
- **Prozent-Alignment-Bug:** Dynamische X-Koordinate für die Prozentanzeige hinzugefügt. Das `%`-Zeichen stürzt bei 100% (4 Zeichen Breite) nicht mehr auf die nächste Zeile ab.
- **UI Alignment:** Seite 2 (Charged Cap.) wurde komplett linksbündig ausgerichtet, um den unruhigen zentrierten Look zu beheben.

## [1.0.0] - 2026-03-29

### Added
- **Nintendoc OS Core:** Vollständige Basis-Logik für den ATmega328P @ 16 MHz.
- **Display-Engine:** Ansteuerung des 0.96" SSD1306 OLED-Displays über I2C.
- **Sensor-Integration:** Präzises Auslesen des Adafruit INA219 (Spannung, Strom, Leistung).
- **Custom Boot-Sequence:** Startbildschirm mit Nintendoc-Logo (2 Sekunden) und Text-Splash (3 Sekunden).
- **Live-Dashboard:** Anzeige der geglätteten Akku-Spannung und dynamischer Prozentanzeige.
- **OLED Paging System:** Rotierendes Diagnose-Menü (alle 5 Sekunden) für mehr Übersichtlichkeit ohne I2C-Blockade.
- **Coulomb Counter:** Echtzeit-Kapazitätszähler zur Messung der eingeladenen Milliamperestunden (mAh).
- **Smart Status-Erkennung:** Automatische Statusanzeige ("Laden...", "Akku Voll", "Standby", "Entladen") basierend auf CC/CV-Ladekurve.

### Fixed
- **I2C/RAM Crash:** Einfrieren des Displays nach dem Logo behoben. Dynamische `String`-Variablen wurden durch RAM-schonende `const char*` Pointer und das `F()`-Makro ersetzt.
- **Timing & Rauschen:** Das Start-Rauschen und extreme Zeitlupen-Verhalten wurde durch das Brennen der richtigen 16-MHz-Fuses (Bootloader) eliminiert.
- **Upload-Fehler (0x4a != 0x4e):** Lock-Bit-Schreibschutzkonflikte während des USBasp-Uploads durch das Hinzufügen des `-e` (Erase) Flags in der `platformio.ini` gelöst.
- **Spannungs-Flackern:** Software-Stossdämpfer (Low-Pass Filter) integriert, um Millivolt-Schwankungen während des Ladevorgangs zu glätten.