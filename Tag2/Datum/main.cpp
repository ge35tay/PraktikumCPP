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
	Date d1 = Date(2,2,2011);
	// d1.m_day = 15;    privacy
	Date d2 = Date(15, 2, 2011);
	bool tf = d2.isEqual(d1);
	std::cout << tf;
	return 0;
}


