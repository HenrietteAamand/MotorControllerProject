#include "MotorFactory.h"


dc* MotorFactory::createMotor(String motorType)
{
    if (motorType == "dc") {
        createDC();
    }

    return dcArray;
}

void MotorFactory::createDC() {
    dcArray[0] = dc(1, 2, 3);
    dcArray[1] = dc(2, 4, 5);
    dcArray[2] = dc(3, 6, 7);
    dcArray[3] = dc(4, 8, 9);
    dcArray[4] = dc(5, 10, 11);
}
