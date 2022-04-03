/*
 * KeyboardControl.cpp
 *
 *  Created on: 31.03.2022
 *      Author: Yinghan Huang Zhishen Zhang
 */

#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <mutex>
#include "ncurses.h"
#include "KeyboardControl.h"
#include "InterfaceSIM.h"

// unbekannt Initialization
KeyboardControl::KeyboardControl() {
	Sollwert[0] = 1500;
	Sollwert[1] = 1500;
	interface.Initialize(0.04, transferFunction);
	transferPointer = this;
}
;

// Erstellen der Communicate-Methode
void KeyboardControl::Communicate() {
	initscr();
	sigprocmask(SIG_UNBLOCK, &interface.mask, nullptr);
	printw("Welcome to this unstable control \n");
	nodelay(stdscr, TRUE);
	noecho();
	char Eingabe;

	while (1) {
		Eingabe = '\0';
		Eingabe = getch();
		clear();
		usleep(50000);
		if (Eingabe != ERR) {
			switch (Eingabe) {
			case 'w':
				printw("%c\n", Eingabe);
				printw(
						"Soll-Geschwindigkeit links: \t%lf Soll-Geschwindigkeit rechts: \t%lf\n",
						SollGeschwindigkeit[1], SollGeschwindigkeit[0]);
				printw(
						"Ist-Geschwindigkeit links: \t%lf  Ist-Geschwindigkeit rechts: \t%lf\n",
						IstGeschwindigkeit[1], IstGeschwindigkeit[0]);

				SollGeschwindigkeit[1] += 0.01;
				SollGeschwindigkeit[0] += 0.01;
				break;

			case 's': //backwords
				printw("%c\n", Eingabe);
				printw(
						"Soll-Geschwindigkeit links: \t%lf Soll-Geschwindigkeit rechts: \t%lf\n",
						SollGeschwindigkeit[1], SollGeschwindigkeit[0]);
				printw(
						"Ist-Geschwindigkeit links: \t%lf  Ist-Geschwindigkeit rechts: \t%lf\n",
						IstGeschwindigkeit[1], IstGeschwindigkeit[0]);
				SollGeschwindigkeit[1] -= 0.01;
				SollGeschwindigkeit[0] -= 0.01;
				break;

			case 'a': // turn left

				printw("%c\n", Eingabe);
				printw(
						"Soll-Geschwindigkeit links: \t%lf Soll-Geschwindigkeit rechts: \t%lf\n",
						SollGeschwindigkeit[1], SollGeschwindigkeit[0]);
				printw(
						"Ist-Geschwindigkeit links: \t%lf  Ist-Geschwindigkeit rechts: \t%lf\n",
						IstGeschwindigkeit[1], IstGeschwindigkeit[0]);
				SollGeschwindigkeit[1] -= 0.005; //left wheel
				SollGeschwindigkeit[0] += 0.005; //right wheel
				break;

			case 'd':

				printw("%c\n", Eingabe);
				printw(
						"Soll-Geschwindigkeit links: \t%lf Soll-Geschwindigkeit rechts: \t%lf\n",
						SollGeschwindigkeit[1], SollGeschwindigkeit[0]);
				printw(
						"Ist-Geschwindigkeit links: \t%lf  Ist-Geschwindigkeit rechts: \t%lf\n",
						IstGeschwindigkeit[1], IstGeschwindigkeit[0]);
				SollGeschwindigkeit[1] += 0.005;
				SollGeschwindigkeit[0] -= 0.005;
				break;

			case 'b':

				printw("%c\n", Eingabe);
				printw(
						"Soll-Geschwindigkeit links: \t%lf Soll-Geschwindigkeit rechts: \t%lf\n",
						SollGeschwindigkeit[1], SollGeschwindigkeit[0]);
				printw(
						"Ist-Geschwindigkeit links: \t%lf  Ist-Geschwindigkeit rechts: \t%lf\n",
						IstGeschwindigkeit[1], IstGeschwindigkeit[0]);
				SollGeschwindigkeit[0] = 0;
				SollGeschwindigkeit[1] = 0;
				break;

			case 'q':
				SollGeschwindigkeit[0] = 0;
				SollGeschwindigkeit[1] = 0;
				printw("%c\n", Eingabe);
				printw(
						"Soll-Geschwindigkeit links: \t%lf Soll-Geschwindigkeit rechts: \t%lf\n",
						SollGeschwindigkeit[1], SollGeschwindigkeit[0]);
				printw(
						"Ist-Geschwindigkeit links: \t%lf  Ist-Geschwindigkeit rechts: \t%lf\n",
						IstGeschwindigkeit[1], IstGeschwindigkeit[0]);
				break;
<<<<<<< Updated upstream

			}
			if (Eingabe == 'q'){
			clear();
			printw("%c\n", Eingabe);
			break;
			}

		}else {
//			printw("NO KEY\n");
			if (std::abs(SollGeschwindigkeit[0])
					> std::abs(SollGeschwindigkeit[1])) {

				SollGeschwindigkeit[0] = SollGeschwindigkeit[1];
			} else {
				SollGeschwindigkeit[1] = SollGeschwindigkeit[0];
			}
			printw("Soll-Geschwindigkeit links: %lf ", SollGeschwindigkeit[1]);
			printw("Soll-Geschwindigkeit rechts: %lf\n", SollGeschwindigkeit[0]);
			printw("Ist-Geschwindigkeit links: %lf ", IstGeschwindigkeit[1]);
			printw("Ist-Geschwindigkeit rechts: %lf\n", IstGeschwindigkeit[0]);
=======
//			default:
//				double a = std::abs(SollGeschwindigkeit[0]);

			}
			if (Eingabe == 'q')
				break;
		}else{
			if(std::abs(SollGeschwindigkeit[0])){
				SollGeschwindigkeit[0] = SollGeschwindigkeit[1];
			}else{
				SollGeschwindigkeit[1] = SollGeschwindigkeit[2];
			};

>>>>>>> Stashed changes
		}
	}
	endwin();
	std::mutex m2;
	m2.lock();
	while (counter<10) {
		SollGeschwindigkeit[0] = 0;
		SollGeschwindigkeit[1] = 0;
		if(std::abs(IstGeschwindigkeit[0])+std::abs(IstGeschwindigkeit[1]) < 0.01){
			counter ++;
		}
		usleep(100000);
	}
	m2.unlock();
}

void KeyboardControl::Step() {
	std::mutex m;
	m.lock();
	IstGeschwindigkeit[0] = *interface.GetInput();
	IstGeschwindigkeit[1] = *(interface.GetInput() + 1);

	if (SollGeschwindigkeit[0] > 0.5) {
		SollGeschwindigkeit[0] = 0.5;
	}

	if (SollGeschwindigkeit[1] > 0.5) {
		SollGeschwindigkeit[1] = 0.5;
	}

	if (SollGeschwindigkeit[0] < -0.5) {
		SollGeschwindigkeit[0] = -0.5;
	}

	if (SollGeschwindigkeit[0] < -0.5) {
		SollGeschwindigkeit[0] = -0.5;
	}

	Regeler1.CalculateU(SollGeschwindigkeit[0], IstGeschwindigkeit[0]);
	Regeler2.CalculateU(SollGeschwindigkeit[1], IstGeschwindigkeit[1]);
	Sollwert[0] = Regeler1.GetU() + 1500;
	Sollwert[1] = Regeler2.GetU() + 1500;
	interface.SetOutputs(Sollwert);
	m.unlock();
}

void KeyboardControl::transferFunction() {
	transferPointer->Step();
}
KeyboardControl *KeyboardControl::transferPointer;
