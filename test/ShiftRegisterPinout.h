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

// Bits of 74HC595
#define LCDRS    0
#define LCDEN    1
#define LCDD0    2
#define LCDD1    3
#define LCDD2    4
#define LCDD3    5

#endif /*defined ____ShiftRegisterPinout__ */