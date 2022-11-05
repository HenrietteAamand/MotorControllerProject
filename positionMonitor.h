// positionMonitor.h

#ifndef _POSITIONMONITOR_h
#define _POSITIONMONITOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#endif

class IPositionMonitor {
public:
	virtual float getPosition(int monitorId) = 0;
};

class PositionMonitor: public IPositionMonitor {
public: 
	PositionMonitor();
	float getPosition(int monitorID);
private:
	int posIDArray[5] = {A1, A2, A3, A4, A5 };
};

