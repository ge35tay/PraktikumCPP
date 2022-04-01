/**
 * @file Person.cpp
 * @author Yinghan Huang 03728454 and Zhishen Zhang 03736826
 * @brief 
 * @version 0.1
 * @date 2022-04-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include "Person.h"

Person::Person(std::string sName, std::string sSurname, int iAge){
	m_sName = sName;
	m_sSurname = sSurname;
	m_iAge = iAge;
}

 std::string Person::getName(){
	 return m_sName;
 }

std::string Person::getSurname(){
	return m_sSurname;
}

int Person::getAge(){
	return m_iAge;
}

bool Person::setAge(int iAge){
	m_iAge = iAge;
	return true;
}

void Person::sagen(){
	std::cout<<"Ich bin ein Mensch."<<std::endl;
};