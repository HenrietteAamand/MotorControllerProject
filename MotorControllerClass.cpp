#include "MotorControllerClass.h"
#include "Motor.h"
#include "MotorActivator.h"
#include "DTO_action.h"
#include "DTO_config.h"
#include "motorFactory.h"


MotorControllerClass::MotorControllerClass(){}

void MotorControllerClass::setupProgram()
{
	motorActivator.setMotorArray(motorFactory.createMotor(configurations.motortype));
	posLowLim = configurations.positionLowerLimit;
	posUpLim = configurations.positionUpperLimit;
}

void MotorControllerClass::startFlow()
{
	while (true) {
		if (actionReciever.hasRevievedAction()) {
			currentAction = actionReciever.getAction();
			positionLimitsExeeded_CorrectAction();
			motorActivator.controllMotors(currentAction);
		}
		if (positionLimitsExeeded_CorrectAction()) {
			motorActivator.controllMotors(currentAction);
		}
	}
}

bool MotorControllerClass::positionLimitsExeeded_CorrectAction()
{
	bool stopMotors = false;
	float position = 0.0;
	for (int i = 0; i<5; ++i) {
		ActionEnum* action = &currentAction->actions[i];
		if (*action == open || *action == close) {
			position = postitionMonitor.getPosition(i);							// Aflæser positionsværdien
			if (position >= posUpLim && *action == open) {	// >= posUpLim || <= posLowLim: hvis positionen af potentimetret overskrider grænserne
				currentAction->actions[i] = stop;								// sæt action til stop for den motor der er over dens grænse
				//postitionMonitor.printString("position: " + String(position) + " is over limit for potentiometer " + String(i + 1) + ", STOP"); // Debug
				stopMotors = true;												// siger at der er en motor der skal stoppes
			}
			else if (position <= posLowLim && *action == close) {	// >= posUpLim || <= posLowLim: hvis positionen af potentimetret overskrider grænserne
				currentAction->actions[i] = stop;									// sæt action til stop for den motor der er over dens grænse
				//postitionMonitor.printString("position: " + String(position) + " is under limit for potentiometer " + String(i + 1) + ", STOP"); // Debug
				stopMotors = true;													// siger at der er en motor der skal stoppes
			}
		}
	}
	return stopMotors;
}
