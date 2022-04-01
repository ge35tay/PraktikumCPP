/**
 * @file main.cpp
 * @author Yinghan Huang 03728454 and Zhishen Zhang 03736826
 * @brief 
 * @version 0.1
 * @date 2022-04-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "vehicle.h"
#include <string>
#include <iostream>

int main(){
	vehicle auto1(40000, 1979, vehicle::Rot);
	vehicle auto2(50000, 2000, vehicle::Blau);
	std::cout <<"auto1 ist: "<< auto1.getFarbe()<< std::endl;
	std::cout <<"Baujahr auto 1: "<< auto1.getBaujahr()<< std::endl;
	std::cout << "ID Auto 1: "<<auto1.getID()<< std::endl;
	std::cout << "ID Auto 2: "<<auto2.getID()<< std::endl;
	std::cout << "Preis Auto 1: "<< auto1.getPreis()<< std::endl;
	auto1.isOLdtimer(auto1);
	return 0;
}


