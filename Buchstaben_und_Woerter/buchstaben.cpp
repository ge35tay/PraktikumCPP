#include <string>
#include <iostream>
using namespace std;

void InOrdnung (string);
void VokaleInklusiv(string);

int main() {
	string a;
	cout << "Geben ein wort ein: ";
	cin >> a;
	InOrdnung(a);
	cout << endl;
	VokaleInklusiv(a);
}

void InOrdnung(string a){
	string temp = a;
	int j = 1;
	for (int i = 2; i < a.size(); i=j+1){
		temp[j] = a[i];
		temp[i] = a[j];
		j = j + 2;
	}
	cout << temp;
}

void VokaleInklusiv(string a){
	string b = "";
	for (int i=0; i < a.size(); i++){
		if (a[i]!='A' && a[i]!='E' && a[i]!='I' && a[i]!='O' && a[i]!='U' &&
				a[i]!='a' && a[i]!='e' && a[i]!='i' && a[i]!='o' && a[i]!='u'){
			b += a[i];
		}
	}
	cout << b;
}
