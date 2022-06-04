#pragma once

// Gtimer Library
// non blocking timer library

class GTimer {
public:
	GTimer();
	GTimer(int interval);
	GTimer(unsigned long interval);
	GTimer(int interval, void(*function)());
	GTimer(unsigned long interval, void(*function)());
	void setInterval(unsigned long interval);
	void attach(void(*function)());
	void detach();
	void reset();
	bool isElapsed(bool resetIfElapsed = true);
	bool triggerFunction(bool resetIfTriggered = true);
	bool update(bool resetIfTriggered = true);
	unsigned long getTimeElapsed();


private:
	unsigned long m_lastResetMs;
	unsigned long m_timeoutMs;
	void(*m_function)() = nullptr;
};