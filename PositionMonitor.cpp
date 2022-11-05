// 
// 
// 

#include "positionMonitor.h"

PositionMonitor::PositionMonitor()
{
	pinMode(12, OUTPUT);
	digitalWrite(12, HIGH);
	Serial.println("enterede ctor in PM");
}

float PositionMonitor::getPosition(int id)
{
	int positionInBits = analogRead(posIDArray[id]);
	Serial.println(positionInBits);
	return ((5.0 / 1023.0) * positionInBits);
}
