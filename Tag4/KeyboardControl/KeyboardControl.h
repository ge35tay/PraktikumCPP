/*
 * KeyboardControl.h
 *
 *  Created on: 31.03.2022
 *      Author: Yinghan Huang
 */

#include "InterfaceSIM.h"
#include "PIDController.h"
#include "ncurses.h"
#include <iostream>
#include <list>


#ifndef KEYBOARDCONTROL_H_
#define KEYBOARDCONTROL_H_


class KeyboardControl
{
public:
	KeyboardControl();
	~KeyboardControl(){};
	void Communicate();
	void Step();
	static void transferFunction();
	static KeyboardControl* transferPointer;
private:
	// Linke Seite 1, rechte Seite 0
	double SollGeschwindigkeit[2] = {0, 0};
	double IstGeschwindigkeit[2] = {0, 0};
	InterfaceSIM interface;
	int Sollwert[2];
	int counter = 0;
	PIDController Regeler1 = PIDController(1000.0, 12.0, 0.1, 0.5);
	PIDController Regeler2 = PIDController(1000.0, 12.0, 0.1, 0.5);
};



#endif /* KEYBOARDCONTROL_H_ */
