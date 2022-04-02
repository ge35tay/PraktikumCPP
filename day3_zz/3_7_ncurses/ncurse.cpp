/**
 * @file ncurse.cpp
 * @author Yinghan Huang 03728454 and Zhishen Zhang 03736826
 * @brief
 * @version 0.1
 * @date 2022-04-02
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <list>
#include <ncurses.h>

// public list
std::list<char> eingabelist;
// build the executable file::: g++ ncurse.cpp -o ncurse -lpanel -lncurses

int main()
{
	char Eingabe;

	initscr();
	printw("Hello!");
	refresh();
	nodelay(stdscr, TRUE);
	noecho();

	while (Eingabe != 'q')
	{
		Eingabe = getch();
		if (Eingabe != ERR)
		{
			eingabelist.push_back(Eingabe);
			clear();
			printw("Eingabe ist: %c\n", Eingabe);
		}
	}
	eingabelist.pop_back();

	endwin();//zurueckschalten auf Standatdsuasgabe (cout)
	std::list<char>::iterator iter;
	for (iter = eingabelist.begin(); iter != eingabelist.end(); iter++)
	{
		std::cout << *iter << std::endl;
	}

	return 0;
}
