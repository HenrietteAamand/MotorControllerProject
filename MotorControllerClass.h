#pragma once
#include "Motor.h"
#include "MotorActivator.h"
#include "DTO_action.h"
#include "DTO_config.h"
#include "motorFactory.h"
#include "ActionReciever.h"
#include "positionMonitor.h"
class MotorControllerClass
{
public:
    MotorControllerClass();
    void setupProgram();
    void startFlow();
private:
    bool positionLimitsExeeded_CorrectAction();
    DTO_Action *currentAction;
    DTO_config configurations;
    MotorFactory motorFactory = MotorFactory();
    MotorActivator motorActivator = MotorActivator();
    //IMotorActivator* motorActivator = &MotorActivator();
    PositionMonitor postitionMonitor = PositionMonitor();
    ActionReciever actionReciever = ActionReciever();
    float posUpLim, posLowLim;
    //ActionReciever_dummy ar = ActionReciever_dummy();
};