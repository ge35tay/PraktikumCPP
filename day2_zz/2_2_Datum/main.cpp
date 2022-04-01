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

#include "Date.h"   // need include Date.h
#include <iostream>
int main()
{

	Date d1 = Date(2,2,2011);
	// d1.m_day = 15; //private variable can not be accessed,
	Date d2 = Date(15,2,2011);
	bool tf = d2.isEqual(d1);
	printf("The statement assertion is: %s\n", tf ? "true" : "false");
	return 0;

}


