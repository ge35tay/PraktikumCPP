#include "Quadrate.h"
#include <iostream>


square operator+(square s1, square s2)
{
	return square(s1.getLaenge() + s2.getLaenge());
}

square operator-(square s1, square s2)
{
	return square(s1.getLaenge() - s2.getLaenge());
}

std::ostream& operator<<(std::ostream &os, const square &square2)   // if the functions are not all const delete the const here, otherwise when a unconst memberfunction in a const object is called, the system would think zou want to change the const.
{
	return os<< "Kantenlänge = " << square2.getLaenge() << "," << "Fläche = " << square2.getFlaeche() << "," << "Kantenlänge = " << square2.getUmfange();
}

int main(){
	square s1 = square(10);
	square s2 = square(s1);
	square s3 = s1 + s2;
	std::cout << s3 << std::endl;
	return 0;
}
