/**
 * @file Quadrate.h
 * @author Yinghan Huang 03728454 and Zhishen Zhang 03736826
 * @brief 
 * @version 0.1
 * @date 2022-04-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef QUADRATE_H
#define QUADRATE_H
#include <iostream>

class square
{

public:
	square(const double kantenLaege);
	square(const square &s);
	~square(){};

	double getSquareKantenlaege() const;
	double getSquareFlaeche() const;
	double getSquareUmfang() const;
	// square operator + (const square &s1) const;

	// friends defined inside class body are inline and are hidden from non-ADL lookup
	friend square operator+(square s1, square s2)
	{
		return square(s1.getSquareKantenlaege() + s2.getSquareKantenlaege());
	}

	friend square operator-(square s1, square s2)
	{
		return square(s1.getSquareKantenlaege() - s2.getSquareKantenlaege());
	}

	friend std::ostream &operator<<(std::ostream &os, const square &square2) // if the functions are not all const delete the const here, otherwise when a unconst memberfunction in a const object is called, the system would think zou want to change the const.
	{
		return os << "Kantenlänge = " << square2.getSquareKantenlaege() << ","
				  << "Fläche = " << square2.getSquareFlaeche() << ","
				  << "Kantenlänge = " << square2.getSquareUmfang();
	}

private:
	double kantenLaege_;
};

#endif