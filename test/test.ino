#include <LiquidCrystal.h>
#include "ShiftRegisterUtils.h"
#include "ShiftRegisterPinout.h"
#include "LCDOverShiftRegister.h"

LCDOverShiftRegister lcd(LATCH, CLOCK, DATA);

void setup() {
  //set pins to output because they are addressed in the main loop
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(DATA, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly: 
  lcd.begin(16, 2);
  lcd.setCursor(0, 1);
  while(1)
  {
    for (int i = 0; i < 8; i++)
    {
      lcd.uprint("hello world");
      delay(500);
    }
  }
}
