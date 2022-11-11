// 
// 
// 

#include "positionMonitor.h"

PositionMonitor::PositionMonitor()
{
	pinMode(12, OUTPUT);
	digitalWrite(12, HIGH);
}

float PositionMonitor::getPosition(int id)
{
	float positionInVolt = 3.0;
	if (id < 5){
		int positionInBits = analogRead(posIDArray[id]);
		positionInVolt = ((5.0 / 1023.0) * positionInBits);
		//Serial.println(positionInVolt);
	}
	//return positionInVolt;
	return 3.0;
}
