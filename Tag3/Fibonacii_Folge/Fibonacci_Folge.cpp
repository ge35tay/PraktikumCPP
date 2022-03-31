/*
 * Fibonacci_Folge.cpp
 *
 *  Created on: 29.03.2022
 *      Author: Yinghan Huang
 */

#include <iostream>

int Fibonacci(int f){
	if (f <= 0){
		return 0;
	}
	else if (f == 1){
		return 1;
	}
	else{
		return Fibonacci(f - 1) + Fibonacci(f - 2);
	}
}

int main(){
	std::cout << "The first 15 Fibonacci numbers are: ";
	for ( int i = 0; i < 15; i++){
		std::cout << Fibonacci(i) << " ";
	}
	std::cout << std::endl;
}



