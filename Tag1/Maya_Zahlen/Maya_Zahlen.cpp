#include <iostream>
using namespace std;

int main() {
	int n;
	int s[200];
	int m = 0;

	cout << "Geben die Zahl ein";
	cin >> n;
	cout << endl;
	while(n > 0 )
	{
		s[m] = n % 20;
		m++;
		n = n / 20;

	}

	for (int i=0; i<m; i++)
	{
		cout << s[i];
		cout << '\n';
	}

	cout << endl;
	return 0;
}
