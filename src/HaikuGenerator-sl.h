#pragma once

#include <Arduino.h>
#include <Adafruit_GFX.h>

// =================================================
// UTF-8 → fontin ASCII-mäppäys
// ä → {   ö → }   å → ~
// =================================================
/*static void normalizeScandics(char *dst, const char *src) {
  while (*src) {
    if ((uint8_t)*src == 0xC3) {
      src++;
      if ((uint8_t)*src == 0xA4) *dst++ = '{';      // ä
      else if ((uint8_t)*src == 0xB6) *dst++ = '}'; // ö
      else if ((uint8_t)*src == 0xA5) *dst++ = '~'; // å
      src++;
    } else {
      *dst++ = *src++;
    }
  }
  *dst = 0;
}
*/

static void normalizeScandics(char *dst, const char *src) {
  while (*src) {
    if ((uint8_t)*src == 0xC3) {
      src++;
      uint8_t c = (uint8_t)*src;

      // pienet
      if (c == 0xA4) *dst++ = '{';   // ä
      else if (c == 0xB6) *dst++ = '}'; // ö
      else if (c == 0xA5) *dst++ = '~'; // å

      // ISOT
      else if (c == 0x84) *dst++ = '['; // Ä
      else if (c == 0x96) *dst++ = ']'; // Ö
      else if (c == 0x85) *dst++ = '^'; // Å

      src++;
    } else {
      *dst++ = *src++;
    }
  }
  *dst = 0;
}


// =================================================
// SANALISTAT
// =================================================

// --- otsikot (20px CAPS) ---
static const char *TITLES[] = {
  "HILJAINEN HETKI",
  "TALVINEN AAMU",
  "VALON POLKU",
  "MEREN MUOTO",
  "YÖN HENKI",
  "RAKKAUDEN KAIPUU",
  "INTOHIMON PALUU",
  "KEVÄÄN TUOKSU",
  "TALVEN LOPPU"
};

// --- rivi 1 (5 tavua, tunnelma) ---
static const char *LINE1[] = {
  "yö hengittää",
  "hiljainen jää",
  "meri odottaa",
  "valo viipyy",
  "tuuli seisoo",
  "rakkaus syttyy",
  "kevään henkäys",
  "valo yllättää"
};

// --- rivi 2 (7 tavua, liike/kuva) ---
static const char *LINE2[] = {
  "lumi sulaa hiljaa",
  "varjot liikkuvat",
  "jää ja vesi kohtaavat",
  "kaukaisuus kutsuu",
  "askel katoaa",
  "rakkaus herää",
  "elämä alkaa uudelleen",
  "romantiikkaa ilmassa"
};

// --- rivi 3 (5tavua, päätös) ---
static const char *LINE3[] = {
  "valo ei katoa",
  "aamu syntyy",
  "hetki katoaa",
  "hiljaisuus henkäilee",
  "meri hengittää",
  "metsä elää",
  "huuma nousee",
  "elämä saa ilon"
};

// =================================================
// APUT
// =================================================
template <typename T>
static const char *pick(const T &arr, int count) {
  return arr[random(count)];
}

// =================================================
// TEKSTINPIIRTO (18px)
// =================================================
/* static void drawText18(Adafruit_GFX &d,
                       int x,
                       int y,
                       const char *txt,
                       uint16_t col)
{
  int cx = x;
  int cy = y;

  for (const char *p = txt; *p; ++p) {
    if (*p == '\n') {
      cx = x;
      cy += 22;
      continue;
    }
    Suomi18_drawChar(d, *p, cx, cy, col);
    cx += S18_WIDTH;
  }
}
*/

// =================================================
// TEKSTINPIIRTO (18px)
// =================================================
/*static void drawText18(Adafruit_GFX &d,
                       int x,
                       int y,
                       const char *txt,
                       uint16_t col)
{
  int cx = x;

  for (const char *p = txt; *p; ++p) {
    if (*p == ' ') {
      cx += S18_WIDTH - 5;
      continue;
    }
    Suomi18_drawChar(d, *p, cx, y, col);
    cx += S18_WIDTH;
  }
}
*/

static void drawText18(Adafruit_GFX &d,
                       int x,
                       int y,
                       const char *txt,
                       uint16_t col)
{
  int cx = x;

  for (const char *p = txt; *p; ++p) {

    // välilyönti
    if (*p == ' ') {
      cx += S18_WIDTH - 8;   // oli -5 → pienempi väli
      continue;
    }

    // kapeat merkit
    if (*p == ':' || *p == '.' || *p == ',' || *p == ';') {
      Suomi18_drawChar(d, *p, cx, y, col);
      cx += S18_WIDTH - 10;  // paljon kapeampi
      continue;
    }

    // normaali merkki
    Suomi18_drawChar(d, *p, cx, y, col);
    cx += S18_WIDTH;
  }
}


// =================================================
// TEKSTINPIIRTO (20px CAPS)
// =================================================
/* static void drawText20(Adafruit_GFX &d,
                       int x,
                       int y,
                       const char *txt,
                       uint16_t col)
{
  int cx = x;
  for (const char *p = txt; *p; ++p) {
    Suomi20_drawChar(d, *p, cx, y, col);
    cx += S20_WIDTH;
  }
}


static void drawText20(Adafruit_GFX &d,
                       int x,
                       int y,
                       const char *txt,
                       uint16_t col)
{
  int cx = x;

  for (const char *p = txt; *p; ++p) {

    if (*p == ' ') {
      cx += S20_WIDTH - 6;   // kapeampi väli otsikolle
      continue;
    }

    if (*p == ':' || *p == '.' || *p == ',') {
      Suomi20_drawChar(d, *p, cx, y, col);
      cx += S20_WIDTH - 6;   // myös nämä kapeampina
      continue;
    }

    Suomi20_drawChar(d, *p, cx, y, col);
    cx += S20_WIDTH;
  }
}
*/

static void drawText20(Adafruit_GFX &d,
                       int x,
                       int y,
                       const char *txt,
                       uint16_t col)
{
  int cx = x;

  for (const char *p = txt; *p; ++p) {

    if (*p == ' ') {
      cx += S20_WIDTH - 6;   // kapeampi väli otsikolle
      continue;
    }

    if (*p == ':' || *p == '.' || *p == ',') {
      Suomi20_drawChar(d, *p, cx, y, col);
      cx += S20_WIDTH - 8;   // myös nämä kapeampina
      continue;
    }

    Suomi20_drawChar(d, *p, cx, y, col);
    cx += S20_WIDTH;
  }
}



// =================================================
// PÄIVÄMÄÄRÄ + AIKA TEKSTIKSI
// =================================================
static void formatDateTime(char *buf, size_t len)
{
  struct tm t;
  if (!getLocalTime(&t)) {
    snprintf(buf, len, "Haiku:");
    return;
  }

  snprintf(buf, len,
           "Haiku: %02d.%02d.%04d %02d:%02d",
           t.tm_mday,
           t.tm_mon + 1,
           t.tm_year + 1900,
           t.tm_hour,
           t.tm_min);
}

// =================================================
// SATUNNAISEN HAIKUN PIIRTO
// =================================================
static void drawRandomHaiku(Adafruit_GFX &d)
{
  char buf[64];

  // --- YLÄRIVI: Päivän haiku + aika ---
  formatDateTime(buf, sizeof(buf));
  drawText18(d, 6, 4, buf, EPD_BLACK);

  // --- OTSIKKO ---
  normalizeScandics(buf,
    pick(TITLES, sizeof(TITLES) / sizeof(TITLES[0])));
  drawText20(d, 10, 24, buf, EPD_RED);

  // --- rivi 1 ---
  normalizeScandics(buf,
    pick(LINE1, sizeof(LINE1) / sizeof(LINE1[0])));
  drawText18(d, 10, 52, buf, EPD_BLACK);

  // --- rivi 2 ---
  normalizeScandics(buf,
    pick(LINE2, sizeof(LINE2) / sizeof(LINE2[0])));
  drawText18(d, 10, 73, buf, EPD_BLACK);

  // --- rivi 3 ---
  normalizeScandics(buf,
    pick(LINE3, sizeof(LINE3) / sizeof(LINE3[0])));
  drawText18(d, 10, 94, buf, EPD_BLACK);
}

