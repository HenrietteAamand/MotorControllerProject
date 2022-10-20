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
    // sytax af det serialiserede objekt "[1:open][2:close][3:na][4:open][5:open]": 
    serialisedAction = Serial.readStringUntil('>');
    motorActionAsString = "";
    motorID = 0;
    for(char letter : serialisedAction)
    {
        if (letter == ',') {
            motorID = motorActionAsString[0] - '0';
            recievedActions.actions[motorID-1] = convertStringToEnum();
            motorActionAsString = "";
        }
        else{
            motorActionAsString = motorActionAsString + letter;
        }
    }

    return &recievedActions;
}

bool ActionReciever::hasRevievedAction()
{
    if(Serial.available()>0)
    {
        digitalWrite(2, HIGH);
        return true;
    }
    else
        return false;
}

ActionEnum ActionReciever::convertStringToEnum() {
    if (motorActionAsString.substring(2) == "o") {
        //Serial.println("returned open"); //debug
        return open;
    }
    if (motorActionAsString.substring(2) == "c") {
        //Serial.println("returned close"); //debug
        return close;
    }
    if (motorActionAsString.substring(2) == "s") {
        //Serial.println("returned stop"); //debug
        return stop;
    }
    if (motorActionAsString.substring(2) == "n") {
        //Serial.println("returned na"); //debug
        return na;
    }
}

