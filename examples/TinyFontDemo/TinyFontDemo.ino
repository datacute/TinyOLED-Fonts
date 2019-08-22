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
//const DCfont *currentFont = FONT8X16;
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

//#include "ModernDos.h"
//const DCfont *currentFont = FONT8X16MDOS;

//#include "ModernDos8.h"
//const DCfont *currentFont = FONT8X8MDOS;

//#include "PixelOperator.h"
//const DCfont *currentFont = FONT8X16PO;

//#include "PixelOperatorBold.h"
//const DCfont *currentFont = FONT8X16POB;

// ============================================================================

uint8_t currentCharacter = currentFont->first;

void setup() {
  // put your setup code here, to run once:

  oled.begin();
  oled.setFont(currentFont);
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
  for (uint8_t x = 0; x + currentFont->width <= 128; x += currentFont->width) {
    oled.print(c);
    if ((uint8_t)c < currentFont->last) {
      c++;
    } else {
      c = currentFont->first;
    }
  }
  return c;
}