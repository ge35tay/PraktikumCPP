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

#include "Person.h"
#include "Student.h"
#include <iostream>


int main(){
	Person per1("Merkel", "Angela", 16);
	Student stu1("Merkel", "Angela", 16, 3728454);
	std::cout << per1.getName() << '\n';
	std::cout << stu1.getName();
	return;
}



