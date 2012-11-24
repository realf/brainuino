//
//  ShiftRegisterUtils.h
//  
//
//  Created by Sergey Dunets on 19.11.12.
//
//

#ifndef ____ShiftRegisterUtils__
#define ____ShiftRegisterUtils__

#include "Arduino.h"

class ShiftRegisterUtils
{
public:
    ShiftRegisterUtils(uint8_t latchPin, uint8_t clockPin, uint8_t dataPin);
    void digitalWriteToShiftRegister(uint8_t shiftRegisterOutputPin, uint8_t val);
    
private:
    // In this variable we store the current value of the shift register output
    uint8_t _output;
    
    // Pin connected to ST_CP of 74HC595
    uint8_t _latchPin;
    // Pin connected to SH_CP of 74HC595
    uint8_t _clockPin;
    // Pin connected to DS of 74HC595
    uint8_t _dataPin;
};

#endif /* defined(____ShiftRegisterUtils__) */
