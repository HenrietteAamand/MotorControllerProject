// 
// 
// 

#include "ActionReciever.h"
ActionReciever::ActionReciever()
{
}

ActionReciever::~ActionReciever()
{
}

DTO_Action* ActionReciever::getAction()
{
    theDto.actions[0] = open;
    theDto.actions[0] = open;
    theDto.actions[0] = close;
    theDto.actions[0] = close;
    theDto.actions[0] = close;
    return &theDto;
}

bool ActionReciever::hasRevievedAction()
{
    return true;
    /*if (Serial.available() > 0)
    {
        return true;
    }
    else
        return false;*/
}


