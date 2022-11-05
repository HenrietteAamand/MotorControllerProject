#include "MotorActivator.h"
#include "DTO_action.h"

MotorActivator::MotorActivator (){}

void MotorActivator::setMotorArray(dc *motorArr) // OBS!
{
	availableMotors = motorArr;
}

int* MotorActivator::controllMotors(DTO_Action *currentAction)
{
	for (int i = 0; i < 5; i++) {
		activateMotor(i, currentAction->actions[i]);
	}
	return activeMotorsID; 
}

ActionEnum MotorActivator::activateMotor(int motor_i, ActionEnum motorAction)
{
	//(availableMotors + motor_i)->printPins();
	if (motorAction == na) {
		return na;
	}
	if (motorAction == open) {
		(availableMotors+motor_i)->open(); //på plads (availableMotors+motor_i) i hukommelsen
		activeMotorsID[(availableMotors + motor_i)->id() - 1] = 1; //Sat til 1 = aktiv, sat til 0 = slukket
		return open;
	}
	if (motorAction == close) {
		(availableMotors + motor_i)->close();
		activeMotorsID[(availableMotors + motor_i)->id() - 1] = 1;
		return close;
	}
	if (motorAction == stop) {
		(availableMotors + motor_i)->stop();
		activeMotorsID[(availableMotors + motor_i)->id() - 1] = 0;
		return stop;
	}
}
