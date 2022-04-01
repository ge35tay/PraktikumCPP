#ifndef FLASCHEN_H_
#define FLASCHEN_H_


#include <string>
#include <iostream>

class Flaschen
{
private:
	double dVolumen;
	std::string sMaterial;

public:
	// Standardkonstruktor
	Flaschen();
	// Destruktor
	~Flaschen();

	// set und get zwei Attribute
	double getdVolumen();
	void setdVolumen(double fdVolumen);
	std::string getsMaterial();
	void setsMaterial(std::string fsMaterial);

	// Methode
	void printFlasche();
	void adoptFlasche(Flaschen Flasche2);
};

#endif
