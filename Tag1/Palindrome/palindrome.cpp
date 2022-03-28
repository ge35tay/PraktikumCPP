#include <string>
#include <iostream>
using namespace std;

void ispalindrome(string);

int main(){
	string a;
	cout << "Geben ein String ein: ";
	cin >> a;
	ispalindrome(a);
}

void ispalindrome(string a){
	string b = a;
	int j = 0;
	for (int i = a.size()-1; i>=0; i--){
		b[j] = a[i];
		j++;
	}

	if (a.compare(b) == 0){
		cout << "Palindrome";
	}
	else{
		cout << "Leider";
	}
}

