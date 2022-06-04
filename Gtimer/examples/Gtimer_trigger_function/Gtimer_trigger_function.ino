/*
 Name:		Gtimer_trigger_function.ino
 Created:	03-Jun-22 14:30:51
 Author:	gabri
*/


//#include <Gtimer.h>
#include "D:\Gtronics.NET\Arduino\GtronicsLibraries\GtimerLibrary\Gtimer\src\Gtimer.h"


void toggleLed() {
	digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}

GTimer timer(100, toggleLed); //if you instantiate with interval it automatically sets the interval

// the setup function runs once when you press reset or power the board
void setup() {
	pinMode(LED_BUILTIN, OUTPUT);
	//timer.setInterval(1000); //set an interval of 1000ms, no needed if specified while instantiating
	//timer.attach(toggleLed); //specify which function to call on timeout, no needed if specified while instantiating
}

// the loop function runs over and over again until power down or reset
void loop() {
	timer.update();
	//timer.triggerFunction(); //alternative to update method
}