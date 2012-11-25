//
//  LCDOverShiftRegister.cpp
//  
//
//  Created by Sergey Dunets on 19.11.12.
//
//

#include "LCDOverShiftRegister.h"
#include "ShiftRegisterPinout.h"
#include "utf8.h"
#include "font.h"

LCDOverShiftRegister::LCDOverShiftRegister(uint8_t shiftRegisterLatchPin,
    uint8_t shiftRegisterClockPin, uint8_t shiftRegisterDataPin, 
    uint8_t lcdRs, uint8_t lcdEnable, uint8_t lcdD0, uint8_t lcdD1,
    uint8_t lcdD2, uint8_t lcdD3)
: LiquidCrystal(lcdRs, lcdEnable, lcdD0, lcdD1, lcdD2, lcdD3)
{
    Serial.println("constructor0");
    init(shiftRegisterLatchPin, shiftRegisterClockPin, shiftRegisterDataPin, 
        lcdRs, lcdEnable, lcdD0, lcdD1, lcdD2, lcdD3);
}

LCDOverShiftRegister::LCDOverShiftRegister(uint8_t shiftRegisterLatchPin,
    uint8_t shiftRegisterClockPin, uint8_t shiftRegisterDataPin)
: LiquidCrystal(LCDRS, LCDEN, LCDD0, LCDD1, LCDD2, LCDD3)
{
    Serial.println("constructor1");
    init(shiftRegisterLatchPin, shiftRegisterClockPin, shiftRegisterDataPin, LCDRS, LCDEN, LCDD0, LCDD1, LCDD2, LCDD3);
}

LCDOverShiftRegister::~LCDOverShiftRegister()
{
    delete _shiftRegisterUtils;
    _shiftRegisterUtils = NULL;
}

// All arguments are the ouput pins of the 74HC595 shift register.
// 4-bit mode implemention.
void LCDOverShiftRegister::init(uint8_t shiftRegisterLatchPin,
    uint8_t shiftRegisterClockPin, uint8_t shiftRegisterDataPin, 
    uint8_t lcdRs, uint8_t lcdEnable, uint8_t lcdD0, uint8_t lcdD1,
    uint8_t lcdD2, uint8_t lcdD3)
{
    Serial.print("init ");
    Serial.print(shiftRegisterLatchPin);
    Serial.print(" ");
    Serial.print(shiftRegisterClockPin);
    Serial.print(" ");
    Serial.print(shiftRegisterDataPin);
    Serial.print(" ");
    Serial.print(lcdRs);
    Serial.print(" ");
    Serial.print(lcdEnable);
    Serial.print(" ");
    Serial.print(lcdD0);
    Serial.print(" ");
    Serial.print(lcdD1);
    Serial.print(" ");
    Serial.print(lcdD2);
    Serial.print(" ");
    Serial.println(lcdD3);
    
    _shiftRegisterUtils = new ShiftRegisterUtils(shiftRegisterLatchPin, shiftRegisterClockPin, shiftRegisterDataPin);

    _rs_pin = lcdRs;
    _enable_pin = lcdEnable;
    
    _data_pins[0] = lcdD0;
    _data_pins[1] = lcdD1;
    _data_pins[2] = lcdD2;
    _data_pins[3] = lcdD3;
    _data_pins[4] = 0;
    _data_pins[5] = 0;
    _data_pins[6] = 0;
    _data_pins[7] = 0;
    
    _displayfunction = LCD_4BITMODE | LCD_1LINE | LCD_5x8DOTS;
    
    begin(16, 1);
}

void LCDOverShiftRegister::begin(uint8_t cols, uint8_t lines, uint8_t dotsize)
{
    Serial.print("begin ");
    Serial.print(cols);
    Serial.print(" ");
    Serial.print(lines);
    Serial.print(" ");
    Serial.println(dotsize);
    
    if (lines > 1) {
        _displayfunction |= LCD_2LINE;
    }
    _numlines = lines;
    _currline = 0;

    // for some 1 line displays you can select a 10 pixel high font
    if ((dotsize != 0) && (lines == 1)) {
        _displayfunction |= LCD_5x10DOTS;
    }

    // SEE PAGE 45/46 FOR INITIALIZATION SPECIFICATION!
    // according to datasheet, we need at least 40ms after power rises above 2.7V
    // before sending commands. Arduino can turn on way befer 4.5V so we'll wait 50
    delayMicroseconds(50000); 
    // Now we pull both RS and R/W low to begin commands
    _shiftRegisterUtils->digitalWriteToShiftRegister(_rs_pin, LOW);
    _shiftRegisterUtils->digitalWriteToShiftRegister(_enable_pin, LOW);

    //put the LCD into 4 bit or 8 bit mode
    if (! (_displayfunction & LCD_8BITMODE)) {
        // this is according to the hitachi HD44780 datasheet
        // figure 24, pg 46

        // we start in 8bit mode, try to set 4 bit mode
        write4bits(0x03);
        delayMicroseconds(4500); // wait min 4.1ms

        // second try
        write4bits(0x03);
        delayMicroseconds(4500); // wait min 4.1ms
        
        // third go!
        write4bits(0x03); 
        delayMicroseconds(150);

        // finally, set to 4-bit interface
        write4bits(0x02); 
    } else {
        // this is according to the hitachi HD44780 datasheet
        // page 45 figure 23

        // Send function set command sequence
        command(LCD_FUNCTIONSET | _displayfunction);
        delayMicroseconds(4500);  // wait more than 4.1ms

        // second try
        command(LCD_FUNCTIONSET | _displayfunction);
        delayMicroseconds(150);

        // third go
        command(LCD_FUNCTIONSET | _displayfunction);
    }

      // finally, set # lines, font size, etc.
    command(LCD_FUNCTIONSET | _displayfunction);  

      // turn the display on with no cursor or blinking default
    _displaycontrol = LCD_DISPLAYON | LCD_CURSOROFF | LCD_BLINKOFF;  
    display();

      // clear it off
    clear();

      // Initialize to default text direction (for romance languages)
    _displaymode = LCD_ENTRYLEFT | LCD_ENTRYSHIFTDECREMENT;
      // set the entry mode
    command(LCD_ENTRYMODESET | _displaymode);
}

size_t LCDOverShiftRegister::uprint(char *rawstr)
{ 
    Serial.print("uprint ");
    Serial.println(rawstr);
    int32_t ucode;
    int i, j;
    int numcodes = sizeof(charmap)/sizeof(charcode);
    utf8 str = utf8(rawstr);
    char result[str.chars];

    for (i = 0; i < str.chars; i++) {
        ucode = str.get();
        if (ucode > 0x0000) {
            if (ucode <= 0x007d) {
                result[i] = ucode;
            } else {
                result[i] = 0xff;
                for (j = 0; (j < numcodes) && (pgm_read_dword(&charmap[j].uni) <= ucode); j++) {
                    if (pgm_read_dword(&charmap[j].uni) == ucode) {
                        result[i] = pgm_read_byte(&charmap[j].font);
                    }
                }
            }
        } else {
            break;
        }
    }
    result[i] = 0;
    return print(result);
}

// Allows us to fill the first 8 CGRAM locations
// with custom characters
void LCDOverShiftRegister::createChar(uint8_t location, uint8_t charmap[]) {
    location &= 0x7; // we only have 8 locations 0-7
    command(LCD_SETCGRAMADDR | (location << 3));
    for (int i=0; i<8; i++) {
        write(charmap[i]);
    }    
}

/*********** mid level commands, for sending data/cmds */

inline void LCDOverShiftRegister::command(uint8_t value)
{
    Serial.print("command ");
    Serial.println(value, HEX);
    send(value, LOW);
}

inline size_t LCDOverShiftRegister::write(uint8_t value)
{
    Serial.print("write ");
    Serial.println(value, HEX);
    send(value, HIGH);
    return 1; // assume sucess
}

/************ low level data pushing commands **********/

// write either command or data, with automatic 4/8-bit selection
void LCDOverShiftRegister::send(uint8_t value, uint8_t mode)
{
    Serial.print("send ");
    Serial.print(value, HEX);
    Serial.print(" ");
    Serial.println(mode, HEX);
    _shiftRegisterUtils->digitalWriteToShiftRegister(_rs_pin, mode);
    
    if (_displayfunction & LCD_8BITMODE) {
        write8bits(value);
    } else {
        write4bits(value >> 4);
        write4bits(value);
    }
}

void LCDOverShiftRegister::pulseEnable(void)
{
    Serial.println("pulseEnable ");
    _shiftRegisterUtils->digitalWriteToShiftRegister(_enable_pin, LOW);
    delayMicroseconds(1);
    _shiftRegisterUtils->digitalWriteToShiftRegister(_enable_pin, HIGH);
    delayMicroseconds(1);    // enable pulse must be >450ns
    _shiftRegisterUtils->digitalWriteToShiftRegister(_enable_pin, LOW);
    delayMicroseconds(100);   // commands need > 37us to settle
}

void LCDOverShiftRegister::write4bits(uint8_t value)
{
    Serial.print("write4bits ");
    Serial.println(value, BIN);
    for (int i = 0; i < 4; i++) {
        _shiftRegisterUtils->digitalWriteToShiftRegister(_data_pins[i], (value >> i) & 0x01);
    }
    
    delay(1000);
    pulseEnable();
}

void LCDOverShiftRegister::write8bits(uint8_t value) 
{
    Serial.print("write8bits ");
    Serial.println(value, BIN);
    for (int i = 0; i < 8; i++) 
    {
        _shiftRegisterUtils->digitalWriteToShiftRegister(_data_pins[i], (value >> i) & 0x01);
    }
    
    pulseEnable();
}
