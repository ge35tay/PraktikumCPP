/*
 * Date.cpp
 *
 *  Created on: 29.03.2022
 *      Author: Yinghan Huang 03728454
 */

#include "Date.h"
#include <cstdlib>
#include <ctime>


Date::Date()
{
	// Einmalige Initialisierung des random-seeds
	srand(time(nullptr));

	// Jahr zwischen 1970 und 2030, Monate zwischen 1 und 12
	int year = rand() % 61 + 1971;
	int month = rand() % 12 + 1;
	if (month == 1 || month == 3 || month == 5 || month == 7 ||
			month == 8 || month == 10 || month == 12){
		int day = rand() % 31 + 1;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11){
			int day = rand() % 30 + 1;
		}
	else
	{
		if (year % 4 == 0){
			int day = rand() % 29 + 1;
		}
		else{
			int day = rand() % 28 + 1;
		// Im Jahr 2000 is 29
		}
	}

}

Date::Date(int day, int month, int year)
{
	m_day = day; m_month = month; m_year = year;
}

int Date::getDay(){return m_day;}    // Date::
int Date::getMonth(){return m_month;}
int Date::getYear(){return m_year;}
bool Date::isEqual(Date dd)
{
	if(m_day==dd.m_day && m_month==dd.m_month && m_year==dd.m_year){
		return true;
		// need {}
	}
	return false;
}

int Date::compare(Date dd2)
{
	if (dd2.m_year > m_year){
		return(1);
	}
	else if ((dd2.m_year < m_year)){
		return(-1);
	}
	else{
		if (dd2.m_month > m_month){
			return(1);
		}
		else if (dd2.m_month < m_month){
			return(-1);
		}
		else{
			if (dd2.m_day > m_day){
				return(1);
			}
			else if (dd2.m_day < m_day){
				return(-1);
			}
			else{
				return(0);
			}
		}
	}
}

