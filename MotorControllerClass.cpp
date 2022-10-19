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
	while (true) {
		if (ar.hasRevievedAction()) {
			Serial.println("mcc in void startFlow() at line 24, ar.hasRecievedAction == true");
			Serial.println("mcc in void startFlow() at line 24, ar.hasRecievedAction == true");
			DTO_Action *tempActionDTO = ar.getAction();
			activeMotors = ma.controllMotors(tempActionDTO);
		}
		else {
			Serial.println("mcc in void startFlow() at line 29, ar.hasRecievedAction == false");
		}
		delay(10000);
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
