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

#include "Quadrate.h"
#include <iostream>



int main(){
	//const square s1(1.2);
	square s1 = square(1.23);
	square s2 = square(s1);
	square s3 = s1 + s2;
	std::cout << s3 << std::endl;
	return 0;
	return 0;
}
