/*
 * KeyboardControl.cpp
 *
 *  Created on: 31.03.2022
 *      Author: Yinghan Huang Zhishen Zhang
 */

#include <cmath>
#include <cstdlib>
#include "ncurses.h"
#include "KeyboardControl.h"
#include "InterfaceSIM.h"

// unbekannt Initialization
KeyboardControl::KeyboardControl()
{
	Sollwert[0] = 1500;
	Sollwert[1] = 1500;
	interface.Initialize(0.04, transferFunction);
	transferPointer = this;
};

// Erstellen der Communicate-Methode
void KeyboardControl::Communicate()
{
	initscr();
	sigprocmask(SIG_UNBLOCK, &interface.mask, nullptr);
	printw("Welcome to this unstable control \n");
	nodelay(stdscr, TRUE);
	noecho();

	while (1)
	{
		char Eingabe = getch();
		if (Eingabe != ERR)
		{
			clear();
			switch (Eingabe)
			{
			case 'w'://forwards
				// if (SollGeschwindigkeit[0] > 0.49)
				// {
				// 	SollGeschwindigkeit[0] = 0.5;
				// }
				// else
				// {
				// 	SollGeschwindigkeit[0] += 0.01;
				// }

				// if (SollGeschwindigkeit[1] > 0.49)
				// {
				// 	SollGeschwindigkeit[1] = 0.5;
				// }
				// else
				// {
				// 	SollGeschwindigkeit[1] += 0.01;
				// }
				
				printw("%c\n", Eingabe);
				printw("Soll-Geschwindigkeit links: \t%lf Soll-Geschwindigkeit rechts: \t%lf\n", 
						SollGeschwindigkeit[1], SollGeschwindigkeit[0]);
				printw("Ist-Geschwindigkeit links: \t%lf  Ist-Geschwindigkeit rechts: \t%lf\n", 
						IstGeschwindigkeit[1], IstGeschwindigkeit[0]);

				SollGeschwindigkeit[1] += 0.01;
				SollGeschwindigkeit[0] += 0.01;
				break;


			case 's'://backwords
				printw("%c\n", Eingabe);
				printw("Soll-Geschwindigkeit links: \t%lf Soll-Geschwindigkeit rechts: \t%lf\n", 
						SollGeschwindigkeit[1], SollGeschwindigkeit[0]);
				printw("Ist-Geschwindigkeit links: \t%lf  Ist-Geschwindigkeit rechts: \t%lf\n", 
						IstGeschwindigkeit[1], IstGeschwindigkeit[0]);
				SollGeschwindigkeit[1] -= 0.01;
				SollGeschwindigkeit[0] -= 0.01;
				break;

			case 'a':// turn left
				

				printw("%c\n", Eingabe);
				printw("Soll-Geschwindigkeit links: \t%lf Soll-Geschwindigkeit rechts: \t%lf\n", 
						SollGeschwindigkeit[1], SollGeschwindigkeit[0]);
				printw("Ist-Geschwindigkeit links: \t%lf  Ist-Geschwindigkeit rechts: \t%lf\n", 
						IstGeschwindigkeit[1], IstGeschwindigkeit[0]);
				KeyboardControl::SollGeschwindigkeit[1] -= 0.005;//left wheel
				KeyboardControl::SollGeschwindigkeit[0] += 0.005;//right wheel
				break;

			case 'd':
				
				printw("%c\n", Eingabe);
				printw("Soll-Geschwindigkeit links: \t%lf Soll-Geschwindigkeit rechts: \t%lf\n", 
						SollGeschwindigkeit[1], SollGeschwindigkeit[0]);
				printw("Ist-Geschwindigkeit links: \t%lf  Ist-Geschwindigkeit rechts: \t%lf\n", 
						IstGeschwindigkeit[1], IstGeschwindigkeit[0]);
				KeyboardControl::SollGeschwindigkeit[1] += 0.005;
				KeyboardControl::SollGeschwindigkeit[0] -= 0.005;
				break;

			case 'b':
				KeyboardControl::SollGeschwindigkeit[0] = 0;
				KeyboardControl::SollGeschwindigkeit[1] = 0;
				printw("%c\n", Eingabe);
				printw("Soll-Geschwindigkeit links: \t%lf Soll-Geschwindigkeit rechts: \t%lf\n", 
						SollGeschwindigkeit[1], SollGeschwindigkeit[0]);
				printw("Ist-Geschwindigkeit links: \t%lf  Ist-Geschwindigkeit rechts: \t%lf\n", 
						IstGeschwindigkeit[1], IstGeschwindigkeit[0]);
				break;

			case 'q':
				SollGeschwindigkeit[0] = 0;
				SollGeschwindigkeit[1] = 0;
				printw("%c\n", Eingabe);
				printw("Soll-Geschwindigkeit links: \t%lf Soll-Geschwindigkeit rechts: \t%lf\n", 
						SollGeschwindigkeit[1], SollGeschwindigkeit[0]);
				printw("Ist-Geschwindigkeit links: \t%lf  Ist-Geschwindigkeit rechts: \t%lf\n", 
						IstGeschwindigkeit[1], IstGeschwindigkeit[0]);
				break;
			default:
				double a = std::abs(SollGeschwindigkeit[0]);
				if(std::abs(SollGeschwindigkeit[0])){
					SollGeschwindigkeit[0] = SollGeschwindigkeit[1];
				}else{
					SollGeschwindigkeit[1] = SollGeschwindigkeit[2];
				}
				break;
			}
			if (Eingabe == 'q')
				break;
		}
	}
	while (IstGeschwindigkeit[0] != 0 || IstGeschwindigkeit[1] != 0)
	{
		clear();
		printw("Soll-Geschwindigkeit links: %lf ", SollGeschwindigkeit[1]);
		printw("Soll-Geschwindigkeit rechts: %lf\n", SollGeschwindigkeit[0]);
		printw("Ist-Geschwindigkeit links: %lf ", IstGeschwindigkeit[1]);
		printw("Ist-Geschwindigkeit rechts: %lf\n", IstGeschwindigkeit[0]);
	}
	sigprocmask(SIG_BLOCK, &interface.mask, nullptr);
	endwin();
}

void KeyboardControl::Step()
{
	IstGeschwindigkeit[0] = *interface.GetInput();
	IstGeschwindigkeit[1] = *(interface.GetInput() + 1);

	if(SollGeschwindigkeit[0]>0.5){
		SollGeschwindigkeit[0]=0.5;
	}

	if(SollGeschwindigkeit[1]>0.5){
		SollGeschwindigkeit[1]=0.5;
	}

	if(SollGeschwindigkeit[0]<-0.5){
		SollGeschwindigkeit[0]=-0.5;
	}

	if(SollGeschwindigkeit[0]<-0.5){
		SollGeschwindigkeit[0]=-0.5;
	}

	Regeler1.CalculateU(SollGeschwindigkeit[0], IstGeschwindigkeit[0]);
	Regeler2.CalculateU(SollGeschwindigkeit[1], IstGeschwindigkeit[1]);
	Sollwert[0] = Regeler1.GetU() + 1500;
	Sollwert[1] = Regeler2.GetU() + 1500;
	interface.SetOutputs(Sollwert);
}

void KeyboardControl::transferFunction()
{
	transferPointer->Step();
}
KeyboardControl *KeyboardControl::transferPointer;
