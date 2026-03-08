# ESP32 E-Ink Finnish Fonts

Finnish optimized bitmap fonts for **ESP32 + SSD1680 E-Ink displays**.

This project provides lightweight bitmap fonts with full support for Finnish characters and punctuation.
The fonts are designed specifically for **E-Ink readability** and work with the **Adafruit_GFX graphics library**.

The repository also includes a working **Haiku generator example** that fetches the current time via **NTP** and updates the poem automatically every morning.

---

# Features

* Full support for Finnish characters
  **Ä ä Ö ö Å å**
* Optimized for **E-Ink displays**
* Lightweight bitmap fonts (very fast rendering)
* Compatible with **Adafruit_GFX**
* Works on **ESP32**
* Includes a **complete working example**

---

# Included Fonts

## suomi18px.h

Readable body text font designed for E-Ink displays.

Characteristics:

* balanced baseline
* clean lowercase characters
* good readability on 2.13" displays
* optimized spacing

Supported characters include:

```
ABCDEFGHIJKLMNOPQRSTUVWXYZ
abcdefghijklmnopqrstuvwxyz
0123456789
ÄÖÅ äöå
.,:;!?-+*/()[]{}<>
```

---

## suomi20px_caps.h

Headline font designed for titles.

Characteristics:

* uppercase letters
* slightly larger size for headings
* optimized for E-Ink contrast

Example usage:

```
HAIKU
TODAY
WEATHER
DATE
```

---

# Example Project

Included example:

**Haiku Generator**

Features:

* fetches current time using **NTP**
* generates a new haiku every day
* automatically updates the poem at **07:00 in the morning**
* uses the included Finnish fonts

Example display layout:

```
HAIKU

Silent winter lake
Morning sun touches the ice
A crow breaks the calm

08.03.2026 07:00
```

---

# Hardware Tested

The project has been tested with:

* **ESP32**
* **LOLIN 2.13" E-Ink display**
* **SSD1680 driver**
* **Adafruit_GFX**

Other SSD1680 based displays may also work.

---

# Libraries Used

The following libraries are required:

```
Adafruit_GFX
LOLIN_EPD
WiFi
time
```

Install them via the **Arduino Library Manager** if necessary.

---

# Folder Structure

```
esp32-eink-suomi-fonts
│
├── fonts
│   ├── suomi18px.h
│   └── suomi20px_caps.h
│
├── examples
│   ├── font_test
│   └── haiku_generator
│
└── images
    └── eink_example.jpg
```

---

# Why These Fonts Exist

Many Arduino fonts lack proper support for **Scandinavian characters** or render poorly on E-Ink displays.

These fonts were created to solve common problems:

* missing **Ä Ö Å**
* poor baseline alignment
* bad readability on low-resolution E-Ink panels

The fonts are designed specifically for **clear text rendering on small E-Ink displays**.

---

# Example Output

Example output on a 2.13" E-Ink display:

```
HAIKU

Morning frost glitters
Quiet forest waits for spring
Light returns slowly
```

---

# License

MIT License

You are free to:

* use
* modify
* distribute

the fonts and code.

---

# Author

Created by **Jukka Holopainen**

Electronics / embedded hobbyist interested in:

* ESP32 projects
* E-Ink displays
* custom bitmap fonts
* Finnish language support in embedded systems

---

# Future Improvements

Possible future additions:

* 16px font version
* automatic line wrapping
* additional punctuation
* support for more E-Ink displays

---
