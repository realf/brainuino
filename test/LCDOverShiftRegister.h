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
#include <LiquidCrystal.h>

class LCDOverShiftRegister : public LiquidCrystal
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

    size_t uprint(char *rawstr);

private:    
    // Overloaded methods
    void send(uint8_t, uint8_t);
    void write4bits(uint8_t);
    void write8bits(uint8_t);
    void pulseEnable();
    
    ShiftRegisterUtils *_shiftRegisterUtils;

    uint8_t _rs_pin; // LOW: command.  HIGH: character.
    uint8_t _rw_pin; // LOW: write to LCD.  HIGH: read from LCD.
    uint8_t _enable_pin; // activated by a HIGH pulse.
    uint8_t _data_pins[8];

    uint8_t _displayfunction;
    uint8_t _displaycontrol;
    uint8_t _displaymode;

    uint8_t _initialized;

    uint8_t _numlines,_currline;
};
#endif /* defined(____LCDOverShiftRegister__) */
