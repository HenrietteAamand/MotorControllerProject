// 
// 
// 

#include "ActionReciever.h"
ActionReciever::ActionReciever(){}

ActionReciever::~ActionReciever(){}

DTO_Action* ActionReciever::getAction()
{
    // sytax af det serialiserede objekt "1:o,2:c,3:n,4:o,5:o>": 
    String serialisedAction = Serial.readStringUntil('>');
    String motorActionAsString = "";
    int motorIndex = 0;
    for(char letter : serialisedAction) {
        if(letter != ',') {
            motorActionAsString = motorActionAsString + letter; 
        }
        else if (letter == ',') {
            motorIndex = motorActionAsString[0] - '1';
            if (motorIndex <= 5) {
                recievedActions.actions[motorIndex] = convertStringToEnum(&motorActionAsString);
                motorActionAsString = "";
            }
        }
    }
    
    return &recievedActions;
}

bool ActionReciever::hasRevievedAction()
{   
    return Serial.available() > 0;
}

ActionEnum ActionReciever::convertStringToEnum(String *actionAsString) {
    ActionEnum enumToReturn;
    if (actionAsString->substring(2) == "o") {
        //Serial.println("returned open"); //debug
        enumToReturn = open;
    }
    else if (actionAsString->substring(2) == "c") {
        //Serial.println("returned close"); //debug
        enumToReturn = close;
    }
    else if (actionAsString->substring(2) == "s") {
        //Serial.println("returned stop"); //debug
        enumToReturn = stop;
    }
    else {
        //Serial.println("returned na"); //debug
        enumToReturn = na;
    }
    return enumToReturn;
}
