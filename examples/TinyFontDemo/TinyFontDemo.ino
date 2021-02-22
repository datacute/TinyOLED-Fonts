/*
 * Tiny4kOLED - Drivers for SSD1306 controlled dot matrix OLED/PLED 128x32 displays
 *
 * Based on ssd1306xled, re-written and extended by Stephen Denne
 * from 2017-04-25 at https://github.com/datacute/Tiny4kOLED
 *
 */

#include <Tiny4kOLED.h>

// ============================================================================

// Fonts that come with Tiny4kOLED
const DCfont *currentFont = FONT6X8;
//const DCfont *currentFont = FONT6X8P;
//const DCfont *currentFont = FONT8X16;
//const DCfont *currentFont = FONT8X16P;
//const DCfont *currentFont = FONT8X16DIGITS;

// Fonts from this TinyOLED-Fonts library

//#include "boxyfont.h"
//const DCfont *currentFont = (&cp_437_box_drawing_font);

//#include "font8x16atari.h"
//const DCfont *currentFont = FONT8X16ATARI;

//#include "font11x16.h"
//const DCfont *currentFont = FONT11X16;

//#include "font16x16cn.h"
//const DCfont *currentFont = (&TinyOLED4kfont16x16cn);

//#include "font16x32digits.h"
//const DCfont *currentFont = FONT16X32DIGITS;

//#include "ModernDos.h"
//const DCfont *currentFont = FONT8X16MDOS;

//#include "ModernDos8.h"
//const DCfont *currentFont = FONT8X8MDOS;

//#include "PixelOperator.h"
//const DCfont *currentFont = FONT8X16PO;

//#include "PixelOperatorBold.h"
//const DCfont *currentFont = FONT8X16POB;

//#include "5x5_font.h"
//const DCfont *currentFont = FONT5X5;

//#include "7linedigital_font.h"
//const DCfont *currentFont = FONT7LINEDIGITAL;

//#include "acme_5_outlines_font.h"
//const DCfont *currentFont = FONTACME5OUTLINES;

//#include "aztech_font.h"
//const DCfont *currentFont = FONTAZTECH;

//#include "Blokus_font.h"
//const DCfont *currentFont = FONTBLOKUS;

//#include "BMplain_font.h"
//const DCfont *currentFont = FONTBMPLAIN;

//#include "BMSPA_font.h"
//const DCfont *currentFont = FONTBMSPA;

//#include "bubblesstandard_font.h"
//const DCfont *currentFont = FONTBUBBLESSTANDARD;

//#include "Commo-Monospaced_font.h"
//const DCfont *currentFont = FONTCOMMOMONOSPACED;

//#include "crackers_font.h"
//const DCfont *currentFont = FONTCRACKERS;

//#include "formplex12_font.h"
//const DCfont *currentFont = FONTFORMPLEX12;

//#include "haiku_font.h"
//const DCfont *currentFont = FONTHAIKU;

//#include "HISKYF21_font.h"
//const DCfont *currentFont = FONTHISKYF21;

//#include "homespun_font.h"
//const DCfont *currentFont = FONTHOMESPUN;

//#include "HUNTER_font.h"
//const DCfont *currentFont = FONTHUNTER;

//#include "m38_font.h"
//const DCfont *currentFont = FONTM38;

//#include "Minimum+1_font.h"
//const DCfont *currentFont = FONTMINIMUM1;

//#include "Minimum_font.h"
//const DCfont *currentFont = FONTMINIMUM;

//#include "pzim3x5_font.h"
//const DCfont *currentFont = FONTPZIM3X5;

//#include "Raumsond_font.h"
//const DCfont *currentFont = FONTRAUMSOND;

//#include "renew_font.h"
//const DCfont *currentFont = FONTRENEW;

//#include "sloth_font.h"
//const DCfont *currentFont = FONTSLOTH;

//#include "SUPERDIG_font.h"
//const DCfont *currentFont = FONTSUPERDIG;

//#include "tama_mini02_font.h"
//const DCfont *currentFont = FONTTAMAMINI02;

//#include "zxpix_font.h"
//const DCfont *currentFont = FONTZXPIX;

// ============================================================================

uint8_t currentCharacter;

void setup() {
  // put your setup code here, to run once:

  oled.begin();
  oled.setFont(currentFont);
  if (currentFont->width == 0) {
    oled.setSpacing(1);
  } else {
    oled.setSpacing(currentFont->spacing + 1);
  }
  currentCharacter = currentFont->first;
  drawScreen();
  oled.on();
  oled.switchRenderFrame();
}

void loop() {
  delay(1000);
  if (currentCharacter < currentFont->last) {
    currentCharacter++;
  } else {
    currentCharacter = currentFont->first;
  }
  drawScreen();
  oled.switchFrame();
}

void drawScreen() {
  oled.clear();
  char c = (char)currentCharacter;
  for (uint8_t y = 0; y + currentFont->height <= 4; y += currentFont->height) {
    oled.setCursor(0, y);
    c = printLineOfText(c);
  }
}

char printLineOfText(char c) {
  while (oled.getCursorX() + oled.getCharacterWidth(c) <= 128) {
    oled.print(c);
    if ((uint8_t)c < currentFont->last) {
      c++;
    } else {
      c = currentFont->first;
    }
  }
  return c;
}
