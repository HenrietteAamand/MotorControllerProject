#include "MotorControllerClass.h"
#include "Motor.h"
#include "MotorActivator.h"
#include "DTO_action.h"
#include "DTO_config.h"
#include "motorFactory.h"


MotorControllerClass::MotorControllerClass()
{
	
}

void MotorControllerClass::setupProgram()
{
	readConfigfile();
	ma.setMotorArray(createMotors());
	posLowLim = configurations.positionLowerLimit;
	posUpLim = configurations.positionUpperLimit;
}

void MotorControllerClass::startFlow()
{
	Serial.println("Entered StartFlow()");
	while (true) {
		if (ar.hasRevievedAction()) {
			currentAction = ar.getAction();
			activeMotors = ma.controllMotors(currentAction);
		}
		if (stopActiveMotors()) {
			activeMotors = ma.controllMotors(currentAction);
		}
	}
}

dc* MotorControllerClass::createMotors()
{
	return mf.createMotor("dc"); //OBS! Skal �ndres til en parameter fra confic_DTO
}

void MotorControllerClass::readConfigfile()
{
	//configurations = DTO_confic;
}

bool MotorControllerClass::stopActiveMotors()
{
	bool stopMotors = false;
	for (int i = 0; i<sizeof(activeMotors); i++) {
		if (activeMotors[i] == 1) {					// == 1 : hvis motoren er aktiv (�bner eller lukker)
			float position = pm.getPosition(i);		// Afl�ser positionsv�rdien
			if (position >= posUpLim || position <= posLowLim)		// >= posUpLim || <= posLowLim: hvis positionen af potentimetret overskrider gr�nserne
				currentAction->actions[i] = stop;					// s�t action til stop for den motor der er over dens gr�nse
			stopMotors = true;								// siger at der er en motor der skal stoppes
		}
	}
	return stopMotors;
}
