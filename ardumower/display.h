#include <Arduino.h>
#include <U8x8lib.h>

//U8X8_SH1106_128X64_NONAME_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);
U8X8_SH1106_128X64_NONAME_2ND_HW_I2C u8x8(/*reset =*/ U8X8_PIN_NONE);

unsigned long nextTimeUpdateDisplay;

void DisplaySetup() {
  u8x8.begin();
  u8x8.clearDisplay();
}

void UpdateDisplayBat(){
    if (millis() < nextTimeUpdateDisplay) return;
    nextTimeUpdateDisplay = millis() + 5000; 
    u8x8.clearLine(4);
    u8x8.clearLine(5);
    u8x8.clearLine(6);
    u8x8.clearLine(7);
	  u8x8.setFont(u8x8_font_profont29_2x3_f);
      u8x8.setCursor(5, 4);
      u8x8.print(String(round((robot.batVoltage-robot.batSwitchOffIfBelow)/(robot.batFull-robot.batSwitchOffIfBelow)*100.0)) + "%");
      
	  u8x8.setFont(u8x8_font_amstrad_cpc_extended_f);
      u8x8.setCursor(5, 7);
      u8x8.print(String(robot.batVoltage) + "V");

}

void UpdateDisplayState(){
	  u8x8.setFont(u8x8_font_8x13B_1x2_f);
	  u8x8.clearLine(0);
	  u8x8.clearLine(1);
	  u8x8.clearLine(2);
    u8x8.clearLine(3);
    u8x8.setCursor((8-(strlen(robot.statusName())/2)), 0);
    u8x8.print(robot.statusName());
    u8x8.setCursor((8-(strlen(robot.stateName())/2)), 2);
    u8x8.print(robot.stateName());
}
