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
	std::cout << std::endl;
	VokaleInklusiv(a);
}

void InOrdnung(std::string a)
{
	std::string temp = a;
	int j = 1;
	for (int i = 2; i < a.size(); i = j + 1)
	{
		temp[j] = a[i];
		temp[i] = a[j];
		j = j + 2;
	}
	std::cout << temp;
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
	std::cout << b;
}
