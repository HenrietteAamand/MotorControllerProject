/*
 Name:		MotorControllerProject.ino
 Created:	10/13/2022 4:13:58 PM
 Author:	henri
*/

// the setup function runs once when you press reset or power the board
//#include "Motor.h"
//#include "MotorActivator.h"
//#include "DTO_action.h"
#include "MotorControllerClass.h"


//DTO_Action myDTO;
//MotorActivator ma;

MotorControllerClass mcc;
void setup() {
	Serial.begin(9600);
	mcc.setupProgram();	
	
	//// Test 1 Setup
	//ma = MotorActivator();
	//dc dcArray[5] = {dc23, dc45, dc67, dc89, dc1011}; 
	//ma.setMotorArray(dcArray);
	//myDTO.actions[0] = close;
	//myDTO.actions[1] = close;
	//myDTO.actions[2] = close;
	//myDTO.actions[3] = close;
	//myDTO.actions[4] = na;
	//Serial.println("START");
}

// the loop function runs over and over again until power down or reset
void loop() {	
	
	// Test 2 - MotorControllerClass
	mcc.startFlow();

	//// Test 1 - MotorActivator
	//for (int i = 0; i < 5; i++) {
	//	myDTO.actions[0] = open;
	//	ma.controllMotors(myDTO);
	//	delay(1000);
	//	myDTO.actions[1] = open;
	//	ma.controllMotors(myDTO);
	//	delay(1000);
	//	myDTO.actions[2] = open;
	//	ma.controllMotors(myDTO);
	//	delay(1000);
	//	myDTO.actions[3] = open;
	//	ma.controllMotors(myDTO);
	//	delay(1000);
	//	myDTO.actions[0] = close;
	//	ma.controllMotors(myDTO);
	//	delay(1000);
	//	myDTO.actions[1] = close;
	//	ma.controllMotors(myDTO);
	//	delay(1000);
	//	myDTO.actions[2] = close;
	//	ma.controllMotors(myDTO);
	//	delay(1000);
	//	myDTO.actions[3] = close;
	//	ma.controllMotors(myDTO);
	//	delay(1000);
	// 	myDTO.actions[0] = stop;
	//	ma.controllMotors(myDTO);
	//	delay(1000);
	//	myDTO.actions[1] = stop;
	//	ma.controllMotors(myDTO);
	//	delay(1000);
	//	myDTO.actions[2] = stop;
	//	ma.controllMotors(myDTO);
	//	delay(1000);
	//	myDTO.actions[3] = stop;
	//	ma.controllMotors(myDTO);
	//	delay(1000);
	//}

}
