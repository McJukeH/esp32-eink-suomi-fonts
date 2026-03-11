#include <LOLIN_EPD.h>
#include <Adafruit_GFX.h>

#include "suomi20px_caps.h"
#include "suomi18px_with_caps.h"
#include "HaikuGenerator-sl.h"
#include "TimeManager.h"

// ---------------- EPD ----------------
#define EPD_CS   5
#define EPD_DC   17
#define EPD_RST  -16
#define EPD_BUSY -4

LOLIN_SSD1680 EPD(250, 122, EPD_DC, EPD_RST, EPD_CS, EPD_BUSY);

// ---------------- SETUP ----------------
void setup() {
  Serial.begin(115200);

  // 1️⃣ Synkkaa aika
  if (!syncTimeNTP()) {
    // Jos WiFi / NTP epäonnistuu → nuku tunti
    esp_sleep_enable_timer_wakeup(3600ULL * 1000000ULL);
    esp_deep_sleep_start();
  }

  // 2️⃣ Piirrä haiku
  EPD.begin();
  EPD.clearBuffer();
  EPD.setRotation(0);

  drawRandomHaiku(EPD);   // otsikko punaisella hoidetaan sisällä
  EPD.display();

  delay(26500); // anna EPD:lle hetki

  // 3️⃣ Nuku seuraavaan aamuun (07:00)
  sleepUntilNextTime(7, 0);
}

void loop() {
  // ei koskaan päästä tänne
}
