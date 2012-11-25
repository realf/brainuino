#include "LiquidCrystal.h"
#include "ShiftRegisterUtils.h"
#include "ShiftRegisterPinout.h"
#include "LCDOverShiftRegister.h"

LCDOverShiftRegister *lcd;
ShiftRegisterUtils *utils;

void setup() {
  //set pins to output because they are addressed in the main loop
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(DATA, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  lcd = new LCDOverShiftRegister(LATCH, CLOCK, DATA);
  utils = new ShiftRegisterUtils(LATCH, CLOCK, DATA);
    // set up the LCD's number of columns and rows: 
  //lcd.begin(16, 2);
  // Print a message to the LCD.
  //lcd.uprint("hello, world!");
}

void loop() {
  lcd->begin(16,2);
   // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd->setCursor(0, 1);
  // print the number of seconds since reset:
  lcd->uprint("12345");
  //utils.digitalWriteToShiftRegister(6, HIGH);
}
