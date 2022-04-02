/*
 * Listen.cpp
 *
 *  Created on: 30.03.2022
 *      Author: Yinghan Huang
 */

#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>

struct coord{
	float coord_x;
	float coord_y;

	coord(float x, float y){
		coord_x = x;
		coord_y = y;
	}
};


void printlist(std::list<coord> * list_add){
	std::list<coord>::iterator myiter;
	for (myiter=(*list_add).begin(); myiter!= (*list_add).end(); myiter++){
		std::cout << "X: " << myiter-> coord_x << ", Y: " << myiter -> coord_y << std::endl;
	}

}

void delcoords(std::list<coord> & list_ref){
	for (std::list<coord>::iterator iter= list_ref.begin(); iter != list_ref.end(); iter++){
		if(iter->coord_x < iter-> coord_y){
			iter = list_ref.erase(iter);
		}
	}
}

int main()
{
	srand((float)time(nullptr));
	std::list<coord> list1;
	for (int i=0; i<10; i++){
		list1.push_back(coord((rand() %100) * 0.1, (rand() %100)*0.1));
	}

	std::list<coord> list2 = list1;
	printlist(&list1);
	std::cout << '\n';
	delcoords(list2);
	printlist(&list2);
	return 0;


}
