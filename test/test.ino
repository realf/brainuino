#include "ShiftRegisterUtils.h"

//Pin connected to ST_CP of 74HC595
int latchPin = 8;
//Pin connected to SH_CP of 74HC595
int clockPin = 12;
//Pin connected to DS of 74HC595
int dataPin = 11;

ShiftRegisterUtils shiftRegisterUtils(latchPin, clockPin, dataPin);

void setup() {
  //set pins to output because they are addressed in the main loop
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly: 
  bool t = true;
  while(1)
  {
    for (int i = 0; i < 8; i++)
    {
      shiftRegisterUtils.digitalWriteToShiftRegister(i, t? HIGH : LOW);
      delay(500);
    }
    delay(1000);
    t = !t;
  }
}
