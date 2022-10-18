#pragma once
struct DTO_config {
	char motortype[15] = "dc";
	int AmountOfMotors = 5;
	float positionUpperLimit = 5.0;
	float positionLowerLimit = 0.2;
};
