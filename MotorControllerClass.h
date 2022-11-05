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
    dc* createMotors();
    void readConfigfile();
    bool stopActiveMotors();
    int* activeMotors;
    float* positions;
    DTO_Action *currentAction;
    DTO_config configurations;
    motorFactory mf = motorFactory();
    //IMotorActivator *ma = new MotorActivator();
    MotorActivator ma = MotorActivator();
    PositionMonitor pm = PositionMonitor();
    ActionReciever ar = ActionReciever();
    float posUpLim, posLowLim;
    //ActionReciever_dummy ar = ActionReciever_dummy();
};