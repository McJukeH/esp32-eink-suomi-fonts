#pragma once

#include <WiFi.h>
#include <time.h>
#include <esp_sleep.h>

// ======================
// ASETUKSET
// ======================

// Vaihda nämä
static const char* WIFI_SSID     = "SoneraKotiGw";
static const char* WIFI_PASSWORD = "Tul1Pal0";

// Suomi
static const char* NTP_SERVER = "fi.pool.ntp.org";
static const long  GMT_OFFSET_SEC = 2 * 3600;   // UTC+2
static const int   DST_OFFSET_SEC = 3600;       // kesäaika

// ======================
// AIKASYNKKA
// ======================

static bool syncTimeNTP() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  unsigned long start = millis();
  while (WiFi.status() != WL_CONNECTED) {
    if (millis() - start > 15000) {
      return false; // timeout
    }
    delay(200);
  }

  configTime(GMT_OFFSET_SEC, DST_OFFSET_SEC, NTP_SERVER);

  struct tm timeinfo;
  bool ok = getLocalTime(&timeinfo, 10000);

  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);

  return ok;
}

// ======================
// DEEP SLEEP KLOON
// ======================

static void sleepUntilNextTime(int targetHour, int targetMinute = 0) {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    // Jos aika ei ole saatavilla → nuku 1h ja yritä uudelleen
    esp_sleep_enable_timer_wakeup(3600ULL * 1000000ULL);
    esp_deep_sleep_start();
  }

  int nowSec =
    timeinfo.tm_hour * 3600 +
    timeinfo.tm_min * 60 +
    timeinfo.tm_sec;

  int targetSec =
    targetHour * 3600 +
    targetMinute * 60;

  int sleepSec;
  if (nowSec < targetSec) {
    sleepSec = targetSec - nowSec;
  } else {
    sleepSec = 24 * 3600 - nowSec + targetSec;
  }

  esp_sleep_enable_timer_wakeup((uint64_t)sleepSec * 1000000ULL);
  esp_deep_sleep_start();
}
