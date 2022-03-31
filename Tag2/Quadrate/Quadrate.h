/*
 * Quadrate.h
 *
 *  Created on: 29.03.2022
 *      Author: pi
 */

#ifndef QUADRATE_H_
#define QUADRATE_H_

#include <iostream>
class square
{
private:
	float m_Kantenlaenge;
public:
	square();
	square(const float Kantenlaenge);

	//Konstruktor mit konstanter Referenz
	square(const square &square2);
	float getLaenge() const;
	float getFlaeche() const;
	float getUmfange() const;

};




#endif /* QUADRATE_H_ */
