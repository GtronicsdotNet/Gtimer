#pragma once

// Gtimer Library
// non blocking timer library

class GTimer {
public:
	void setInterval(unsigned long interval);
	void attach(void(*function)());
	void reset();
	bool isElapsed(bool resetIfElapsed = true);
	bool triggerFunction(bool resetIfTriggered = true);
	unsigned long getTimeElapsed();


private:
	unsigned long m_lastResetMs;
	unsigned long m_timeoutMs;
	void(*m_function)() = nullptr;
};