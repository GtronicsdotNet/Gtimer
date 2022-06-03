#include "Arduino.h"
#include "Gtimer.h"


void GTimer::setInterval(unsigned long interval)
{
	m_timeoutMs = interval;
	this->reset();
}



void GTimer::attach(void(*function)())
{
	m_function = function;
}

void GTimer::reset()
{
	m_lastResetMs = millis();
}

bool GTimer::isElapsed(bool resetIfElapsed)
{
	bool elapsed = ((millis() - m_lastResetMs) > m_timeoutMs);

	if (resetIfElapsed)
		this->reset();
	
	return elapsed;
}

bool GTimer::triggerFunction(bool resetIfTriggered)
{
	bool elapsed = ((millis() - m_lastResetMs) > m_timeoutMs);
	if (m_function && elapsed)
	{
		m_function();
	}
	
	if (resetIfTriggered)
		this->reset();

	return elapsed; 
}

unsigned long GTimer::getTimeElapsed()
{
	return (millis() - m_lastResetMs);
}

