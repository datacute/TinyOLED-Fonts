/* Font data from https://jared.geek.nz/2014/jan/custom-fonts-for-microcontrollers */
#include <avr/pgmspace.h>
const uint8_t ssd1306xled_fonthaiku [] PROGMEM = {
  0x00,0x00,0x00,0x00,0x00,0x00, // 0x20 32  
  0x00,0x5e,0x00,0x00,0x00,0x00, // 0x21 33 !
  0x00,0x0e,0x0e,0x00,0x00,0x00, // 0x22 34 "
  0x00,0x7f,0x40,0x40,0x7f,0x00, // 0x23 35 #
  0x00,0x7e,0x52,0xd2,0x52,0x76, // 0x24 36 $
  0x00,0x7f,0x40,0x40,0x7f,0x00, // 0x25 37 %
  0x00,0x70,0x7c,0x52,0x7e,0x40, // 0x26 38 &
  0x00,0x0e,0x00,0x00,0x00,0x00, // 0x27 39 '
  0x00,0xfe,0x82,0x00,0x00,0x00, // 0x28 40 (
  0x00,0x82,0xfe,0x00,0x00,0x00, // 0x29 41 )
  0x00,0x14,0x0e,0x14,0x00,0x00, // 0x2A 42 *
  0x10,0x10,0x38,0x10,0x10,0x00, // 0x2B 43 +
  0x00,0xc0,0x00,0x00,0x00,0x00, // 0x2C 44 ,
  0x00,0x10,0x10,0x10,0x00,0x00, // 0x2D 45 -
  0x00,0x40,0x00,0x00,0x00,0x00, // 0x2E 46 .
  0x00,0xfe,0x00,0x00,0x00,0x00, // 0x2F 47 /
  0x00,0x7e,0x42,0x7e,0x00,0x00, // 0x30 48 0
  0x00,0x02,0x7e,0x00,0x00,0x00, // 0x31 49 1
  0x00,0x76,0x52,0x52,0x7e,0x00, // 0x32 50 2
  0x00,0x66,0x42,0x52,0x7e,0x42, // 0x33 51 3
  0x00,0x1e,0x50,0x78,0x50,0x00, // 0x34 52 4
  0x00,0x7e,0x52,0x52,0x72,0x00, // 0x35 53 5
  0x00,0x7e,0x52,0x52,0x76,0x00, // 0x36 54 6
  0x00,0x06,0x02,0x42,0x7e,0x42, // 0x37 55 7
  0x00,0x7e,0x52,0x52,0x7e,0x00, // 0x38 56 8
  0x00,0x7e,0x52,0x52,0x7e,0x00, // 0x39 57 9
  0x00,0x50,0x00,0x00,0x00,0x00, // 0x3A 58 :
  0x00,0x90,0x00,0x00,0x00,0x00, // 0x3B 59 ;
  0x00,0x7f,0x40,0x40,0x7f,0x00, // 0x3C 60 <
  0x00,0x18,0x18,0x18,0x00,0x00, // 0x3D 61 =
  0x00,0x7f,0x40,0x40,0x7f,0x00, // 0x3E 62 >
  0x00,0x06,0x72,0x12,0x1e,0x00, // 0x3F 63 ?
  0x00,0x78,0x48,0x78,0x48,0x00, // 0x40 64 @
  0x00,0x42,0x7e,0x12,0x12,0x7e, // 0x41 65 A
  0x00,0x52,0x7e,0x52,0x5e,0x70, // 0x42 66 B
  0x00,0x42,0x7e,0x42,0x42,0xe6, // 0x43 67 C
  0x00,0x42,0x7e,0x42,0x42,0x7e, // 0x44 68 D
  0x00,0x42,0x7e,0x5a,0x42,0xe6, // 0x45 69 E
  0x42,0x7e,0x52,0x3a,0x02,0x06, // 0x46 70 F
  0x00,0x42,0x7e,0x42,0x52,0x76, // 0x47 71 G
  0x00,0x42,0x7e,0x10,0x10,0x7e, // 0x48 72 H
  0x00,0x42,0x7e,0x42,0x00,0x00, // 0x49 73 I
  0x00,0x02,0xfe,0x02,0x00,0x00, // 0x4A 74 J
  0x00,0x52,0x7e,0x10,0x1e,0x72, // 0x4B 75 K
  0x00,0x42,0x7e,0x42,0x40,0xe0, // 0x4C 76 L
  0x00,0x42,0x7e,0x02,0xfe,0x02, // 0x4D 77 M
  0x42,0x42,0x7e,0x02,0x02,0x7e, // 0x4E 78 N
  0x00,0x7e,0x42,0x42,0x7e,0x00, // 0x4F 79 O
  0x00,0x52,0x7e,0x52,0x12,0x1e, // 0x50 80 P
  0x00,0x7e,0x42,0xc2,0x7e,0x00, // 0x51 81 Q
  0x00,0x52,0x7e,0x52,0x32,0x5e, // 0x52 82 R
  0x00,0xfe,0x52,0x52,0x76,0x00, // 0x53 83 S
  0x00,0x06,0x42,0x7e,0x42,0x02, // 0x54 84 T
  0x00,0x42,0x7e,0x40,0x40,0x7e, // 0x55 85 U
  0x00,0x02,0x1e,0x20,0x20,0x1e, // 0x56 86 V
  0x00,0x02,0x7e,0x40,0x7e,0x40, // 0x57 87 W
  0x02,0x42,0x6e,0x10,0x10,0x6e, // 0x58 88 X
  0x02,0x1e,0x50,0x70,0x50,0x1e, // 0x59 89 Y
  0x66,0x52,0x4a,0x4a,0xe6,0x00, // 0x5A 90 Z
  0x00,0xfe,0x82,0x00,0x00,0x00, // 0x5B 91 [
  0x00,0x7f,0x40,0x40,0x7f,0x00, // 0x5C 92 \ backslash
  0x00,0x82,0xfe,0x00,0x00,0x00, // 0x5D 93 ]
  0x00,0x7f,0x40,0x40,0x7f,0x00, // 0x5E 94 ^
  0x00,0x40,0x40,0x40,0x00,0x00, // 0x5F 95 _
  0x00,0x7f,0x40,0x40,0x7f,0x00, // 0x60 96 `
  0x00,0x70,0x5c,0x58,0x78,0x00, // 0x61 97 a
  0x00,0x42,0x7e,0x48,0x48,0x78, // 0x62 98 b
  0x00,0x78,0x48,0x48,0xfc,0x00, // 0x63 99 c
  0x00,0x78,0x48,0x48,0x7e,0x42, // 0x64 100 d
  0x00,0x78,0x68,0x68,0xf8,0x00, // 0x65 101 e
  0x00,0x50,0x7e,0x52,0x00,0x00, // 0x66 102 f
  0x00,0x78,0x48,0x48,0xf8,0x08, // 0x67 103 g
  0x00,0x42,0x7e,0x08,0x08,0x78, // 0x68 104 h
  0x00,0x48,0x7a,0x48,0x00,0x00, // 0x69 105 i
  0x00,0x08,0xfa,0x08,0x00,0x00, // 0x6A 106 j
  0x00,0x42,0x7e,0x50,0x1c,0x70, // 0x6B 107 k
  0x00,0x42,0x7e,0x40,0x00,0x00, // 0x6C 108 l
  0x00,0x48,0x78,0x08,0xf8,0x08, // 0x6D 109 m
  0x48,0x48,0x78,0x08,0x08,0x78, // 0x6E 110 n
  0x00,0x78,0x48,0x48,0x78,0x00, // 0x6F 111 o
  0x00,0x08,0xf8,0x48,0x48,0x78, // 0x70 112 p
  0x00,0x78,0x48,0x48,0xf8,0x08, // 0x71 113 q
  0x00,0x48,0x78,0x48,0x18,0x00, // 0x72 114 r
  0x00,0xd8,0x58,0x58,0x7c,0x00, // 0x73 115 s
  0x00,0x08,0x48,0x7e,0x48,0x08, // 0x74 116 t
  0x00,0x48,0x78,0x40,0x40,0x78, // 0x75 117 u
  0x08,0x18,0x28,0x40,0x28,0x18, // 0x76 118 v
  0x00,0x08,0x78,0x40,0x78,0x40, // 0x77 119 w
  0x08,0x48,0x58,0x20,0x58,0x48, // 0x78 120 x
  0x00,0x08,0x78,0xc0,0x40,0x78, // 0x79 121 y
  0x00,0x6c,0x58,0x58,0xc8,0x00, // 0x7A 122 z
  0x00,0x7f,0x40,0x40,0x7f,0x00, // 0x7B 123 {
  0x00,0xfe,0x00,0x00,0x00,0x00, // 0x7C 124 |
  0x00,0x7f,0x40,0x40,0x7f,0x00, // 0x7D 125 }
  0x00,0x7f,0x40,0x40,0x7f,0x00, // 0x7E 126 ~
  0x00,0x00,0x00,0x00,0x00,0x00, // 0x7F 127
};
const DCfont TinyOLEDFonthaiku = {
  (uint8_t *)ssd1306xled_fonthaiku,
  6, // character width in pixels
  1, // character height in pages (8 pixels)
  32,127 // ASCII extents
  };
#define FONTHAIKU (&TinyOLEDFonthaiku)
