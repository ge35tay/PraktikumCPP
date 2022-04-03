/*
 * PosEstimation.h
 *
 *  Created on: 02.04.2022
 *      Author: pi
 */

#ifndef POSESTIMATION_H_
#define POSESTIMATION_H_

#include <cmath>
#include "iostream"

class PosEstimation
{
private:
	double x[3];    // position
	double dVelAverage;   // mittleren Geschwindigkeit, constant in einen interval T.
	double T;       // Zeitschrittlänge
public:
	PosEstimation();
	~PosEstimation();
	void Reset();    //Koordinatenursprung zurückgesetzt
	void PredictPosition(double dSpeedR, double dSpeedL, double dTimestep);   // die Aktuelle Position und die Raumrichtung
	double * GetPosition();      // Addresse des Ergebnisarrays zurück, x,y positionen und aktuelle Winkel
};




#endif /* POSESTIMATION_H_ */
