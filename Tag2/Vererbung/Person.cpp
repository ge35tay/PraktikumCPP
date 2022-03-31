/*
 * Person.cpp
 *
 *  Created on: 29.03.2022
 *      Author: Yinghan Huang
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

