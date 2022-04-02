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
	KeyboardControl key;
	key.Communicate();
	return 0;
}


