/*
 * Quadrate.cpp
 *
 *  Created on: 29.03.2022
 *      Author: Yinghan Huang
 */

#include "Quadrate.h"
#include <iostream>


square::square(){
	m_Kantenlaenge = 1;
}

square::square(const float Kantenlaenge){
	m_Kantenlaenge = Kantenlaenge;
}

square::square(const square &square2){
	m_Kantenlaenge = square2.getLaenge();
}

float square::getLaenge() const
{
	return m_Kantenlaenge;
}

float square::getFlaeche() const {
	return m_Kantenlaenge * m_Kantenlaenge;
}

float square::getUmfange() const {
	return 4 * m_Kantenlaenge;
}

