#include <LOLIN_EPD.h>
#include <Adafruit_GFX.h>

#include "suomi20px_caps.h"
#include "suomi18px_with_caps.h"
#include "TimeManager.h"

// ---------------- EPD ----------------
#define EPD_CS   5
#define EPD_DC   17
#define EPD_RST  -16
#define EPD_BUSY -4

LOLIN_SSD1680 EPD(250, 122, EPD_DC, EPD_RST, EPD_CS, EPD_BUSY);

// =================================================
// PIIRTOAPU 18px
// =================================================
static void drawText18(Adafruit_GFX &d, int x, int y, const char *txt, uint16_t col)
{
  int cx = x;
  for (const char *p = txt; *p; ++p) {
    if (*p == ' ') {
      cx += S18_WIDTH - 5;
      continue;
    }
    if (*p == ':' || *p == '.' || *p == ',' || *p == ';') {
      Suomi18_drawChar(d, *p, cx, y, col);
      cx += S18_WIDTH - 5;
      continue;
    }
    Suomi18_drawChar(d, *p, cx, y, col);
    cx += S18_WIDTH;
  }
}

// =================================================
// SETUP
// =================================================
void setup() {
  Serial.begin(115200);

  // aika (jos ei toimi, jatkaa silti)
  syncTimeNTP();

  EPD.begin();
  EPD.clearBuffer();
  EPD.setRotation(0);

  char buf[32];
  struct tm t;
  if (getLocalTime(&t)) {
    snprintf(buf, sizeof(buf),
             "%02d.%02d.%04d %02d:%02d",
             t.tm_mday,
             t.tm_mon + 1,
             t.tm_year + 1900,
             t.tm_hour,
             t.tm_min);
  } else {
    strcpy(buf, "NO TIME");
  }

  // --- aika ---
  drawText18(EPD, 5, 4, buf, EPD_BLACK);

  // --- otsikko ---
  Suomi20_drawChar(EPD, 'A', 5, 22, EPD_RED);
  drawText18(EPD, 20, 22, "SCII TESTI", EPD_RED);

// --- testirivit ---
 drawText18(EPD, 5, 45, "abcdefghijklmnopqrstuvwxyz", EPD_BLACK);
//  drawText18(EPD, 5, 65, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", EPD_BLACK);
  drawText18(EPD, 5, 85, "0123456789", EPD_BLACK);
  drawText18(EPD, 5,105, "!?:.,;<>a&aa@a%$|", EPD_BLACK);
  drawText18(EPD, 5,125, "{ } ~", EPD_BLACK); // ä ö å

  EPD.display();
}

void loop() {
  // ei mitään
}
