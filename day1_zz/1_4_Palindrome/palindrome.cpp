/**
 * @file palindrome.cpp
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

int ispalindrome(std::string str);

int main()
{
	std::string str;
	std::cout << "Geben ein string ein: ";
	std::cin >> str;
	while (!ispalindrome(str))
	{
		std::cin >> str;
	}
	return 0;
}

int ispalindrome(std::string str)
{

	int n_char = str.length();
	//Check if there is a capital letter
	for (int i = 0; i < n_char; i++)
	{
		if ((int)str[i] >= 65 && (int)str[i] <= 90)
		{
			std::cout << "Es kann nur Wörter in Kleinbuchstaben berücksichtigt werden.\nBitte versuchen Sie nochmals:\n";
			return 0;
		}
	}

	// check if it is a Palindrome
	while (str.length() > 1)
	{

		if (str[0] != str.back())
		{
			std::cout << "Das Gegebene Wort ist keine Palindrome. " << std::endl;
			return 1;
		}
		str = str.substr(1, str.length() - 2);
	}

	std::cout << "Ja! Das Gegebene Wort ist eine Palindrome! " << std::endl;

	return 1;
}