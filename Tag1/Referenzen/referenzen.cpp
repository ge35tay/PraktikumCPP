#include <iostream>
using namespace std;

void swap(int& uebergabeparam1, int& uebergabeparam2){
	int temp;

	temp = uebergabeparam1;
	uebergabeparam1 = uebergabeparam2;
	uebergabeparam2 = temp;

	cout << "num1= " << uebergabeparam1 << '\n' << "num2= " << uebergabeparam2 << endl;
}

int main(){
	int num1, num2;

	cout << "Geben die Num1: ";
	cin >> num1;
	cout << endl;

	cout << "Geben die Num2: ";
	cin >> num2;
	cout << endl;

	swap(num1, num2);

}
