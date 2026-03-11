#pragma once

// --------------------
// HAIKU – SANALISTAT
// --------------------

// 1. rivi (5 tavua, tunnelma / luonto)
static const char* HAIKU_LINE1[] = {
  "hiljainen hetki",
  "sumuinen aamu",
  "talvinen ranta",
  "yö hengittää",
  "jäinen kuu"
};

// 2. rivi (7 tavua, toiminta / havainto)
static const char* HAIKU_LINE2[] = {
  "meri odottaa kaukaa",
  "tuuli kulkee yksin",
  "jäljet katoavat lumeen",
  "varjo liikkuu hitaasti",
  "jää laulaa hiljaa"
};

// 3. rivi (5 tavua, päätös / oivallus)
static const char* HAIKU_LINE3[] = {
  "kaikki pysähtyy",
  "hetki jää eloon",
  "valo kirkastuu",
  "aika hengittää",
  "hiljaisuus vastaa"
};

#define HAIKU_L1_COUNT (sizeof(HAIKU_LINE1)/sizeof(HAIKU_LINE1[0]))
#define HAIKU_L2_COUNT (sizeof(HAIKU_LINE2)/sizeof(HAIKU_LINE2[0]))
#define HAIKU_L3_COUNT (sizeof(HAIKU_LINE3)/sizeof(HAIKU_LINE3[0]))
