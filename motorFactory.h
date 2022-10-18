#pragma once
#include "Motor.h"
class motorFactory
{
public:
	dc* createMotor(char motorType[20]);
private:
	dc motor1, motor2, motor3, motor4, motor5;
	dc dcArray[5];
};

