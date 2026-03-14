​📝 TODO für Version 0.2 & Optimierung
​1. Hardware-Korrekturen (EasyEDA)
​R5 (Shunt-Widerstand): Fest auf Part-Nummer C2903476 (Bauform 2512) umstellen, damit der Footprint im DFM-Check sofort passt.
​BOM-Optimierung: Alle passiven Bauteile (Widerstände/Kondensatoren) prüfen und nach Möglichkeit auf Basic Parts umstellen, um die $3 Gebühr pro Typ zu sparen.
​OLED-Positionierung: Evaluation der aktuellen Position. Eventuell Verschiebung nach oben/unten oder Zentrierung für eine bessere Optik in einem 3D-Druck-Gehäuse.
​Beschriftung: "Nintendoc" Logo oder Versionierung direkt in den Kupfer- oder Silkscreen-Layer der Platine integrieren.
​2. Software-Weiterentwicklung
​Batterie-Logik: Schwellenwerte für die Spannung definieren (z.B. wann gilt ein Akku als "leer" oder "tiefentladen").
​UI-Verschönerung: Anzeige kleiner Symbole (z.B. ein Blitz beim Laden oder ein Batterie-Icon).
​Kalibrierung: Vergleich der INA219-Werte mit einem Multimeter, um den Stromwert im Code gegebenenfalls feinjustieren.
​3. Bekannte Korrekturen (Erster Batch)
​R5 manuell prüfen: Falls die Fabrik ihn trotz Aufpreis weggelassen hat, einen 2512 100mΩ Widerstand nachlöten.
​Pin-Belegung USBasp: Dokumentation der 6 Verbindungen vom Flasher zum Board (erstellen wir, sobald die Hardware da ist).