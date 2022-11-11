#pragma once
#include "Motor.h"
class MotorFactory
{
public:
	dc* createMotor(String type);
private:
	void createDC();
	dc dcArray[5];
};

