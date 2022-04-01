/*
 * vehicle.h
 *
 *  Created on: 29.03.2022
 *      Author: Yinghan Huang
 */

#ifndef VEHICLE_H_
#define VEHICLE_H_

class vehicle
{
public:
	// Öffentliche type Farbe
	enum Farbe{Blau=1, Rot, Gruen, Weiss, Schwarz};

	// Standardkontruktor und überladen
	vehicle();
	vehicle(double Preis, int Baujahr, Farbe farbe);

	int m_ID;
	void getFarbe();
	int getBaujahr();
	static int getID();
	double getPreis();
	static bool isOLdtimer(vehicle v1);

private:
	Farbe m_Farbe;
	int m_preis;
	int m_Baujahr;
	static int ID;
};



#endif /* VEHICLE_H_ */
