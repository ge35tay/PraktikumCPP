/*
 * PIDController.h
 *
 *  Created on: 02.04.2022
 *      Author: pi
 */

#ifndef PIDCONTROLLER_H_
#define PIDCONTROLLER_H_

class PIDController
{
private:
	double dKp;
	double dKi;
	double dKd;
	double dTa;
	double dEsum;
	double deold;
	double dU;
public:
	PIDController(double Kp, double Ki, double Kd, double Ta);
	void CalculateU(double dW, double dY);
	double GetU();
};



#endif /* PIDCONTROLLER_H_ */
