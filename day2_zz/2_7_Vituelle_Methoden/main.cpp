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

//g++ Person.h Person.cpp Student.h Student.cpp main.cpp
int main(){
	Person *p1 = new Person("Merkel", "Angela", 16);
	Person *p2 = new Student("Merkel", "Angela", 16, 3728454);
	p1->sagen();
	p2->sagen();
	delete p1;
	delete p2;
	return 0;
}



