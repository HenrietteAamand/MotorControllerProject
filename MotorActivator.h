#pragma once
#include "Motor.h"
#include "DTO_action.h"
class IMotorActivator {
public:
    virtual void setMotorArray(dc motorArr[5]) = 0;
    virtual void controllMotors(DTO_Action *currentAction) = 0;
};

class MotorActivator : public IMotorActivator
{
public:
    MotorActivator();
    void setMotorArray(dc* motorArr);
    void controllMotors(DTO_Action *currentAction);
private:
    void activateMotor(int motor_i, ActionEnum motorAction);
    dc* availableMotors;
};

