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
    theDto.actions[1] = open;
    theDto.actions[2] = close;
    theDto.actions[3] = close;
    theDto.actions[4] = close;
    return &theDto;
}

bool ActionReciever::hasRevievedAction()
{
    
    if(Serial.available() > 0)
    {
        return true;
    }
    else
        return false;
}


