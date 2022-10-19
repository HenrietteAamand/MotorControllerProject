// 
// 
// 

#include "ActionReciever.h"

#include "ActionReciever.h"
ActionReciever_dummy::ActionReciever_dummy()
{
}

ActionReciever_dummy::~ActionReciever_dummy()
{
}

DTO_Action* ActionReciever::getAction()
{
    theDto.actions[0] = open;
    theDto.actions[1] = open;
    theDto.actions[2] = close;
    theDto.actions[3] = close;
    theDto.actions[4] = close;
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
