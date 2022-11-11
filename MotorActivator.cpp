#include "MotorActivator.h"
#include "DTO_action.h"

MotorActivator::MotorActivator (){}

void MotorActivator::setMotorArray(dc *motorArr) 
{
	availableMotors = motorArr;
}

void MotorActivator::controllMotors(DTO_Action *currentAction)
{
	for (int i = 0; i < 5; ++i) {
		activateMotor(i, currentAction->actions[i]);
	} 
}

void MotorActivator::activateMotor(int motor_i, ActionEnum motorAction)
{
	dc* motor = (availableMotors + motor_i); //på plads (availableMotors+motor_i) i hukommelsen
	if (motorAction == open) {
		motor->open(); 
	}
	else if (motorAction == close) {
		motor->close();
	}
	else if (motorAction == stop) {
		motor->stop();
	}
}
