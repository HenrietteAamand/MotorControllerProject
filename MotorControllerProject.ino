/*
 Name:		MotorControllerProject.ino
 Created:	10/13/2022 4:13:58 PM
 Author:	henri
*/

// the setup function runs once when you press reset or power the board
//#include "Motor.h"
//#include "MotorActivator.h"
//#include "DTO_action.h"
#include "ActionReciever_dummy.h"
#include "MotorControllerClass.h"


//DTO_Action myDTO;
//dc dc23(1, 2, 3);
//dc dc45(2, 4, 5);
//dc dc67(3, 6, 7);
//dc dc89(4, 8, 9);
//dc dc1011(5, 10, 11);
//MotorActivator ma;
MotorControllerClass mcc;
#include "ActionReciever.h"
int pwm_pin = 11;
void setup() {
	Serial.begin(9600);
	mcc.setupProgram();
	pinMode(pwm_pin, OUTPUT);
	//ma = MotorActivator();
	//dc dcArray[5] = {dc23, dc45, dc67, dc89, dc1011}; // OBS!
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
	////Fading the LED
	//for (int n = 0; n < 10; n++) {
	//	for (int i = 0; i < 255; i++) {
	//		analogWrite(pwm_pin, i);
	//		delay(5);
	//	}
	//	for (int i = 255; i > 0; i--) {
	//		analogWrite(pwm_pin, i);
	//		delay(5);
	//	}
	//}
	// Test 3 - MotorControllerClass
	//Serial.println(".ino in void loop line 41");
	analogWrite(pwm_pin, 100);
	mcc.startFlow();

	//// Test 2 - MotorActivator
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
	//}

	// Test kun motor
	/*dc23.open();
	dc45.close();
	delay(3000);
	dc23.close();
	dc45.open();
	delay(3000);*/
}
