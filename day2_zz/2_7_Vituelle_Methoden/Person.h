/**
 * @file Person.h
 * @author Yinghan Huang 03728454 and Zhishen Zhang 03736826
 * @brief 
 * @version 0.1
 * @date 2022-04-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <string>

class Person
{
private:
	std::string m_sName;
	std::string m_sSurname;
	int m_iAge;

public:
	Person(std::string sName, std::string sSurname, int iAge);
	~Person(){};
	std::string getName();
	std::string getSurname();
	int getAge();
	bool setAge(int iAge);
	virtual void sagen();
};

#endif /* PERSON_H_ */
