/**
 * @file vehicle.h
 * @author Yinghan Huang 03728454 and Zhishen Zhang 03736826
 * @brief 
 * @version 0.1
 * @date 2022-04-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef VEHICLE_H_
#define VEHICLE_H_
#include <string>
#include <iostream>

class vehicle
{
public:
	// Öffentliche type Farbe
	enum Farbe{Blau=1, Rot, Gruen, Weiss, Schwarz};

	// Standardkontruktor und überladen
	vehicle();
	vehicle(double Preis, int Baujahr, Farbe farbe);

	
	std::string getFarbe();
	int getBaujahr();
	int getID();
	double getPreis();
	static bool isOLdtimer(vehicle v1);

private:
	Farbe m_Farbe;
	int m_ID;
	int m_preis;
	int m_Baujahr;
	static int ID;
};



#endif /* VEHICLE_H_ */
