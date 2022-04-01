/**
 * @file Taschenrechner.cpp
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

int main()
{

	float num1, num2;
	char operation;

	cout << "Bitte geben die erste Zahl ein:";
	cin >> num1;
	cout << endl;

	while (cin.fail())
	{
		cout << "Falsche Eingabe, bitte wiederholen";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> num1;
		cout << endl;
	}

	cout << "Bitte geben den Operator ein";
	cin >> operation;
	cout << endl;
	while ((operation != '+') && (operation != '-') && (operation != '*') && (operation != '/'))
	{
		cout << "Falsche Eingabe, bitte wiederholen:";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> operation;
		cout << endl;
	}

	cout << "Bitte geben die zweite Zahl ein";
	cin >> num2;
	cout << endl;
	while (cin.fail())
	{
		cout << "Falsche Eingabe, bitte wiederholen:";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> num1;
		cout << endl;
	}

	if (operation == '+')
	{
		cout << num1 << '+' << num2 << '=' << num1 + num2;
	}
	else if (operation == '-')
	{
		cout << num1 << '-' << num2 << '=' << num1 - num2;
	}
	else if (operation == '*')
	{
		cout << num1 << '*' << num2 << '=' << num1 * num2;
	}
	else if (operation == '/')
	{
		if (num2 == 0)
		{
			cout << "Falsche Eingabe, bitte geben die zweite Zahl:";
			cin >> num2;
			cout << endl;
			while (num2 == 0 || cin.fail())
			{
				cout << "Falsche Eingabe, bitte geben die zweite Zahl:";
				cin.clear();
				cin.ignore(1000, '\n');
				cin >> num2;
				cout << endl;
			}
		}
		cout << num1 << '/' << num2 << '=' << num1 / num2;
	}

	return 0;
}
