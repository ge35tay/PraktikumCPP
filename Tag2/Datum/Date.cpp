/*
 * Date.cpp
 *
 *  Created on: 29.03.2022
 *      Author: Yinghan Huang 03728454
 */

#include "Date.h"

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


