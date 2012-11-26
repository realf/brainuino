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
  Serial.println("<<<<<<<<");
  Serial.println("--BEGIN");
  lcd->begin(16,2);
  // Print a message to the LCD.
  Serial.println("--PRINT");
  lcd->print("hello, world!");
}

void loop() {
   // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  Serial.println("========");
  Serial.println("--SETCURSOR");
  lcd->setCursor(0, 1);
  // print the number of seconds since reset:
  Serial.println("--PRINT SEC");
  lcd->print(millis()/1000);
  Serial.println(">>>>>>>>");
  delay(2000);
  //utils.digitalWriteToShiftRegister(6, HIGH);
}
