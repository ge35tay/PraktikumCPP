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

std::string vehicle::getFarbe(){
	if(m_Farbe==1){
		return "Blau";
	}
	else if(m_Farbe==2){
		return "Rot";
	}
	else if(m_Farbe==3){
		return "Grün";
	}
	else if(m_Farbe==4){
		return "Weiß";
	}
	else if(m_Farbe==5){
		return "Schwarz";
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

bool vehicle::isOLdtimer(vehicle v1){
	if (v1.getBaujahr() < 1980){
		std::cout << "Geht zum Meseum" << std::endl;
		return true;
	}
	else{
		std::cout << "Willkommen aus Grüner Partei" << std::endl;
		return false;
	}
}




