/*
 * ncurse.cpp
 *
 *  Created on: 31.03.2022
 *      Author: Yinghan Huang
 */

#include <iostream>
#include <list>
#include "ncurses.h"

// public list
std::list<char> eingabelist;


int main() {
	char Eingabe;

	initscr();
	nodelay(stdscr, TRUE);
	noecho();


	while(1){
		Eingabe = getch();
		if (Eingabe != ERR){
			if (Eingabe != 'q'){
				eingabelist.push_back(Eingabe);
				clear();
				printw("Eingabe ist: %c", Eingabe);
			}

			else{
				break;
			}

		}
	}
	endwin();
	std::list<char>::iterator iter;
	for (iter = eingabelist.begin(); iter!=eingabelist.end(); iter++){
		std::cout << *iter << std::endl;
	}
}




