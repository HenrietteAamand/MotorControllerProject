#include "motorFactory.h"


dc* motorFactory::createMotor(char motorType[20])
{
    if (motorType == "dc") {
        motor1 = dc(1, 2, 3);
        motor2 = dc(2, 4, 5);
        motor3 = dc(3, 6, 7);
        motor4 = dc(4, 8, 9);
        motor5 = dc(5, 10, 12);
        //motor1 = dc(1, 2, 3, 50);
        //motor2 = dc(2, 4, 5, 100);
        //motor3 = dc(3, 6, 7, 100);
        //motor4 = dc(4, 8, 9, 100);
        //motor5 = dc(5, 10, 12, 100);
    }
    dcArray[0] = motor1;
    dcArray[1] = motor2;
    dcArray[2] = motor3;
    dcArray[3] = motor4;
    dcArray[4] = motor5;
    return dcArray;
}
