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
}

void MotorControllerClass::startFlow()
{
	DTO_Action tempDTO = DTO_Action();
	activeMotors = ma.controllMotors(&tempDTO);
	while (true) {
		if (ar.hasRevievedAction()) {
			DTO_Action *tempActionDTO = ar.getAction();
			activeMotors = ma.controllMotors(tempActionDTO);
		}
	}
	// tjek positionssensorerne
}

dc* MotorControllerClass::createMotors()
{
	return mf.createMotor("dc"); //OBS! Skal ændres til en parameter fra confic_DTO
}

void MotorControllerClass::readConfigfile()
{
	//configurations = DTO_confic;
}

bool MotorControllerClass::stopActiveMotors()
{
	return false;
}
