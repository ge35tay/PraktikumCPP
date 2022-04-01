/**
 * @author Yinghan Huang 03728454 and Zhishen Zhang 93736826
 * @brief 
 * @version 0.1
 * @date 2022-04-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;
void heron_ite(float a);

int main()
{
	float a;
	cout << "Geben eine Zahl ein: ";
	cin >> a;

	heron_ite(a);
	return 0;
}

void heron_ite(float a)
{
	float x = 1;
	for (int i = 0; i <= 9; i++)
	{
		x = (x + a / x) / 2;
	}
	cout << "Die Quadratwurzel der Zahl " << a << " lautet: " << x << endl;
}
