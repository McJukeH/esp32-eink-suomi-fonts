#pragma once
#include <Adafruit_GFX.h>

// =======================
// SUOMI20 CAPS – POHJA + KAIKKI KIRJAIMET
// =======================

#ifndef S20_BASELINE
#define S20_BASELINE     14
#endif

#ifndef S20_CAPTOP
#define S20_CAPTOP       2
#endif

#ifndef S20_CAP_HEIGHT
#define S20_CAP_HEIGHT   12
#endif

#ifndef S20_WIDTH
#define S20_WIDTH        14
#endif

static inline void S20_H(Adafruit_GFX &d, int x, int y, int w, uint16_t c) {
  d.drawFastHLine(x, y, w, c);
}
static inline void S20_V(Adafruit_GFX &d, int x, int y, int h, uint16_t c) {
  d.drawFastVLine(x, y, h, c);
}

static void Suomi20_drawUpper(Adafruit_GFX &d, char c, int x0, int y0, uint16_t col)
{
  int yt = y0 + S20_CAPTOP;
  int yb = y0 + S20_BASELINE;

  switch (c) {
    case 'A':
      S20_V(d, x0+4, yt, S20_CAP_HEIGHT, col);
      S20_V(d, x0+9, yt, S20_CAP_HEIGHT, col);
      S20_H(d, x0+4, yt, 6, col);
      S20_H(d, x0+4, yt+6, 6, col);
    break;

    case 'B':
      S20_V(d, x0+4, yt, S20_CAP_HEIGHT, col);
      S20_H(d, x0+4, yt, 5, col);
      S20_H(d, x0+4, yt+6, 5, col);
      S20_H(d, x0+4, yb, 5, col);
      S20_V(d, x0+9, yt+1, 5, col);
      S20_V(d, x0+9, yt+7, 5, col);
    break;

    case 'C':
      S20_H(d, x0+5, yt, 5, col);
      S20_H(d, x0+5, yb, 5, col);
      S20_V(d, x0+4, yt+1, S20_CAP_HEIGHT-1, col);
    break;

    case 'D':
      S20_V(d, x0+4, yt, S20_CAP_HEIGHT, col);
      S20_H(d, x0+4, yt, 4, col);
      S20_H(d, x0+4, yb, 4, col);
      S20_V(d, x0+9, yt+1, S20_CAP_HEIGHT-1, col);
    break;

    case 'E':
      S20_V(d, x0+4, yt, S20_CAP_HEIGHT, col);
      S20_H(d, x0+4, yt, 6, col);
      S20_H(d, x0+4, yt+6, 5, col);
      S20_H(d, x0+4, yb, 6, col);
    break;

    case 'F':
      S20_V(d, x0+4, yt, S20_CAP_HEIGHT, col);
      S20_H(d, x0+4, yt, 6, col);
      S20_H(d, x0+4, yt+6, 5, col);
    break;

    case 'G':
      S20_H(d, x0+5, yt, 5, col);
      S20_H(d, x0+5, yb, 5, col);
      S20_V(d, x0+4, yt+1, S20_CAP_HEIGHT-1, col);
      S20_V(d, x0+10, yt+5, 6, col);
      S20_H(d, x0+7, yt+6, 3, col);
    break;

    case 'H':
      S20_V(d, x0+4, yt, S20_CAP_HEIGHT, col);
      S20_V(d, x0+9, yt, S20_CAP_HEIGHT, col);
      S20_H(d, x0+4, yt+6, 6, col);
    break;

    case 'I':
      S20_H(d, x0+4, yt, 6, col);
      S20_V(d, x0+7, yt, S20_CAP_HEIGHT, col);
      S20_H(d, x0+4, yb, 6, col);
    break;

    case 'J':
      S20_H(d, x0+4, yt, 6, col);
      S20_V(d, x0+7, yt, S20_CAP_HEIGHT, col);
      S20_H(d, x0+5, yb, 3, col);
    break;

    case 'K':
      S20_V(d, x0+4, yt, S20_CAP_HEIGHT, col);
      d.drawLine(x0+9, yt, x0+4, yt+6, col);
      d.drawLine(x0+4, yt+6, x0+9, yb, col);
    break;

    case 'L':
      S20_V(d, x0+4, yt, S20_CAP_HEIGHT, col);
      S20_H(d, x0+4, yb, 6, col);
    break;

    case 'M':
      S20_V(d, x0+3, yt, S20_CAP_HEIGHT, col);
      S20_V(d, x0+10, yt, S20_CAP_HEIGHT, col);
      d.drawLine(x0+3, yt, x0+7, yt+6, col);
      d.drawLine(x0+10, yt, x0+7, yt+6, col);
    break;

    case 'N':
      S20_V(d, x0+4, yt, S20_CAP_HEIGHT, col);
      S20_V(d, x0+9, yt, S20_CAP_HEIGHT, col);
      d.drawLine(x0+4, yt, x0+9, yb, col);
    break;

    case 'O':
      S20_H(d, x0+5, yt, 5, col);
      S20_H(d, x0+5, yb, 5, col);
      S20_V(d, x0+4, yt+1, S20_CAP_HEIGHT-1, col);
      S20_V(d, x0+10, yt+1, S20_CAP_HEIGHT-1, col);
    break;

    case 'P':
      S20_V(d, x0+4, yt, S20_CAP_HEIGHT, col);
      S20_H(d, x0+4, yt, 5, col);
      S20_H(d, x0+4, yt+5, 5, col);
      S20_V(d, x0+9, yt+1, 4, col);
    break;

    case 'Q':
      Suomi20_drawUpper(d, 'O', x0, y0, col);
      d.drawLine(x0+7, yb-2, x0+11, yb+2, col);
    break;

    case 'R':
      Suomi20_drawUpper(d, 'P', x0, y0, col);
      d.drawLine(x0+6, yt+6, x0+10, yb, col);
    break;

    case 'S':
      S20_H(d, x0+5, yt, 5, col);
      S20_H(d, x0+5, yt+6, 5, col);
      S20_H(d, x0+5, yb, 5, col);
      S20_V(d, x0+4, yt+1, 4, col);
      S20_V(d, x0+10, yt+7, 4, col);
    break;

    case 'T':
      S20_H(d, x0+4, yt, 6, col);
      S20_V(d, x0+7, yt, S20_CAP_HEIGHT, col);
    break;

    case 'U':
      S20_V(d, x0+4, yt, S20_CAP_HEIGHT-1, col);
      S20_V(d, x0+9, yt, S20_CAP_HEIGHT-1, col);
      S20_H(d, x0+5, yb, 5, col);
    break;

    case 'V':
      d.drawLine(x0+4, yt, x0+7, yb, col);
      d.drawLine(x0+10, yt, x0+7, yb, col);
    break;

    case 'W':
      d.drawLine(x0+3, yt, x0+6, yb, col);
      d.drawLine(x0+6, yb, x0+8, yt+6, col);
      d.drawLine(x0+8, yt+6, x0+10, yb, col);
      d.drawLine(x0+10, yb, x0+13, yt, col);
    break;

    case 'X':
      d.drawLine(x0+4, yt, x0+10, yb, col);
      d.drawLine(x0+10, yt, x0+4, yb, col);
    break;

    case 'Y':
      d.drawLine(x0+4, yt, x0+7, yt+6, col);
      d.drawLine(x0+10, yt, x0+7, yt+6, col);
      S20_V(d, x0+7, yt+6, 6, col);
    break;

    case 'Z':
      S20_H(d, x0+4, yt, 6, col);
      d.drawLine(x0+10, yt, x0+4, yb, col);
      S20_H(d, x0+4, yb, 6, col);
    break;

    // Skandit
    case '[': // Ä
      Suomi20_drawUpper(d, 'A', x0, y0, col);
      d.drawPixel(x0+5, yt-2, col);
      d.drawPixel(x0+8, yt-2, col);
    break;

    case ']': // Ö
      Suomi20_drawUpper(d, 'O', x0, y0, col);
      d.drawPixel(x0+5, yt-2, col);
      d.drawPixel(x0+8, yt-2, col);
    break;

    case '^': // Å
      Suomi20_drawUpper(d, 'A', x0, y0, col);
      d.drawPixel(x0+6, yt-2, col);
    break;
  }
}

// Julkinen rajapinta
static void Suomi20_drawChar(Adafruit_GFX &d, char c, int x, int y, uint16_t col)
{
  if ((c >= 'A' && c <= 'Z') || c=='[' || c==']' || c=='^') {
    Suomi20_drawUpper(d, c, x, y, col);
  }
}

