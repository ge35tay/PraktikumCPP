/*
 * vehicle.cpp
 *
 *  Created on: 29.03.2022
 *      Author: Yinghan Huang
 */

#include "vehicle.h"
#include <string>
#include <iostream>

int vehicle::ID = 0;

vehicle::vehicle()
{
	ID++;
	m_ID = ID;
	m_preis = 40000;
	m_Farbe = Farbe::Blau;
	m_Baujahr = 2020;
}

vehicle::vehicle(double Preis, int Baujahr, Farbe Farbe){
	ID++;
	m_ID = ID;
	m_Farbe = Farbe;
	m_Baujahr = Baujahr;
	m_preis = Preis;
}

void vehicle::getFarbe(){
	if(m_Farbe==1){
		std::cout << "Blau" << std::endl;
	}
	else if(m_Farbe==2){
		std::cout << "Rot" << std::endl;
	}
	else if(m_Farbe==3){
		std::cout << "Grün" << std::endl;
	}
	else if(m_Farbe==4){
		std::cout << "Weiß" << std::endl;
	}
	else if(m_Farbe==5){
		std::cout << "Schwarz" << std::endl;
	}
}

int vehicle::getBaujahr(){
	return m_Baujahr;
}

int vehicle::getID(){
	return ID;
}

double vehicle::getPreis(){
	return m_preis;
}

void vehicle::isOLdtimer(){
	if (m_Baujahr < 1980){
		std::cout << "Geht zum Meseum" << std::endl;
	}
	else{
		std::cout << "Willkommen aus Grüner Partei" << std::endl;
	}
}




