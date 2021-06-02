#include <Arduino.h>

unsigned long nextTimeLED;// use for LED
int off = 0;
int on = 0;
int ontime;
int offtime;
bool green;
bool red;

void updateLED(){
	if (millis() < nextTimeLED) return;
	nextTimeLED = millis() + 100;
	
	switch(robot.stateCurr) {
		case STATE_ERROR:
			ontime = 100; offtime = 100; green = 1; red = 1;	
		break;

		case STATE_PERI_FIND:
			ontime = 500; offtime = 1000; green = 1; red = 1;			
		break;
		
		case STATE_PERI_TRACK:
			ontime = 500; offtime = 1000; green = 1; red = 1;				
		break;
				
		case STATE_OFF:
			ontime = 100; offtime = 5000; green = 1; red = 0;	
		break;
			  
		case STATE_STATION:
			ontime = 100; offtime = 30000; green = 1; red = 1;
		break;
	
		case STATE_STATION_CHARGING:
			ontime = 100; offtime = 5000; green = 1; red = 1;			
		break;			

		default:
			ontime = 500; offtime = 1000; green = 1; red = 0;
		break;
	}
	
	if (off <= offtime/100) {
		off=off+1;
		digitalWrite(pinGreenLED, LOW);
		if (red) {digitalWrite(pinRedLED, HIGH);}
		on=0;
	}
	else {
		on=on+1;
		if (green) {digitalWrite(pinGreenLED, HIGH);}
		digitalWrite(pinRedLED, LOW);
		if (on > ontime/100) {
		off=0;
    }
  }	
}
	
