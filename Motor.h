// Motor.h

#ifndef _MOTOR_h
#define _MOTOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
class IMotor {
public:
	virtual void open() = 0;
	virtual void close() = 0;
	virtual void stop() = 0;
	virtual int id() = 0;
};

class dc : public IMotor
{
public:
	dc(int motorID, int pinOpen, int pinClose);
	//dc(int motorID, int pinOpen, int pinClose, int pwm);
	dc() {
		motorID = 0;
		pinOpen = 0;
		pinClose = 0;
	}
	// Copy constructor
	dc(const dc& t)
	{
		motorID = t.motorID;
		pinOpen = t.pinOpen;
		pinClose = t.pinClose;
	}

	//Assignment cunstructor
	dc& operator=(const dc& t)
	{
		motorID = t.motorID;
		pinOpen = t.pinOpen;
		pinClose = t.pinClose;
		return *this;
	}
	void open();
	void close();
	void stop();
	int id();
	void printPins();
private:
	int motorID, pinOpen, pinClose, pwm;

};

#endif

