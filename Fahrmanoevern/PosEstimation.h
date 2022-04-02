/*
 * PosEstimation.h
 *
 *  Created on: 02.04.2022
 *      Author: pi
 */

#ifndef POSESTIMATION_H_
#define POSESTIMATION_H_

class PosEstimation
{
private:
	double x[3];    // position
	double dVelAverage;   //
public:
	PosEstimation();
	void Reset();
	void PredictPosition(double dSpeedR, double dSpeedL, double dTimestep);
	double GetPosition();
};




#endif /* POSESTIMATION_H_ */
