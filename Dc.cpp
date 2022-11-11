// 
// 
// 

#include "Motor.h"

dc::dc(int _motorID, int _pinOpen, int _pinClose)
{
	motorIndex = _motorID;
	pinOpen = _pinOpen;
	pinClose = _pinClose;
	pinMode(pinOpen, OUTPUT);
	pinMode(pinClose, OUTPUT);
}


void dc::open()
{
	digitalWrite(pinOpen, HIGH);
	digitalWrite(pinClose, LOW);
}

void dc::close()
{
	digitalWrite(pinOpen, LOW);
	digitalWrite(pinClose, HIGH);
}

void dc::stop()
{
	digitalWrite(pinOpen, LOW);
	digitalWrite(pinClose, LOW);
}

int dc::id()
{
	return motorIndex;
}

void dc::printPins()
{
	Serial.print("Motor with ID: ");
	Serial.print(motorIndex);
	Serial.print(" uses pin ");
	Serial.print(pinOpen);
	Serial.print(" as openPin and ");
	Serial.print(pinClose);
	Serial.println(" as closePin");
}

