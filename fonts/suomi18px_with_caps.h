#pragma once
#include <Adafruit_GFX.h>

// =======================
// YHTEISET VAKIOT (LUKITTU)
// =======================

#define S18_BASELINE 12
#define S18_CAPTOP   5
#define S18_WIDTH    12

// =======================
// APUFUNKTIOT
// =======================

static inline void S18_H(Adafruit_GFX &d, int x, int y, int w, uint16_t c) {
  d.drawFastHLine(x, y, w, c);
}

static inline void S18_V(Adafruit_GFX &d, int x, int y, int h, uint16_t c) {
  d.drawFastVLine(x, y, h, c);
}

// =======================
// PIENET KIRJAIMET a–z + { } ~
// =======================

static void Suomi18_drawLower(Adafruit_GFX &d, char c, int x0, int y0, uint16_t col)
{
  int yb = y0 + S18_BASELINE;

  switch (c) {

//================================
// NuMEROT JA ERIKOISMERKIT
//=================================

    case '0':
      S18_H(d, x0+5, yb-7, 3, col);
      S18_H(d, x0+5, yb,   3, col);
      S18_V(d, x0+4, yb-6, 6, col);
      S18_V(d, x0+8, yb-6, 6, col);
      break;

    case '1':
      S18_V(d, x0+6, yb-7, 7, col);
      break;

    case '2':
      S18_H(d, x0+4, yb-7, 4, col);
      S18_H(d, x0+5, yb-4, 3, col);
      S18_H(d, x0+5, yb,   3, col);
      S18_V(d, x0+8, yb-6, 2, col);
      S18_V(d, x0+4, yb-3, 3, col);
      break;

    case '3':
      S18_H(d, x0+5, yb-7, 3, col);
      S18_H(d, x0+5, yb-4, 3, col);
      S18_H(d, x0+5, yb,   3, col);
      S18_V(d, x0+8, yb-6, 6, col);
      break;

    case '4':
      S18_V(d, x0+4, yb-7, 4, col);
      S18_V(d, x0+8, yb-7, 7, col);
      S18_H(d, x0+4, yb-4, 5, col);
      break;

    case '5':
      S18_H(d, x0+5, yb-7, 3, col);
      S18_H(d, x0+5, yb-4, 3, col);
      S18_H(d, x0+5, yb,   3, col);
      S18_V(d, x0+4, yb-6, 2, col);
      S18_V(d, x0+8, yb-3, 3, col);
      break;

    case '6':
      S18_H(d, x0+5, yb-7, 3, col);
      S18_H(d, x0+5, yb-4, 3, col);
      S18_H(d, x0+5, yb,   3, col);
      S18_V(d, x0+4, yb-6, 6, col);
      S18_V(d, x0+8, yb-3, 3, col);
      break;

    case '7':
      S18_H(d, x0+5, yb-7, 3, col);
      d.drawLine(x0+8, yb-7, x0+5, yb, col);
      break;

    case '8':
      S18_H(d, x0+5, yb-7, 3, col);
      S18_H(d, x0+5, yb-4, 3, col);
      S18_H(d, x0+5, yb,   3, col);
      S18_V(d, x0+4, yb-6, 6, col);
      S18_V(d, x0+8, yb-6, 6, col);
      break;

    case '9':
      S18_H(d, x0+5, yb-7, 3, col);
      S18_H(d, x0+5, yb-4, 3, col);
      S18_H(d, x0+5, yb,   3, col);
      S18_V(d, x0+4, yb-6, 3, col);
      S18_V(d, x0+8, yb-6, 6, col);
      break;

//=================================
// VÄLIMERKIT
//=================================

    case ':':
      d.drawPixel(x0+1, yb-5, col);
      d.drawPixel(x0+1, yb-2, col);
      break;

    case '.':
      d.drawPixel(x0+1, yb, col);
      break;

    case ',':
      d.drawPixel(x0+1, yb, col);
      d.drawPixel(x0+0, yb+1, col);
      break;

    case ';':
      d.drawPixel(x0+1, yb-4, col);
      d.drawPixel(x0+1, yb, col);
      d.drawPixel(x0+0, yb+1, col);
      break;

    case '-':
      // keskiviiva
      S18_H(d, x0+4, yb-3, 5, col);
      break;

    case '+':
      // risti keskelle
      S18_H(d, x0+4, yb-3, 5, col);
      S18_V(d, x0+6, yb-6, 7, col);
      break;

    case '/':
      // vinoviiva oikea ylös -> vasen alas
      d.drawLine(x0+8, yb-7, x0+4, yb, col);
      break;

    case '(':
      // vasen kaari (kolmesta pysty+kulma pisteistä)
      d.drawPixel(x0+6, yb-7, col);
      S18_V(d, x0+5, yb-6, 5, col);
      d.drawPixel(x0+6, yb, col);
      break;

    case ')':
      d.drawPixel(x0+4, yb-7, col);
      S18_V(d, x0+5, yb-6, 5, col);
      d.drawPixel(x0+4, yb, col);
      break;

    case ' ':
      // välilyönti: ei piirretä mitään
      break;


// ================================
// ERIKOISMERKIT
// ================================

case '!':
  S18_V(d, x0+6, yb-7, 5, col);
  d.drawPixel(x0+6, yb, col);
  break;

case '?':
  S18_H(d, x0+5, yb-7, 3, col);
  S18_V(d, x0+8, yb-6, 2, col);
  S18_H(d, x0+7, yb-4, 2, col);
  d.drawPixel(x0+6, yb-2, col);
  d.drawPixel(x0+6, yb-3, col);
  d.drawPixel(x0+6, yb, col);
  break;

case '|':
  S18_V(d, x0+6, yb-11, 11, col);
  break;

case '<':
  d.drawLine(x0+8, yb-7, x0+4, yb-4, col);
  d.drawLine(x0+8, yb-1, x0+4, yb-4, col);
  break;

case '>':
  d.drawLine(x0+4, yb-7, x0+8, yb-4, col);
  d.drawLine(x0+4, yb-1, x0+8, yb-4, col);
  break;

case '$':
  S18_H(d, x0+5, yb-7, 3, col);
  S18_H(d, x0+5, yb-4, 3, col);
  S18_H(d, x0+5, yb,   3, col);
  S18_V(d, x0+4, yb-6, 2, col);
  S18_V(d, x0+8, yb-3, 3, col);
  S18_V(d, x0+6, yb-9, 11, col); // pystyviiva keskelle
  break;

case '%':
  d.drawPixel(x0+4, yb-7, col);
  d.drawPixel(x0+8, yb-1, col);
  d.drawLine(x0+8, yb-7, x0+4, yb, col);
  break;

  case '&':
  d.drawLine(x0+3, yb-6, x0+8, yb-1, col); // kenoviiva
  d.drawLine(x0+9,yb-4, x0+5, yb-0, col); //kauttaviiva
  S18_H(d, x0+2, yb-0, 3, col);
  S18_V(d, x0+1, yb-3, 3, col);
  S18_H(d, x0+2, yb-4, 2, col);
  S18_H(d, x0+5, yb-6, 1, col);
  S18_V(d, x0+6, yb-8, 2, col);
  S18_H(d, x0+4, yb-9, 2, col);
  S18_V(d, x0+3, yb-8, 2, col);
  S18_H(d, x0+7, yb-4, 2, col);
  S18_H(d, x0+9, yb-0, 2, col);
  break;



  case '@':
  // ulkokehys iso ympyrä
  S18_H(d, x0+4, yb-9, 5, col);
  S18_H(d, x0+2, yb-8, 2, col);
  S18_V(d, x0+2, yb-7, 1, col);
  S18_V(d, x0+1, yb-6, 5, col);
  S18_V(d, x0+2, yb-1, 1, col);
  S18_H(d, x0+3, yb,   6, col);
  S18_H(d, x0+9, yb-1, 1, col);
  S18_H(d, x0+9, yb-8, 1, col);
  S18_V(d, x0+10, yb-7, 3, col);
  S18_V(d, x0+9, yb-4, 2, col);
  S18_H(d, x0+8, yb-2, 1, col);

  // sisä-"a"

  S18_V(d, x0+7, yb-6, 5, col);
  S18_H(d, x0+5, yb-6, 2, col);
  S18_H(d, x0+4, yb-5, 1, col);
  S18_V(d, x0+3, yb-4, 2, col);
  S18_H(d, x0+4, yb-2, 3, col);

  // häntä oikealle alas
  // d.drawLine(x0+8, yb-2, x0+10, yb, col);
  break;

    // ---- pystyrungot ----

     case 'k':  // Nyt Lukittu
       // pysty runko
       S18_V(d, x0+5, yb-11, 11, col);
       // ylähaara
//       d.drawLine(x0+6, yb-7, x0+9, yb-10, col);
       d.drawLine(x0+6, yb-4, x0+9, yb-6, col);
       // ala-haara
//       d.drawLine(x0+6, yb-7, x0+9, yb-3, col);
       d.drawLine(x0+6, yb-3, x0+9, yb-1, col);
    break;

    case 'l':  // Lukittu
      S18_V(d, x0+6, yb-11, 11, col); 
      d.drawPixel(x0+7, yb, col);
    break;

    case 'i':  // Lukittu
      S18_V(d, x0+6, yb-7, 7, col);
      d.drawPixel(x0+6, yb-11, col); break;

    case 'j':   // LUKITSE
      S18_V(d, x0+6, yb-7, 9, col);
      d.drawPixel(x0+6, yb-11, col);
    break;

    case 't':  //Lukitse
      S18_V(d, x0+6, yb-11, 11, col);
      S18_H(d, x0+4, yb-8, 5, col); break;

    case 'f':  // LUKITTU
      S18_V(d, x0+6, yb-8, 8, col);
      S18_H(d, x0+7, yb-9, 3, col);
      S18_H(d, x0+5, yb-6, 4, col); break;

    // ---- perus x-height ----

    case 'n':  // LUKITTU
      S18_V(d, x0+4, yb-7, 7, col);
      S18_V(d, x0+8, yb-6, 6, col);
      S18_H(d, x0+4, yb-7, 4, col); break;

    case 'h': // LUKITTU
      S18_V(d, x0+4, yb-11, 11, col);
      S18_V(d, x0+8, yb-6, 6, col);
      S18_H(d, x0+4, yb-7, 4, col); break;

    case 'u':   // Lukittu
      S18_V(d, x0+4, yb-7, 7, col);
      S18_V(d, x0+8, yb-7, 8, col);
      S18_H(d, x0+5, yb, 3, col); break;

    case 'r': // LUKITTU
      S18_V(d, x0+5, yb-7, 7, col);
      S18_H(d, x0+6, yb-6, 1, col);
      S18_H(d, x0+7, yb-7, 2, col); 
      S18_H(d, x0+9, yb-6, 1, col); break;

    // ---- pyöreät ----

    case 'o':   // Lukitaan
      S18_H(d, x0+5, yb-7, 3, col);
      S18_H(d, x0+5, yb,   3, col);
      S18_V(d, x0+4, yb-6, 6, col);  // Vasen pyst
      S18_V(d, x0+8, yb-6, 6, col);  // oikea pysty
//     if (c=='e') S18_H(d, x0+5, yb-4, 3, col); 
      break;

    case 'c':  // Lukitaan
     S18_H(d, x0+5, yb-7, 3, col);
      S18_H(d, x0+5, yb,   3, col);
      S18_V(d, x0+4, yb-6, 6, col); // Oli 5, on vasen pysty
 //     S18_V(d, x0+8, yb-6, 6, col);  // Oli 5 oli oikea pysty
 //     if (c=='e') S18_H(d, x0+5, yb-4, 3, col); 
    break;

    case 'e':  // Lukitaan nyt.
      S18_H(d, x0+5, yb-7, 3, col);
      S18_H(d, x0+5, yb,   3, col);
      S18_V(d, x0+4, yb-6, 6, col); // On vasen pysty
      S18_V(d, x0+8, yb-6, 3, col);  // On oikea pysty
      if (c=='e') S18_H(d, x0+5, yb-4, 3, col); 
      break;

    case 'a': // LUKITSE
      S18_H(d, x0+5, yb-7, 3, col);
      S18_H(d, x0+5, yb-1, 3, col);
      S18_V(d, x0+4, yb-3, 2, col);
      S18_V(d, x0+8, yb-6, 6, col);
      S18_H(d, x0+5, yb-4, 3, col); 
      S18_H(d, x0+4, yb-6, 1, col);
    break;

    case 'b':   // LUKITSE 
      S18_V(d, x0+5, yb-11, 11, col);
      S18_H(d, x0+5, yb-7, 4, col);
      S18_H(d, x0+5, yb,   4, col);
      S18_V(d, x0+9, yb-6, 6, col);
    break;

    case 'd':   // LUKITSE 
      S18_V(d, x0+8, yb-11, 11, col);
      S18_H(d, x0+5, yb-7, 3, col);
      S18_H(d, x0+5, yb,   3, col);
      S18_V(d, x0+4, yb-6, 6, col);
    break;

    // ---- muut ----

    case 's':   // Lukitaan nyt
    // yläosa
     S18_H(d, x0+5, yb-7, 3, col); // 
     S18_V(d, x0+4, yb-6, 2, col); // 
     S18_H(d, x0+8, yb-6, 1, col);
     // keskikohta
     S18_H(d, x0+5, yb-4, 3, col);
     // alaosa
     S18_V(d, x0+8, yb-3, 2, col);
     S18_H(d, x0+5, yb-1, 3, col); 
     S18_H(d, x0+4, yb-2, 1, col);
    break;

   case 'v': //Lukitaan
     d.drawLine(x0+4, yb-7, x0+6, yb, col);
     d.drawLine(x0+8, yb-7, x0+6, yb, col);
    break;


    case 'w': // Lukitaan
      d.drawLine(x0+4, yb-7, x0+6, yb, col); // Vasen kenoviiva
      d.drawLine(x0+8, yb-7, x0+6, yb, col); //Vasen keski kauttaviiva
      d.drawLine(x0+8, yb-7, x0+10, yb, col); //Oikea keski kenoviiva
      d.drawLine(x0+12, yb-7,x0+10, yb, col);// Oikea Kauttaviiva

//      S18_V(d, x0+4, yb-7, 7, col);
//      S18_V(d, x0+8, yb-7, 7, col);
//      d.drawLine(x0+4, yb-7, x0+6, yb, col);   // Vasen kenoviiva ok
 //     d.drawLine(x0+6, yb-4, x0+8, yb-2, col); //
 //     d.drawLine(x0+6, yb-7, x0+4, yb, col);
  //    d.drawLine(x0+13, yb-7, x0+9, yb, col);
    break;

   case 'x':   // LUKITSE
     d.drawLine(x0+4, yb-7, x0+8, yb, col);
     d.drawLine(x0+8, yb-7, x0+4, yb, col);
   break;

   case 'z':   // LUKITSE 
    S18_H(d, x0+4, yb-7, 5, col);
    d.drawLine(x0+8, yb-7, x0+4, yb, col);
    S18_H(d, x0+4, yb,   5, col);
   break;

    case 'm':  // Lukittu
      S18_V(d, x0+3, yb-6, 6, col);
      S18_V(d, x0+6, yb-6, 6, col);
      S18_V(d, x0+9, yb-6, 6, col);
      S18_H(d, x0+3, yb-7, 3, col);
      S18_H(d, x0+7, yb-7, 2, col);
      break;

    case 'p': // Lukitse jos OK
      S18_V(d, x0+6, yb-7, 10, col);     // runko alas
      S18_H(d, x0+7, yb-7, 3, col);     // Ylä vaaka
      S18_V(d, x0+10, yb-6, 3, col);    // Oikea pysty
      S18_H(d, x0+7, yb-3, 3, col);     // Ala vaaka
    break;

    case 'q': // Lukitse
      S18_H(d, x0+5, yb-7, 3, col);
      S18_H(d, x0+5, yb,   3, col);
      S18_V(d, x0+4, yb-6, 6, col);
      S18_V(d, x0+8, yb-6, 10, col);     // häntä alas
    break;


    case 'y': // Lukitaan!
//      S18_V(d, x0+4, yb-7, 7, col);
//      S18_V(d, x0+8, yb-7, 10, col);
//        d.drawLine(x0+4,yb-7,x0+6,yb-4,col); // Vasen lyhyt kenoviiva
//        d.drawLine(x0+9,yb-7,x0+3,yb+3,col); //oikea pitkä kauttaviiva
//      d.drawLine(x0+5,yb+9,x0+3,yb+15,col);
     d.drawLine(x0+4, yb-7, x0+6, yb-2, col);
 //           d.drawLine(x0+9, yb-7, x0+3, yb+3, col);
     d.drawLine(x0+10,yb-7,x0+7,yb+3,col);
    break;

    case 'g': // Lukitse jos OK
      S18_H(d, x0+5, yb-7, 3, col);  //Ylä vaaaka
      S18_H(d, x0+5, yb,   3, col); //ala vaaka
      S18_V(d, x0+4, yb-6, 6, col);  // vasen pysty
      S18_V(d, x0+8, yb-7, 10, col);  // Oikea pysty
      S18_H(d, x0+5, yb+3, 3, col);
      S18_H(d, x0+4, yb+2, 1, col);
    break;

//    case 'j':
      // descenderit: jätetään stubiksi nyt
//       S18_V(d, x0+6, yb-7, 7, col);
//      S18_V(d, x0+6, yb-7, 9, col);
//      d.drawPixel(x0+6, yb-11, col);
//      break;

    // ---- ääkköset (VAIHTOEHTO A) ----

    case '{': // ä
      Suomi18_drawLower(d, 'a', x0, y0, col);
      d.drawPixel(x0+5, yb-11, col);
      d.drawPixel(x0+8, yb-11, col); break;

    case '}': // ö
      Suomi18_drawLower(d, 'o', x0, y0, col);
      d.drawPixel(x0+5, yb-11, col);
      d.drawPixel(x0+8, yb-11, col); break;

    case '~': // å
      Suomi18_drawLower(d, 'a', x0, y0, col);
      d.drawPixel(x0+6, yb-11, col); break;
  }
}

// =======================
// YHDISTÄVÄ FUNKTIO
// =======================

/*static void Suomi18_drawChar(Adafruit_GFX &d, char c, int x, int y, uint16_t col)
{
  // pienet kirjaimet + skandit
  if ((c >= 'a' && c <= 'z') || c=='{' || c=='}' || c=='~') {
    Suomi18_drawLower(d, c, x, y, col);
    return;
  }
*/

/* static void Suomi18_drawChar(Adafruit_GFX &d, char c, int x, int y, uint16_t col)
{
  // pienet kirjaimet + ääkköset
  if ((c >= 'a' && c <= 'z') || c=='{' || c=='}' || c=='~') {
    Suomi18_drawLower(d, c, x, y, col);
    return;
  }

  // numerot
  if (c >= '0' && c <= '9') {
    Suomi18_drawLower(d, c, x, y, col);
    return;
  }

  // isot kirjaimet → pieniksi
  if (c >= 'A' && c <= 'Z') {
    Suomi18_drawLower(d, c + 32, x, y, col);
    return;
  }

  // välimerkit
  if (c == ':' || c == '.' || c == ',' || c == ';') {
    Suomi18_drawLower(d, c, x, y, col);
    return;
  }

  // erikoismerkit
  if (c == '!' || c == '?' || c == '<' || c == '>' ||
      c == '|' || c == '$' || c == '%' || c == '&' || c == '@') {
    Suomi18_drawLower(d, c, x, y, col);
    return;
  }
*/

static void Suomi18_drawChar(Adafruit_GFX &d, char c, int x, int y, uint16_t col)
{
  // Välilyönti
  if (c == ' ') {
    Suomi18_drawLower(d, ' ', x, y, col);
    return;
  }

  // pienet kirjaimet + ääkköset (sun koodaus: ä={, ö=}, å=~)
  if ((c >= 'a' && c <= 'z') || c=='{' || c=='}' || c=='~') {
    Suomi18_drawLower(d, c, x, y, col);
    return;
  }

  // numerot
  if (c >= '0' && c <= '9') {
    Suomi18_drawLower(d, c, x, y, col);
    return;
  }

  // isot kirjaimet -> tällä hetkellä pieniksi (OK A-setille, ei aidot capsit)
  if (c >= 'A' && c <= 'Z') {
    Suomi18_drawLower(d, (char)(c + 32), x, y, col);
    return;
  }

  // välimerkit (A-setti)
  if (c=='.' || c==',' || c==':' || c==';' || c=='!' || c=='?' ||
      c=='-' || c=='+' || c=='/' || c=='(' || c==')') {
    Suomi18_drawLower(d, c, x, y, col);
    return;
  }

  // jos haluat nämä vielä (sulla jo löytyy): < > | $ % & @
  if (c=='<' || c=='>' || c=='|' || c=='$' || c=='%' || c=='&' || c=='@') {
    Suomi18_drawLower(d, c, x, y, col);
    return;
  }

  // kaikki muu -> piirretään '?'
  Suomi18_drawLower(d, '?', x, y, col);
}


  // muut: ei piirretä


