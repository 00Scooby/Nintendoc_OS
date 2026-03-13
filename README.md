# 🎮 Nintendoc Battery Activation Tool v0.1

Das **Nintendoc Battery Activation Tool** ist ein massgeschneidertes Diagnose- und Aktivierungswerkzeug für Nintendo Switch Akkus (Joy-Con, Switch Lite, Switch V1/V2 & OLED). Es erlaubt das Auslesen von Spannungs- und Stromwerten in Echtzeit und hilft dabei, tiefentladene Akkus wieder "wachzuküssen".

## ✨ Features
* **Multi-Connector Support:** Direkte Anschlüsse für Joy-Con, Switch Lite und Standard/OLED Batterien.
* **Live-Monitoring:** 0.96" OLED-Display zur Anzeige von Spannung (V) und Stromstärke (mA).
* **High Precision:** Nutzt den INA219 Sensor für exakte Messungen über den I2C-Bus.
* **USB-C Powered:** Einfache Stromversorgung über ein Standard-USB-C Kabel.
* **Custom Design:** Kompakter Formfaktor mit stylischem Nintendoc-Branding.

## 🛠 Hardware & Specs
* **MCU:** ATmega328P-AU (Arduino Uno Architektur)
* **Sensor:** Adafruit INA219 (High-Side DC Current Sensor)
* **Display:** 0.96" SSD1306 OLED (I2C, 128x64 Pixel, Blau auf Schwarz)
* **Power:** Integrierter Laderegler für sicheres Handling.

## 🚀 Installation & Flash-Anleitung

Dieses Projekt wurde mit **VS Code** und **PlatformIO** entwickelt.

### 1. Software vorbereiten
1. VS Code installieren.
2. Das **PlatformIO IDE** Plugin hinzufügen.
3. Repository klonen oder herunterladen.

### 2. Hardware flashen
Verbinde deinen **USBasp Programmer** mit dem 6-Pin ICSP Header (`J1`) auf dem Board:
* **VCC -> VCC**
* **GND -> GND**
* **MOSI, MISO, SCK, RESET** entsprechend markiert.

Klicke in VS Code unten in der blauen Leiste auf den Pfeil (**Upload**). PlatformIO kümmert sich um die Treiber und den Flash-Vorgang.

## 📦 Teileliste (BOM)
Neben der bestückten Platine von JLCPCB werden folgende Komponenten benötigt:
* 0.96" OLED I2C Display (SSD1306)
* USBasp AVR Programmer (zum Flashen)
* Joy-Con / Switch Battery Connectors (AliExpress/Ersatzteile)
* Schiebeschalter (SS12D00G3)

## ⚖️ Disclaimer
Dieses Projekt ist ein Community-Modding-Tool und steht in keiner Verbindung zu Nintendo. Die Nutzung erfolgt auf eigene Gefahr. Achten Sie beim Umgang mit Li-Ion Akkus immer auf die nötige Vorsicht!

---
*Developed by Steven - 2026*
