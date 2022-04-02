/*
 * ncurses.cpp
 *
 *  Created on: 2 Apr 2022
 *      Author: pi
 */


#include <iostream>
#include <list>
#include "ncurses.h"

std::list<char> eingabelist;

int main(){

	char eingabe;
	initscr();
	printw("Hello!");
	refresh();
	nodelay(stdscr,TRUE);
	noecho();


	while(Eingabe!='q'){
		Eingabe = getch();
		if(Eingave!=ERR){
			eingabelist.push_back(Eingabe);
			clear();
			printw("Eingabe ist:%c\n", Eingabe);
		}
	}
	
	endwin();
	
	
	std::list<char>
	
	
	

}

