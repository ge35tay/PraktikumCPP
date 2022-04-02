/*
 * KeyboardControl.cpp
 *
 *  Created on: 31.03.2022
 *      Author: Yinghan Huang Zhishen Zhang
 */

#include <cmath>
#include "ncurses.h"
#include "KeyboardControl.h"
#include "InterfaceSIM.h"


// unbekannt Initialization
KeyboardControl::KeyboardControl(){
	Sollwert[0] = 1500;
	Sollwert[1] = 1500;
	interface.Initialize(0.04, transferFunction);
	transferPointer = this;
};

// Erstellen der Communicate-Methode
void KeyboardControl::Communicate(){
	initscr();
	sigprocmask(SIG_UNBLOCK, &interface.mask, nullptr);
	printw("Welcome to this unstable control \n");
	nodelay(stdscr, TRUE);
	noecho();

	while(1){
		char Eingabe = getch();
		if (Eingabe != ERR){
			clear();
			switch(Eingabe)
			{
			case 'w':
				KeyboardControl::SollGeschwindigkeit[0] += 0.01;
				KeyboardControl::SollGeschwindigkeit[1] += 0.01;
				if (SollGeschwindigkeit[0] > 0.5){
					SollGeschwindigkeit[0] = 0.5;
				}
				if (SollGeschwindigkeit[1] > 0.5){
					SollGeschwindigkeit[1] = 0.5;
				}
				printw("%c \n", Eingabe);
				printw("Soll-Geschwindigkeit links: %lf ", SollGeschwindigkeit[1]);
				printw("Soll-Geschwindigkeit rechts: %lf\n", SollGeschwindigkeit[0]);
				printw("Ist-Geschwindigkeit links: %lf ", IstGeschwindigkeit[1]);
				printw("Ist-Geschwindigkeit rechts: %lf\n", IstGeschwindigkeit[0]);
				break;
			case 's':
				KeyboardControl::SollGeschwindigkeit[0] -= 0.01;
				KeyboardControl::SollGeschwindigkeit[1] -= 0.01;
				if (SollGeschwindigkeit[0] < -0.5){
					SollGeschwindigkeit[0] = -0.5;
				}
				if (SollGeschwindigkeit[1] < -0.5){
					SollGeschwindigkeit[1] = -0.5;
				}
				printw("%c \n", Eingabe);
				printw("Soll-Geschwindigkeit links: %lf ", SollGeschwindigkeit[1]);
				printw("Soll-Geschwindigkeit rechts: %lf\n", SollGeschwindigkeit[0]);
				printw("Ist-Geschwindigkeit links: %lf ", IstGeschwindigkeit[1]);
				printw("Ist-Geschwindigkeit rechts: %lf\n", IstGeschwindigkeit[0]);
				break;
			case 'a':
				KeyboardControl::SollGeschwindigkeit[0] += 0.005;
				KeyboardControl::SollGeschwindigkeit[1] -= 0.005;
				if (SollGeschwindigkeit[0] < -0.5){
					SollGeschwindigkeit[0] = -0.5;
				}
				if (SollGeschwindigkeit[1] < -0.5){
					SollGeschwindigkeit[1] = -0.5;
				}
				if (SollGeschwindigkeit[0] > 0.5){
					SollGeschwindigkeit[0] = 0.5;
				}
				if (SollGeschwindigkeit[1] > 0.5){
					SollGeschwindigkeit[1] = 0.5;
				}
				printw("%c \n", Eingabe);
				printw("Soll-Geschwindigkeit links: %lf ", SollGeschwindigkeit[1]);
				printw("Soll-Geschwindigkeit rechts: %lf\n", SollGeschwindigkeit[0]);
				printw("Ist-Geschwindigkeit links: %lf ", IstGeschwindigkeit[1]);
				printw("Ist-Geschwindigkeit rechts: %lf\n", IstGeschwindigkeit[0]);
				break;
			case 'd':
				KeyboardControl::SollGeschwindigkeit[0] -= 0.005;
				KeyboardControl::SollGeschwindigkeit[1] += 0.005;
				if (SollGeschwindigkeit[0] < -0.5){
					SollGeschwindigkeit[0] = -0.5;
				}
				if (SollGeschwindigkeit[1] < -0.5){
					SollGeschwindigkeit[1] = -0.5;
				}
				if (SollGeschwindigkeit[0] > 0.5){
					SollGeschwindigkeit[0] = 0.5;
				}
				if (SollGeschwindigkeit[1] > 0.5){
					SollGeschwindigkeit[1] = 0.5;
				}
				printw("%c \n", Eingabe);
				printw("Soll-Geschwindigkeit links: %lf ", SollGeschwindigkeit[1]);
				printw("Soll-Geschwindigkeit rechts: %lf\n", SollGeschwindigkeit[0]);
				printw("Ist-Geschwindigkeit links: %lf ", IstGeschwindigkeit[1]);
				printw("Ist-Geschwindigkeit rechts: %lf\n", IstGeschwindigkeit[0]);
				break;
			case 'b':
				KeyboardControl::SollGeschwindigkeit[0] = 0;
				KeyboardControl::SollGeschwindigkeit[1] = 0;
				printw("%c \n", Eingabe);
				printw("Soll-Geschwindigkeit links: %lf ", SollGeschwindigkeit[1]);
				printw("Soll-Geschwindigkeit rechts: %lf\n", SollGeschwindigkeit[0]);
				printw("Ist-Geschwindigkeit links: %lf ", IstGeschwindigkeit[1]);
				printw("Ist-Geschwindigkeit rechts: %lf\n", IstGeschwindigkeit[0]);
				break;
			case 'q':
				KeyboardControl::SollGeschwindigkeit[0] = 0;
				KeyboardControl::SollGeschwindigkeit[1] = 0;
				printw("%c \n", Eingabe);
				printw("Soll-Geschwindigkeit links: %lf ", SollGeschwindigkeit[1]);
				printw("Soll-Geschwindigkeit rechts: %lf\n", SollGeschwindigkeit[0]);
				printw("Ist-Geschwindigkeit links: %lf ", IstGeschwindigkeit[1]);
				printw("Ist-Geschwindigkeit rechts: %lf\n", IstGeschwindigkeit[0]);
				break;
			}
			if(Eingabe == 'q') break;
		}
	}
	while(IstGeschwindigkeit[0] != 0 || IstGeschwindigkeit[1] != 0 ){
		clear();
		printw("Soll-Geschwindigkeit links: %lf ", SollGeschwindigkeit[1]);
		printw("Soll-Geschwindigkeit rechts: %lf\n", SollGeschwindigkeit[0]);
		printw("Ist-Geschwindigkeit links: %lf ", IstGeschwindigkeit[1]);
		printw("Ist-Geschwindigkeit rechts: %lf\n", IstGeschwindigkeit[0]);
	}
	sigprocmask(SIG_BLOCK, &interface.mask, nullptr);
	endwin();

}

void KeyboardControl::Step(){
	IstGeschwindigkeit[0] = *interface.GetInput();
	IstGeschwindigkeit[1] = *(interface.GetInput() + 1);
	Regeler1.CalculateU(SollGeschwindigkeit[0], IstGeschwindigkeit[0]);
	Regeler2.CalculateU(SollGeschwindigkeit[1], IstGeschwindigkeit[1]);
	Sollwert[0] = Regeler1.GetU() + 1500;
	Sollwert[1] = Regeler2.GetU() + 1500;
	interface.SetOutputs(Sollwert);
}

void KeyboardControl::transferFunction(){
	transferPointer -> Step();
}
KeyboardControl* KeyboardControl::transferPointer;
