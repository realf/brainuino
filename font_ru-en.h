/*
    Brainuino Aleph

    Copyright (C) 2012  Dmitry Mikhirev

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef en_ru_h
#define en_ru_h

#include <avr/pgmspace.h>

struct charcode {
  const int32_t uni;
  const char font;
};

const charcode charmap[] PROGMEM = {
// tilde
  {0x007e, 0xe9},
// latin-1 supplement
  {0x0083, 0xce},
  {0x00a2, 0x5c},
  {0x00a7, 0xfd},
  {0x00a8, 0xe8},
  {0x00ab, 0xc8},
  {0x00b4, 0xe7},
  {0x00b6, 0xfe},
  {0x00b7, 0xdf},
  {0x00bb, 0xc9},
  {0x00bc, 0xf0},
  {0x00bd, 0xf2},
  {0x00be, 0xf3},
  {0x00bf, 0xcd},
  {0x00d7, 0xd5},
  {0x00e7, 0xeb},
  {0x00e9, 0xea},
  {0x00eb, 0xb5},
// greek
  {0x0391, 0x41},
  {0x0392, 0x42},
  {0x0393, 0xa1},
  {0x0395, 0x45},
  {0x0396, 0x5a},
  {0x0397, 0x48},
  {0x0399, 0x49},
  {0x039a, 0x4b},
  {0x039c, 0x4d},
  {0x039d, 0x4e},
  {0x039f, 0x4f},
  {0x03a0, 0xa8},
  {0x03a1, 0x50},
  {0x03a4, 0x54},
  {0x03a5, 0x59},
  {0x03a6, 0xaa},
  {0x03a7, 0x58},
  {0x03ba, 0xba},
  {0x03bf, 0x6f},
  {0x03c0, 0xbe},
  {0x03c1, 0x70},
// cyryllic
  {0x0401, 0xa2},
  {0x0410, 0x41},
  {0x0411, 0xa0},
  {0x0412, 0x42},
  {0x0413, 0xa1},
  {0x0414, 0xe0},
  {0x0415, 0x45},
  {0x0416, 0xa3},
  {0x0417, 0xa4},
  {0x0418, 0xa5},
  {0x0419, 0xa6},
  {0x041a, 0x4b},
  {0x041b, 0xa7},
  {0x041c, 0x4d},
  {0x041e, 0x4f},
  {0x041f, 0xa8},
  {0x0420, 0x50},
  {0x0421, 0x43},
  {0x0422, 0x54},
  {0x0423, 0xa9},
  {0x0424, 0xaa},
  {0x0425, 0x58},
  {0x0426, 0xe1},
  {0x0427, 0xab},
  {0x0428, 0xac},
  {0x0429, 0xe2},
  {0x042a, 0xad},
  {0x042b, 0xae},
  {0x042c, 0x62},
  {0x042d, 0xaf},
  {0x042e, 0xb0},
  {0x042f, 0xb1},
  {0x0430, 0x61},
  {0x0431, 0xb2},
  {0x0432, 0xb3},
  {0x0433, 0xb4},
  {0x0434, 0xe3},
  {0x0435, 0x65},
  {0x0436, 0xb6},
  {0x0437, 0xb7},
  {0x0438, 0xb8},
  {0x0439, 0xb9},
  {0x043a, 0xba},
  {0x043b, 0xbb},
  {0x043c, 0xbc},
  {0x043d, 0xbd},
  {0x043e, 0x6f},
  {0x043f, 0xbf},
  {0x0440, 0x70},
  {0x0441, 0x63},
  {0x0442, 0xbf},
  {0x0443, 0x79},
  {0x0444, 0xe4},
  {0x0445, 0x78},
  {0x0446, 0xe5},
  {0x0447, 0xc0},
  {0x0448, 0xc1},
  {0x0449, 0xe6},
  {0x044a, 0xc2},
  {0x044b, 0xc3},
  {0x044c, 0xc4},
  {0x044d, 0xc5},
  {0x044e, 0xc6},
  {0x044f, 0xc7},
  {0x0451, 0xb5},
// general punctuation
  {0x2010, 0x2e},
  {0x2011, 0x2e},
  {0x2012, 0x2e},
  {0x2013, 0x2e},
  {0x2014, 0x2e},
  {0x2015, 0x2e},
  {0x201c, 0xca},
  {0x201d, 0xcb},
// one third
  {0x2153, 0xf1},
// arrows
  {0x2191, 0xd9},
  {0x2193, 0xda},
  {0x21b5, 0x7e},
// mathematical operators
  {0x2212, 0x2e},
  {0x2218, 0xef},
  {0x22c5, 0xdf}
};

#endif
