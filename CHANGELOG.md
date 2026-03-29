# Changelog

Alle bemerkenswerten Änderungen an diesem Projekt werden in dieser Datei dokumentiert.

Das Format basiert auf [Keep a Changelog](https://keepachangelog.com/de/1.0.0/), 
und dieses Projekt hält sich an [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [1.0.0] - 2026-03-29

### Added
- **Nintendoc OS Core:** Vollständige Basis-Logik für den ATmega328P @ 16 MHz.
- **Display-Engine:** Ansteuerung des 0.96" SSD1306 OLED-Displays über I2C.
- **Sensor-Integration:** Präzises Auslesen des Adafruit INA219 (Spannung, Strom, Leistung).
- **Custom Boot-Sequence:** Startbildschirm mit Nintendoc-Logo (2 Sekunden) und Text-Splash (3 Sekunden).
- **Live-Dashboard:** Anzeige der geglätteten Akku-Spannung und dynamischer Prozentanzeige (angepasst auf 3.0V - 4.2V Li-Ion Range).
- **OLED Paging System:** Rotierendes Diagnose-Menü (alle 5 Sekunden) für mehr Übersichtlichkeit ohne I2C-Blockade.
- **Coulomb Counter:** Echtzeit-Kapazitätszähler zur Messung der eingeladenen Milliamperestunden (mAh).
- **Smart Status-Erkennung:** Automatische Statusanzeige ("Laden...", "Akku Voll", "Standby", "Entladen") basierend auf CC/CV-Ladekurve.

### Fixed
- **I2C/RAM Crash:** Einfrieren des Displays nach dem Logo behoben. Dynamische `String`-Variablen wurden durch RAM-schonende `const char*` Pointer und das `F()`-Makro ersetzt.
- **Timing & Rauschen:** Das Start-Rauschen und extreme Zeitlupen-Verhalten wurde durch das Brennen der richtigen 16-MHz-Fuses (Bootloader) eliminiert.
- **Upload-Fehler (0x4a != 0x4e):** Lock-Bit-Schreibschutzkonflikte während des USBasp-Uploads durch das Hinzufügen des `-e` (Erase) Flags in der `platformio.ini` gelöst.
- **Spannungs-Flackern:** Software-Stossdämpfer (Low-Pass Filter) integriert, um Millivolt-Schwankungen während des Ladevorgangs zu glätten.