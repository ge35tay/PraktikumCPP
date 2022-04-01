/**
 * @file buchstaben.cpp
 * @author Yinghan Huang 03728454 and Zhishen Zhang 03736826
 * @brief 
 * @version 0.1
 * @date 2022-04-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <string>
#include <iostream>

void InOrdnung(std::string a);
void VokaleInklusiv(std::string a);

int main()
{
	std::string a;
	std::cout << "Geben ein wort ein: ";
	std::cin >> a;
	InOrdnung(a);
	VokaleInklusiv(a);
}

void InOrdnung(std::string a)
{
	std::string temp = a;
	for(int i = 1; i <(a.size()-2); i+=2){
		temp[i] = a[i+1];
		temp[i+1] = a[i];
	}
	std::cout << temp << std::endl;
}

void VokaleInklusiv(std::string a)
{
	std::string b = "";
	for (int i = 0; i < a.size(); i++)
	{

		std::string temp(1, a[i]);
		if (temp != "A" && temp != "E" && temp != "I" && temp != "O" && temp != "U" &&
			temp != "a" && temp != "e" && temp != "i" && temp != "o" && temp != "u")
		{
			b.append(temp); 
		}
	}
	std::cout <<b<< std::endl;
}
