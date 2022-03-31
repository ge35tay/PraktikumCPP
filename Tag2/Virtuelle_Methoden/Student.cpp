/*
 * Student.cpp
 *
 *  Created on: 29.03.2022
 *      Author: Yinghan Huang
 */

#include "Student.h"
#include "Person.h"
#include <iostream>
#include <string>

Student::Student(std::string sName, std::string sSurname, int iAge, unsigned int uiStudentID):Person(sName, sSurname, iAge){
	m_uiStudentID = uiStudentID;
}

unsigned int Student::getStudentID(){
	return m_uiStudentID;
}

std::string Student::getName(){
	return ("Student " + Person::getName());
}
