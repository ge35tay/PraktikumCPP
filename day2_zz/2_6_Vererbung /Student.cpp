/**
 * @file Student.cpp
 * @author Yinghan Huang 03728454 and Zhishen Zhang 03736826
 * @brief 
 * @version 0.1
 * @date 2022-04-01
 * 
 * @copyright Copyright (c) 2022
 * 
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

