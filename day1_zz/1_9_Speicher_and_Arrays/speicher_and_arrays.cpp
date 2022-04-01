/**
 * @file speicher_and_arrays.cpp
 * @author Yinghan Huang 03728454 and Zhishen Zhang 03736826
 * @brief 
 * @version 0.1
 * @date 2022-04-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

	int* path = new int[100000];
	// Initializetion seed
	srand(time(nullptr));

	int count13 = 0;

	// Zufall zwischen 0 and 100
	for (int i=0; i < 100000; i++){
		*(path + i) = rand() % 101;
		if (*(path + i)% 13 == 0){
			count13++;
		}

	}

	cout << count13;
	delete[] path;
	return 0;
}
