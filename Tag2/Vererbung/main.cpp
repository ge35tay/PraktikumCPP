/*
 * main.cpp
 *
 *  Created on: 29.03.2022
 *      Author: Yinghan Huang
 */

#include "Person.h"
#include "Student.h"
#include <iostream>


int main(){
	Person per1("Merkel", "Angela", 16);
	Student stu1("Merkel", "Angela", 16, 3728454);
	std::cout << per1.getName() << '\n';
	std::cout << stu1.getName();
}



