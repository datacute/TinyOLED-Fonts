/*
 * Tiny4kOLED - Drivers for SSD1306 controlled dot matrix OLED/PLED 128x32 displays
 *
 * Based on ssd1306xled, re-written and extended by Stephen Denne
 * from 2017-04-25 at https://github.com/datacute/Tiny4kOLED
 *
 */
/*
 * SSD1306xLED - Drivers for SSD1306 controlled dot matrix OLED/PLED 128x64 displays
 *
 * @created: 2014-08-12
 * @author: Neven Boyanov
 *
 * Source code available at: https://bitbucket.org/tinusaur/ssd1306xled
 *
 */

// ----------------------------------------------------------------------------

#include <avr/pgmspace.h>

// ----------------------------------------------------------------------------

/* Font Information:
/* Pixel Operator (previously known as the 8-bit Operator) is a libre/free raster proportional and
 * monospace sans serif typeface.
 * Source files are available at NotABug: https://notabug.org/HarvettFox96/ttf-pixeloperator
 *
 * This typeface is made by Jayvee Enaguas (HarvettFox96), licensed under a Creative Commons Zero 
 * (CC0) 1.0. © 2009-2018.
 */ 
 
const uint8_t ssd1306xled_font8x16po [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x70, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x40, 0xf0, 0x40, 0x40, 0xf0, 0x40, 0x00, 0x00, 0x04, 0x1f, 0x04, 0x04, 0x1f, 0x04, 0x00,
    0x00, 0xe0, 0x10, 0xfc, 0x10, 0x20, 0x00, 0x00, 0x00, 0x08, 0x11, 0x7f, 0x11, 0x0e, 0x00, 0x00,
    0x60, 0x90, 0x60, 0x00, 0x80, 0x40, 0x00, 0x00, 0x00, 0x04, 0x02, 0x01, 0x0c, 0x12, 0x0c, 0x00,
    0x00, 0xe0, 0x10, 0x10, 0x10, 0x20, 0x00, 0x00, 0x00, 0x0e, 0x11, 0x11, 0x11, 0x1e, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xc0, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0x10, 0x00, 0x00,
    0x00, 0x10, 0x20, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x08, 0x07, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xa0, 0x40, 0xf0, 0x40, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x07, 0x01, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x30, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x80, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x03, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xe0, 0x10, 0x10, 0x90, 0xe0, 0x00, 0x00, 0x00, 0x0f, 0x12, 0x11, 0x10, 0x0f, 0x00, 0x00,
    0x00, 0x40, 0x20, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x1f, 0x10, 0x10, 0x00, 0x00,
    0x00, 0x20, 0x10, 0x10, 0x90, 0x60, 0x00, 0x00, 0x00, 0x1c, 0x12, 0x11, 0x10, 0x10, 0x00, 0x00,
    0x00, 0x20, 0x10, 0x10, 0x10, 0xe0, 0x00, 0x00, 0x00, 0x08, 0x10, 0x11, 0x11, 0x0e, 0x00, 0x00,
    0x00, 0x00, 0x80, 0x40, 0x20, 0xf0, 0x00, 0x00, 0x00, 0x03, 0x02, 0x02, 0x02, 0x1f, 0x00, 0x00,
    0x00, 0xf0, 0x90, 0x90, 0x90, 0x10, 0x00, 0x00, 0x00, 0x08, 0x10, 0x10, 0x10, 0x0f, 0x00, 0x00,
    0x00, 0xe0, 0x10, 0x10, 0x10, 0x20, 0x00, 0x00, 0x00, 0x0f, 0x11, 0x11, 0x11, 0x0e, 0x00, 0x00,
    0x00, 0x10, 0x10, 0x10, 0x90, 0x70, 0x00, 0x00, 0x00, 0x1c, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xe0, 0x10, 0x10, 0x10, 0xe0, 0x00, 0x00, 0x00, 0x0e, 0x11, 0x11, 0x11, 0x0e, 0x00, 0x00,
    0x00, 0xe0, 0x10, 0x10, 0x10, 0xe0, 0x00, 0x00, 0x00, 0x08, 0x11, 0x11, 0x11, 0x0f, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x30, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x80, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00,
    0x00, 0x00, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x20, 0x10, 0x10, 0x90, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17, 0x00, 0x00, 0x00, 0x00,
    0xe0, 0x10, 0x90, 0x50, 0xd0, 0x10, 0xe0, 0x00, 0x0f, 0x10, 0x13, 0x14, 0x17, 0x14, 0x03, 0x00,
    0x00, 0xe0, 0x10, 0x10, 0x10, 0xe0, 0x00, 0x00, 0x00, 0x1f, 0x02, 0x02, 0x02, 0x1f, 0x00, 0x00,
    0x00, 0xf0, 0x10, 0x10, 0x10, 0xe0, 0x00, 0x00, 0x00, 0x1f, 0x11, 0x11, 0x11, 0x0e, 0x00, 0x00,
    0x00, 0xe0, 0x10, 0x10, 0x10, 0x20, 0x00, 0x00, 0x00, 0x0f, 0x10, 0x10, 0x10, 0x08, 0x00, 0x00,
    0x00, 0xf0, 0x10, 0x10, 0x10, 0xe0, 0x00, 0x00, 0x00, 0x1f, 0x10, 0x10, 0x10, 0x0f, 0x00, 0x00,
    0x00, 0xf0, 0x10, 0x10, 0x10, 0x10, 0x00, 0x00, 0x00, 0x1f, 0x11, 0x11, 0x10, 0x10, 0x00, 0x00,
    0x00, 0xf0, 0x10, 0x10, 0x10, 0x10, 0x00, 0x00, 0x00, 0x1f, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xe0, 0x10, 0x10, 0x10, 0x20, 0x00, 0x00, 0x00, 0x0f, 0x10, 0x10, 0x11, 0x1f, 0x00, 0x00,
    0x00, 0xf0, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x1f, 0x01, 0x01, 0x01, 0x1f, 0x00, 0x00,
    0x00, 0x10, 0x10, 0xf0, 0x10, 0x10, 0x00, 0x00, 0x00, 0x10, 0x10, 0x1f, 0x10, 0x10, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x10, 0x10, 0xf0, 0x10, 0x00, 0x00, 0x08, 0x10, 0x10, 0x10, 0x0f, 0x00, 0x00,
    0x00, 0xf0, 0x00, 0x80, 0x40, 0x30, 0x00, 0x00, 0x00, 0x1f, 0x01, 0x02, 0x04, 0x18, 0x00, 0x00,
    0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x10, 0x10, 0x10, 0x10, 0x00, 0x00,
    0xf0, 0x40, 0x80, 0x00, 0x80, 0x40, 0xf0, 0x00, 0x1f, 0x00, 0x00, 0x01, 0x00, 0x00, 0x1f, 0x00,
    0x00, 0xf0, 0x80, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x01, 0x02, 0x1f, 0x00, 0x00,
    0x00, 0xe0, 0x10, 0x10, 0x10, 0xe0, 0x00, 0x00, 0x00, 0x0f, 0x10, 0x10, 0x10, 0x0f, 0x00, 0x00,
    0x00, 0xf0, 0x10, 0x10, 0x10, 0xe0, 0x00, 0x00, 0x00, 0x1f, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00,
    0x00, 0xe0, 0x10, 0x10, 0x10, 0xe0, 0x00, 0x00, 0x00, 0x0f, 0x10, 0x14, 0x08, 0x17, 0x00, 0x00,
    0x00, 0xf0, 0x10, 0x10, 0x10, 0xe0, 0x00, 0x00, 0x00, 0x1f, 0x01, 0x03, 0x05, 0x18, 0x00, 0x00,
    0x00, 0xe0, 0x10, 0x10, 0x10, 0x20, 0x00, 0x00, 0x00, 0x08, 0x11, 0x11, 0x11, 0x0e, 0x00, 0x00,
    0x00, 0x10, 0x10, 0xf0, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xf0, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x0f, 0x10, 0x10, 0x10, 0x0f, 0x00, 0x00,
    0x00, 0xf0, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x07, 0x08, 0x10, 0x08, 0x07, 0x00, 0x00,
    0xf0, 0x00, 0x00, 0xc0, 0x00, 0x00, 0xf0, 0x00, 0x0f, 0x10, 0x10, 0x0f, 0x10, 0x10, 0x0f, 0x00,
    0x00, 0x70, 0x80, 0x00, 0x80, 0x70, 0x00, 0x00, 0x00, 0x1c, 0x02, 0x01, 0x02, 0x1c, 0x00, 0x00,
    0x00, 0x70, 0x80, 0x00, 0x80, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x10, 0x10, 0x10, 0x90, 0x70, 0x00, 0x00, 0x00, 0x1c, 0x12, 0x11, 0x10, 0x10, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xf0, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x10, 0x10, 0x00, 0x00,
    0x00, 0x00, 0x70, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x00, 0x00, 0x00,
    0x00, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x40, 0x20, 0x10, 0x20, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,
    0x00, 0x00, 0x10, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x0c, 0x12, 0x12, 0x12, 0x1f, 0x00, 0x00,
    0x00, 0xf0, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x1f, 0x10, 0x10, 0x10, 0x0f, 0x00, 0x00,
    0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x0f, 0x10, 0x10, 0x10, 0x08, 0x00, 0x00,
    0x00, 0x80, 0x40, 0x40, 0x40, 0xf0, 0x00, 0x00, 0x00, 0x0f, 0x10, 0x10, 0x10, 0x1f, 0x00, 0x00,
    0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x0f, 0x12, 0x12, 0x12, 0x0b, 0x00, 0x00,
    0x00, 0x00, 0x80, 0xe0, 0x90, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x80, 0x40, 0x40, 0x40, 0xc0, 0x00, 0x00, 0x00, 0x27, 0x48, 0x48, 0x48, 0x3f, 0x00, 0x00,
    0x00, 0xf0, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00,
    0x00, 0x40, 0x40, 0xd0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x1f, 0x10, 0x10, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x40, 0x40, 0xd0, 0x00, 0x00, 0x00, 0x20, 0x40, 0x40, 0x40, 0x3f, 0x00, 0x00,
    0x00, 0xf0, 0x00, 0x00, 0x80, 0x40, 0x00, 0x00, 0x00, 0x1f, 0x02, 0x05, 0x08, 0x10, 0x00, 0x00,
    0x00, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x1f, 0x10, 0x10, 0x00, 0x00,
    0xc0, 0x40, 0x40, 0x80, 0x40, 0x40, 0x80, 0x00, 0x1f, 0x00, 0x00, 0x07, 0x00, 0x00, 0x1f, 0x00,
    0x00, 0xc0, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00,
    0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x0f, 0x10, 0x10, 0x10, 0x0f, 0x00, 0x00,
    0x00, 0xc0, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x7f, 0x10, 0x10, 0x10, 0x0f, 0x00, 0x00,
    0x00, 0x80, 0x40, 0x40, 0x40, 0xc0, 0x00, 0x00, 0x00, 0x0f, 0x10, 0x10, 0x10, 0x7f, 0x00, 0x00,
    0x00, 0xc0, 0x00, 0x80, 0x40, 0x40, 0x00, 0x00, 0x00, 0x1f, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x09, 0x12, 0x12, 0x12, 0x0c, 0x00, 0x00,
    0x00, 0x00, 0x40, 0xe0, 0x40, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x10, 0x10, 0x00, 0x00,
    0x00, 0xc0, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x0f, 0x10, 0x10, 0x10, 0x0f, 0x00, 0x00,
    0x00, 0xc0, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x07, 0x08, 0x10, 0x08, 0x07, 0x00, 0x00,
    0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x0f, 0x10, 0x10, 0x0f, 0x10, 0x10, 0x0f, 0x00,
    0x00, 0xc0, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x18, 0x05, 0x02, 0x05, 0x18, 0x00, 0x00,
    0x00, 0xc0, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x27, 0x48, 0x48, 0x48, 0x3f, 0x00, 0x00,
    0x00, 0x40, 0x40, 0x40, 0x40, 0xc0, 0x00, 0x00, 0x00, 0x18, 0x14, 0x12, 0x11, 0x10, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xe0, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x01, 0x0e, 0x10, 0x10, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x10, 0x10, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x0e, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x20, 0x10, 0x10, 0x20, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


// ----------------------------------------------------------------------------

const DCfont TinyOLED4kfont8x16po = {
  (uint8_t *)ssd1306xled_font8x16po,
  8, // character width in pixels
  2, // character height in pages (8 pixels)
  32,126 // ASCII extents
  };

// for backwards compatibility
#define FONT8X16PO (&TinyOLED4kfont8x16po)