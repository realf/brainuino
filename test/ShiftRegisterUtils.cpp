//
//  ShiftRegisterUtils.cpp
//  
//
//  Created by Sergey Dunets on 19.11.12.
//
//

#include "ShiftRegisterUtils.h"

ShiftRegisterUtils::ShiftRegisterUtils(uint8_t latchPin, uint8_t clockPin,
                                       uint8_t dataPin)
{
    _latchPin = latchPin;
    _clockPin = clockPin;
    _dataPin = dataPin;
    digitalWrite(_clockPin, LOW);
    _output = 0;
}

void ShiftRegisterUtils::digitalWriteToShiftRegister(uint8_t shiftRegisterOutputPin,
                                                     uint8_t val)
{
    Serial.print("digitalWrite ");
    Serial.print(shiftRegisterOutputPin);
    Serial.print(" ");
    Serial.println(val);
    // Ground latchPin and hold low for as long as you are transmitting
    digitalWrite(_latchPin, LOW);
    
    // bitmask
    uint8_t bit = 1 << shiftRegisterOutputPin;
    
    if (val == LOW)
        _output &= ~bit;
    else
        _output |= bit;
    
    shiftOut(_dataPin, _clockPin, MSBFIRST, _output);
    
    // Return the latch pin high to signal chip that it
    // no longer needs to listen for information
    digitalWrite(_latchPin, HIGH);
}
