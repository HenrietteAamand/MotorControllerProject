#pragma once
#include "Motor.h"
#include "DTO_action.h"
class IMotorActivator {
public:
    virtual void setMotorArray(dc motorArr[5]) = 0; // OBS!
    virtual int* controllMotors(DTO_Action *currentAction) = 0;
};

class MotorActivator : public IMotorActivator
{
public:
    MotorActivator();
    void setMotorArray(dc motorArr[5]); // OBS!
    int* controllMotors(DTO_Action *currentAction); // OBS!
private:
    ActionEnum activateMotor(int motor_i, ActionEnum motorAction);
    dc* availableMotors; // OBS! OG pointer der holder pladsen for det første element i arrayet i hukommelsen
    int* activeMotorsID;
};

