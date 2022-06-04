#include "Arduino.h"
#include "Gtimer.h"


GTimer::GTimer()
{
	this->reset();
}

GTimer::GTimer(int interval)
{
	this->setInterval((unsigned long)interval);
}

GTimer::GTimer(unsigned long interval)
{
	this->setInterval(interval);
}

GTimer::GTimer(int interval, void(*function)())
{
	this->setInterval((unsigned long)interval);
	m_function = function;
}

GTimer::GTimer(unsigned long interval, void(*function)())
{
	this->setInterval(interval);
	m_function = function;
}

void GTimer::setInterval(unsigned long interval)
{
	m_timeoutMs = interval;
	this->reset();
}



void GTimer::attach(void(*function)())
{
	m_function = function;
}

void GTimer::detach()
{
	m_function = nullptr;
}

void GTimer::reset()
{
	m_lastResetMs = millis();
}

bool GTimer::isElapsed(bool resetIfElapsed)
{
	bool elapsed = ((millis() - m_lastResetMs) > m_timeoutMs);

	if (elapsed && resetIfElapsed)
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
	
	if (elapsed && resetIfTriggered)
		this->reset();

	return elapsed; 
}

bool GTimer::update(bool resetIfTriggered /*= true*/)
{
	return this->triggerFunction(resetIfTriggered);
}

unsigned long GTimer::getTimeElapsed()
{
	return (millis() - m_lastResetMs);
}

