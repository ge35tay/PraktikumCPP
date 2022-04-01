/*
 * Date.h
 *
 *  Created on: 29.03.2022
 *      Author: Yinghan Huang
 */

#ifndef DATE_H_
#define DATE_H_

class Date
{
private:
	int m_day, m_month, m_year;
	// Date(int day, int month, int year);    // Overload here

public:
	// Standardkontruktur here
	Date();
	Date(int day, int month, int year);

	~Date(){};    // need Dekontruktor
	bool isEqual(Date dd);
	int getDay();
	int getMonth();
	int getYear();
	int compare(Date dd2);
};




#endif /* DATE_H_ */
