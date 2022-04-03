/*
 * Maneuver.h
 *
 *  Created on: 03.04.2022
 *      Author: Yinghan Huang
 */

#ifndef MANEUVER_H_
#define MANEUVER_H_

#include <iostream>
#include <cmath>
#include <list>
#include <string>

class Maneuver
{
private:
	struct Coord
	{
		double dX;
		double dY;
		double dV;
		Coord(double X, double Y, double V)
		{
			dX = X;
			dY = Y;
			dV = v;
		}
	};                                  // Coord: X,Y,V

	std::list<Coord> Coordlist;         // save the coord
	std::list<Coord>::iterator iter;
	bool blsRunning;					// to see if the robot is running
	double adWishSpeed[2];				// Expected Speed, sum of rotation part and translation part.
	double dMaxSpeed;
	double dPosDifference;              // difference from true value

public:
	Maneuver();
	~Maneuver(){};
	void CalcCircle(double dRadius, double dSpeed, double dTimestep);
	void CalcEight(double dRadius, double dSpeed, double dTimestep);
	void Loglist(std::string sDatei);                                         // the generated Koord is saved in a Log-Date
	bool isRunning();
	void start();
	void stop();
	void Proceed();
	void CalcManeuverSpeed(double dX, double dY, double dW);
	double * GetManeuverSpeed();
};


#endif /* MANEUVER_H_ */
