/*
 * Maneuver.h
 *
 *  Created on: 03.04.2022
 *      Author: Yinghan Huang
 */
// g++ PIDController.h PIDController.cpp Maneuver.h Maneuver.cpp PosEstimation.h PosEstimation.cpp RobotControl.h RobotControl.cpp main.cpp
#ifndef ROBOTCONTROL_ 
#define ROBOTCONTROL_

#include <iostream>
#include <cmath>
#include <list>
#include <string>
#include "InterfaceSIM.h"
#include "Maneuver.h"
#include "PosEstimation.h"
#include "PIDController.h"

class RobotControl
{
private:
	InterfaceSIM interface;
	Maneuver maneuver;
	PosEstimation posEstimation;
	PIDController motorR;
	PIDController motorL;
	bool bIsActive;

public:
	RobotControl();
	~RobotControl(){};
	static RobotControl* transferPointer();
	static void transferFunction();
	bool isActive();
	void Step();
	void Communicate();

};


#endif /* ROBOTCONTROL_ */
