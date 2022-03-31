#include "Flaschen.h"
#include <string>
#include <iostream>

int main()
{
	//Erzeugen der Flasche 1 & 2 durch Anruf des Standardkonstruktors
	Flaschen Flasche1;
	Flaschen Flasche2;

	// test all Methoden
	Flasche1.getdVolumen();
	Flasche1.setdVolumen(90);
	Flasche1.getsMaterial();
	Flasche1.setsMaterial("Biomull");
	Flasche2.getdVolumen();
	Flasche2.setdVolumen(100);
	Flasche2.getsMaterial();
	Flasche2.setsMaterial("Restmull");

	Flasche1.printFlasche();
	Flasche2.printFlasche();

	Flasche1.adoptFlasche(Flasche2);
	Flasche1.printFlasche();
}
