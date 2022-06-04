/*
 Name:		Gtimer_basic.ino
 Created:	03-Jun-22 13:13:52
 Author:	gabri
*/

//#include <Gtimer.h>
#include "D:\Gtronics.NET\Arduino\GtronicsLibraries\GtimerLibrary\Gtimer\src\Gtimer.h"

//GTimer timer;  
GTimer timer(500); //if you instantiate with interval it automatically sets the interval


// the setup function runs once when you press reset or power the board
void setup() {
	pinMode(LED_BUILTIN, OUTPUT);
	//timer.setInterval(500); //set an interval of 500ms, no needed if specified while instantiating

}

// the loop function runs over and over again until power down or reset
void loop() {
	if (timer.isElapsed()) //if no specified isElapsed automatically reset the timer if elapsed
	{
		digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
		//timer.reset();
	}
}
