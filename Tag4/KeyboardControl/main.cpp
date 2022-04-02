/*
 * main.cpp
 *
 *  Created on: 01.04.2022
 *      Author: Yinghan Huang
 */

#include <cmath>
#include "ncurses.h"
#include "KeyboardControl.h"
#include "InterfaceSIM.h"


int main(){

	std::cout<<"Wellcome on board!\n"
	<<"Press the W key to drive forward\n"
	<<"Press the S key to drive backwards\n"
	<<"Press the A key to turn left\n"
	<<"Press the D key to turn righ\n"
	<<std::endl;


	KeyboardControl key;
	key.Communicate();
	return 0;
}


