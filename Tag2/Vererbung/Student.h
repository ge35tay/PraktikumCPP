/*
 * Student.h
 *
 *  Created on: 29.03.2022
 *      Author: pi
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <string>
#include "Person.h"

class Student : public Person
{
private:
	unsigned int m_uiStudentID;
public:
	Student(std::string sName, std::string sSurname, int iAge, unsigned int uiStudentID);
	~Student(){};
	unsigned int getStudentID();
	std::string getName();
};


#endif /* STUDENT_H_ */
