# 📝 Nintendoc - Project TODOs

Hier werden alle geplanten Verbesserungen und Aufgaben für die kommenden Versionen festgehalten.

---

## 🛠 Hardware-Optimierungen (v0.2)
- [ ] **Display-Position korrigieren:** OLED-Header weiter nach rechts rücken. Aktuell ragt das Display über den linken Platinenrand hinaus.
- [ ] **R5 Fix:** Part-Nummer fest auf `C2903476` (Bauform 2512) setzen, damit Footprint und Bauteil im DFM sofort matchen.
- [ ] **BOM-Bereinigung:** Alle Widerstände und Kondensatoren auf "Basic Parts" prüfen, um die $3 Gebühr pro Typ einzusparen.
- [ ] **Beschriftung:** Version "v0.2" und die Pin-Belegung für den Programmier-Header direkt auf den Silkscreen (weisse Schrift) drucken.

## 💻 Software-Entwicklung
- [ ] **Batterie-Logik:** Spannungs-Schwellenwerte definieren (Wann ist der Akku leer/voll?).
- [ ] **UI-Verschönerung:** Batterie-Icons und Lade-Animationen für das OLED entwerfen.
- [ ] **Kalibrierung:** Messwerte des INA219 mit einem Multimeter abgleichen und ggf. im Code kalibrieren.

## 📦 Erster Batch (v0.1 Ankunft & Tests)
- [ ] **Mechanik-Check:** Passgenauigkeit der Joy-Con Stecker in den Bohrungen prüfen.
- [ ] **Bestückung:** R5 (falls leer), OLED-Header und Joy-Con Connectors auflöten.
- [ ] **First Boot:** Bootloader/Code via USBasp flashen und Kommunikation mit dem Sensor testen.

---
*Status: In Produktion (v0.1 bestellt am 14.03.2026)*
