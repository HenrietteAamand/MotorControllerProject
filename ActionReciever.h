// ActionReciever.h

#ifndef _ACTIONRECIEVER_h
#define _ACTIONRECIEVER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "DTO_action.h"
class IActionReciever {
public:
	virtual DTO_Action* getAction() = 0;
	virtual bool hasRevievedAction() = 0;
};

class ActionReciever : public IActionReciever {
public:
	ActionReciever();
	~ActionReciever();
	DTO_Action* getAction();
	bool hasRevievedAction();
private:
	ActionEnum convertStringToEnum();
	DTO_Action recievedActions;
	String serialisedAction = "";
	String motorActionAsString = "";
	int motorID = 9;
};

//class ActionReciever_dummy : public IActionReciever {
//public:
//	ActionReciever_dummy();
//	~ActionReciever_dummy();
//	DTO_Action* getAction();
//	bool hasRevievedAction();
//private:
//	DTO_Action recievedActions;
//
//};



#endif

