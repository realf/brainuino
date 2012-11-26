//
//  LCDOverShiftRegister.h
//  
//
//  Created by Sergey Dunets on 19.11.12.
//
//

#ifndef ____LCDOverShiftRegister__
#define ____LCDOverShiftRegister__

#include "ShiftRegisterUtils.h"
#include <inttypes.h>
#include "Print.h"

// commands
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80

// flags for display entry mode
#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

// flags for display on/off control
#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00

// flags for display/cursor shift
#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE 0x00
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00

// flags for function set
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00

class LCDOverShiftRegister : public Print
{
public:
    LCDOverShiftRegister(uint8_t shiftRegisterLatchPin,
        uint8_t shiftRegisterClockPin, uint8_t shiftRegisterDataPin, 
        uint8_t lcdRs, uint8_t lcdEnable, uint8_t lcdD0, uint8_t lcdD1,
        uint8_t lcdD2, uint8_t lcdD3);

    LCDOverShiftRegister(uint8_t shiftRegisterLatchPin,
        uint8_t shiftRegisterClockPin, uint8_t shiftRegisterDataPin);

    virtual ~LCDOverShiftRegister();

    void init(uint8_t shiftRegisterLatchPin,
        uint8_t shiftRegisterClockPin, uint8_t shiftRegisterDataPin, 
        uint8_t lcdRs, uint8_t lcdEnable, uint8_t lcdD0, uint8_t lcdD1,
        uint8_t lcdD2, uint8_t lcdD3);

    void begin(uint8_t cols, uint8_t rows, uint8_t charsize = LCD_5x8DOTS);

    void createChar(uint8_t location, uint8_t charmap[]);
    void setCursor(uint8_t, uint8_t);
    size_t uprint(char *rawstr);
    virtual size_t write(uint8_t);
    void command(uint8_t);

    void clear();
    void home();

    void noDisplay();
    void display();
    void noBlink();
    void blink();
    void noCursor();
    void cursor();
    void scrollDisplayLeft();
    void scrollDisplayRight();
    void leftToRight();
    void rightToLeft();
    void autoscroll();
    void noAutoscroll();

    using Print::write;

private:    
    // Overloaded methods
    void send(uint8_t, uint8_t);
    void write4bits(uint8_t);
    void write8bits(uint8_t);
    void pulseEnable();
    
    ShiftRegisterUtils *_shiftRegisterUtils;

    uint8_t _rs_pin; // LOW: command.  HIGH: character.
    uint8_t _enable_pin; // activated by a HIGH pulse.
    uint8_t _data_pins[8];

    uint8_t _displayfunction;
    uint8_t _displaycontrol;
    uint8_t _displaymode;

    uint8_t _numlines,_currline;
};
#endif /* defined(____LCDOverShiftRegister__) */
