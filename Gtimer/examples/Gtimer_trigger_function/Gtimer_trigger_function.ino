/*
 Name:		Gtimer_trigger_function.ino
 Created:	03-Jun-22 14:30:51
 Author:	gabri
*/


#include <Gtimer.h>
//#include "D:\Gtronics.NET\Arduino\GtronicsLibraries\GtimerLibrary\Gtimer\src\Gtimer.h"

GTimer timer;

void toggleLed() {
	digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}


// the setup function runs once when you press reset or power the board
void setup() {
	pinMode(LED_BUILTIN, OUTPUT);
	timer.setInterval(1000); //set an interval of 1000ms
	timer.attach(toggleLed);
}

// the loop function runs over and over again until power down or reset
void loop() {
	timer.triggerFunction();
}