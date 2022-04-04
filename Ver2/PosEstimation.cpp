/*
 * PosEstimation.cpp
 *
 *  Created on: 02.04.2022
 *      Author: Yinghan Huang
 */

#include "PosEstimation.h"
#include "string.h"

PosEstimation::PosEstimation(){
	memset(x, 0, sizeof(x));
	dVelAverage = 0;
}

PosEstimation::~PosEstimation(){}

void PosEstimation::Reset(){
	memset(x, 0, sizeof(x));
	dVelAverage = 0;
}


void PosEstimation::PredictPosition(double SpeedR, double SpeedL, double Timestep)
{
	T = Timestep;
	x[0] += T * dVelAverage * cos(x[2]);
	x[1] +=  T * dVelAverage * sin(x[2]);
	x[2] +=  T * (SpeedR - SpeedL)/0.23;
	x[2] = fmod(x[2], 2 * M_PI);
	if (x[2] > M_PI){
		x[2] -= 2 * M_PI;
	}
	else if(x[2] < -M_PI){
		x[2] += 2 * M_PI;
	}
	dVelAverage = (SpeedR + SpeedL)/2;
}

double * PosEstimation::GetPosition(){
	double *a = x;
	return a;
}
