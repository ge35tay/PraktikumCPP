/*
 * Rekursion.cpp
 *
 *  Created on: 29.03.2022
 *      Author: Yinghan Huang
 */

#include <iostream>

int factorialIter(int n){
	if (n < 0){
		return 0;
	}
	else if (n == 0){
		return 1;
	}
	else {
		int mul = 1;
		for (int i = n; i >= 1; i--){
			mul *= i;
		}
		return mul;
	}
}

int factorialRec(int n){
	if (n < 0){
		return 0;
	}
	else if (n == 0){
		return 1;
	}
	else{
		return factorialRec(n-1)*n;
	}
}


int main() {
	std::cout << factorialIter(5) << std::endl;
	std::cout << factorialRec(5) << std::endl;
	return 0;
}

