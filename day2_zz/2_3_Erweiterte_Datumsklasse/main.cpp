/*
 * main.cpp
 *
 *  Created on: 29.03.2022
 *      Author: Yinghan Huang
 */
#include "Date.h"   // need include Date.h
#include <iostream>
int main()
{
	Date d1;
	// d1.m_day = 15;    privacy
	Date d2 = Date(15, 2, 2011);
	
	std::cout<<"d1: "<<d1.getYear()<<"\t: "<<d1.getMonth()<<"\t: "<<d1.getDay()<<std::endl;
	std::cout<<"d2: "<<d2.getYear()<<"\t: "<<d2.getMonth()<<"\t: "<<d2.getDay()<<std::endl;
	bool tf = d2.isEqual(d1);
	int comp = d1.compare(d2);
	std::cout << tf << '\n';
	std::cout << comp<<std::endl;
	return 0;
}


