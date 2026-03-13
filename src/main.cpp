#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_INA219.h>

// Display-Einstellungen
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Sensor-Objekt
Adafruit_INA219 ina219;

// DEIN LOGO DATA
const unsigned char nintendoc_logo [] PROGMEM = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // ... (hier den Rest deiner Hex-Zahlen einfügen) ...
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

void setup() {
  Serial.begin(9600);
  
  // 1. Display starten
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    for(;;); 
  }

  // 2. Sensor starten
  if (!ina219.begin()) {
    Serial.println("INA219 nicht gefunden");
  }

  // BOOT-SCREEN: Dein Logo anzeigen
  display.clearDisplay();
  display.drawBitmap(0, 0, nintendoc_logo, 128, 64, SSD1306_WHITE);
  display.display();
  
  delay(3000); // 3 Sekunden dein Logo geniessen
}

void loop() {
  // Daten vom Sensor lesen
  float busvoltage = ina219.getBusVoltage_V();
  float current_mA = ina219.getCurrent_mA();

  // Display aktualisieren
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  
  // Header
  display.setCursor(0, 0);
  display.println(F("Nintendoc Battery Monitor"));
  display.drawFastHLine(0, 10, 128, SSD1306_WHITE);

  // Spannung (V)
  display.setTextSize(2);
  display.setCursor(0, 20);
  display.print(busvoltage);
  display.println(F(" V"));

  // Stromstärke (mA)
  display.setCursor(0, 45);
  display.print(current_mA);
  display.setTextSize(1);
  display.println(F(" mA"));

  display.display();
  delay(500); // Alle halbe Sekunde aktualisieren
}