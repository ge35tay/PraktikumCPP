/**
 * @file Student.h
 * @author Yinghan Huang 03728454 and Zhishen Zhang 03736826
 * @brief
 * @version 0.1
 * @date 2022-04-01
 *
 * @copyright Copyright (c) 2022
 *
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
	void sagen();
};

#endif /* STUDENT_H_ */
