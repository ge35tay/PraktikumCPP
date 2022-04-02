/*
 * ncurse.cpp
 *
 *  Created on: 31.03.2022
 *      Author: Yinghan Huang
 */

#include <iostream>
#include <list>
#include <ncurses.h>

// public list
std::list<char> eingabelist;

//build the executable file::: g++ ncurse.cpp -o ncurse -lpanel -lncurses


int main() {
	char Eingabe;

	initscr();
	printw("Hello!");
	refresh();
	nodelay(stdscr, TRUE);
	noecho();


	while(Eingabe != 'q'){
		Eingabe = getch();
		if (Eingabe != ERR){
			
			eingabelist.push_back(Eingabe);
			clear();
			printw("Eingabe ist: %c\n", Eingabe);
		}
	}
	
	endwin();
	std::list<char>::iterator iter;
	for (iter = eingabelist.begin(); iter!=eingabelist.end(); iter++){
		std::cout << *iter << std::endl;
	}
	
	return 0;
}




