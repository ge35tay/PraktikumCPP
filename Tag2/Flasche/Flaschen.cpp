/*
 * Flaschen.cpp
 *
 *  Created on: 29.03.2022
 *      Author: Yinghan Huang 03728454
 */

#include "Flaschen.h"
#include <iostream>
#include <string>

// Standardkonstruktor mit Initialisierungsliste
Flaschen::Flaschen()
{
	dVolumen = 1;
	sMaterial = "Muehl";
}

// Standarddestruktur
Flaschen::~Flaschen()
{}

double Flaschen::getdVolumen()
{
	return dVolumen;
}

void Flaschen::setdVolumen(double fdVolumen)
{
	dVolumen = fdVolumen;
}

std::string Flaschen::getsMaterial()
{
	return sMaterial;
}

void Flaschen::setsMaterial(std::string fsMaterial)
{
	sMaterial = fsMaterial;
}

// Zeigen Volumen und Material
void Flaschen::printFlasche()
{
	std::cout << "dVolumen = " << dVolumen << std::endl;
	std::cout << "sMaterial = " << sMaterial << std::endl;
}

// adopt Volumen und Material von anderer Flasche
void Flaschen::adoptFlasche(Flaschen Flasche2)
{
	dVolumen = Flasche2.dVolumen;
	sMaterial = Flasche2.sMaterial;
}

