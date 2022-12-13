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
		//if (id < 2) {
		//	Serial.print(String(id+1));
		//	Serial.println(": " + String(positionInVolt) + "V");
		//}
	}
	return positionInVolt;
}

void PositionMonitor::printString(String inputString)
{
	Serial.println(inputString);
}
