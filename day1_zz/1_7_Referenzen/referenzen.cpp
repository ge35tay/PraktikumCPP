/**
 * @file referenzen.cpp
 * @author Yinghan Huang 03728454 and Zhishen Zhang 03736826
 * @brief 
 * @version 0.1
 * @date 2022-04-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

void swap(int& uebergabeparam1, int& uebergabeparam2){
	int temp;

	temp = uebergabeparam1;
	uebergabeparam1 = uebergabeparam2;
	uebergabeparam2 = temp;

	cout << "num1= " << uebergabeparam1 << '\n' << "num2= " << uebergabeparam2 << endl;
}

int main(){
	int num1, num2;

	cout << "Geben die Num1: ";
	cin >> num1;
	cout << endl;

	cout << "Geben die Num2: ";
	cin >> num2;
	cout << endl;

	swap(num1, num2);

}
