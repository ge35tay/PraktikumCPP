/**
 * @file quadratische_funktionen.cpp
 * @author Yinghan Huang 03728454 and Zhishen Zhang 03736826
 * @brief 
 * @version 0.1
 * @date 2022-04-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <cmath>
#include <iostream>
using namespace std;

void solution(float a, float b, float c, float *x1, float *x2);

int main()
{
	float a, b, c, x1, x2;
	cout << "Geben a ein: ";
	cin >> a;
	cout << "Geben b ein: ";
	cin >> b;
	cout << "Geben c ein: ";
	cin >> c;
	solution(a, b, c, &x1, &x2);
}


void solution(float a, float b, float c, float *x1, float *x2)
{
	float delta;
	delta = pow(b, 2) - 4 * a * c;
	if (delta >= 0)
	{
		*x1 = (-b + sqrt(delta)) / (2 * a);
		*x2 = (-b - sqrt(delta)) / (2 * a);
		cout << *x1 << '\n'
			 << *x2;
	}
	else
	{
		cout << "Keine Lösung";
	}
}