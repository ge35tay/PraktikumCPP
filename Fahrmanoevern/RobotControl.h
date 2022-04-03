/**
 * @file RobotControl.h
 * @author Yinghan Huang and Zhishen Zhang
 * @brief 
 * @version 0.1
 * @date 2022-04-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef ROBOTCONTROL_ 
#define ROBOTCONTROL_

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
	PIDController motorR = PIDController(500,100,0,0.4);
	PIDController motorL = PIDController(500,100,0,0.4);
	bool bIsActive;
	int iMicros[2];
	double current_speed[2];
	double timeStep = 0.04;


public:
	RobotControl();
	~RobotControl(){};
	static RobotControl* transferPointer;
	static void transferFunction();
	bool isActive();
	void Step();
	void Communicate();

};


#endif /* ROBOTCONTROL_ */
