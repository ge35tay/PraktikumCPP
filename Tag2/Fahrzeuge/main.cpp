/*
 * main.cpp
 *
 *  Created on: 29.03.2022
 *      Author: Yinghan Huang
 */

#include "vehicle.h"
#include <string>
#include <iostream>

int main(){
	vehicle auto1(40000, 1979, vehicle::Rot);
	auto1.getFarbe();
	std::cout << auto1.getBaujahr() << '\n'<< std::endl;
	std::cout << auto1.getID() << '\n'<< std::endl;
	std::cout << auto1.getPreis() << '\n'<< std::endl;
	auto1.isOLdtimer();
}


