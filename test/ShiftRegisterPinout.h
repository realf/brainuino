/*
    Satori-brain

    Copyright (C) 2012  Sergey Dunets

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

#ifndef ____ShiftRegisterPinout__
#define ____ShiftRegisterPinout__

// Pin connected to ST_CP of 74HC595
#define LATCH    8
// Pin connected to SH_CP of 74HC595
#define CLOCK   12
// Pin connected to DS of 74HC595
#define DATA    11

// Shift register pin bitmasks
#define SHIFTREGPIN15   0x01
#define SHIFTREGPIN1    0x02
#define SHIFTREGPIN2    0x04
#define SHIFTREGPIN3    0x08
#define SHIFTREGPIN4    0x10
#define SHIFTREGPIN5    0x20
#define SHIFTREGPIN6    0x40
#define SHIFTREGPIN7    0x80

// Pins of 74HC595
#define LCDRS    SHIFTREGPIN15
#define LCDEN    SHIFTREGPIN1
#define LCDD0    SHIFTREGPIN2
#define LCDD1    SHIFTREGPIN3
#define LCDD2    SHIFTREGPIN4
#define LCDD3    SHIFTREGPIN5

#endif /*defined ____ShiftRegisterPinout__ */