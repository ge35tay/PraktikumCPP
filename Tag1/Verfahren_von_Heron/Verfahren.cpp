#include <iostream>
using namespace std;
void heron_ite(float a);

int main() {
	float a;
	cout << "Geben eine Zahl ein: ";
	cin >> a;

	heron_ite(a);
	return 0;
}


void heron_ite(float a)
{
	float x = 1;
	for (int i=0; i<=9; i++)
	{
		x = (x + a/x)/2;
	}
	cout << x;

}

