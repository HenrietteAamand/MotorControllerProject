#pragma once
struct DTO_config {
	char motortype[15] = "dc";
	int AmountOfMotors = 5;
	float positionUpperLimit = 4;
	float positionLowerLimit = 1.5;
};
