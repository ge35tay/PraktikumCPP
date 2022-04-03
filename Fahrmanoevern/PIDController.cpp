/*
 * PIDController.cpp
 *
 *  Created on: 02.04.2022
 *      Author: Yinghan Huang
 */
#include "PIDController.h"

PIDController::PIDController(double Kp, double Ki, double Kd, double Ta){
	dKp = Kp;
	dKi = Ki;
	dKd = Kd;
	dTa = Ta;
	dEsum = 0;
	dU = 0;
	deold = 0;
}

void PIDController::CalculateU(double dW, double dY){
	dU = dKp*(dW - dY) + dKi*dEsum + dKd*(dW -dY -deold)/dTa;
	dEsum += dW -dY;
	deold = dW- dY;
}

double PIDController::GetU(){
	return dU;
}
