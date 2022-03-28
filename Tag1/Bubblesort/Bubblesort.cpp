#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void bubblesort (int* path, int len){
	int temp;
	for (int i = 0; i < len-1; i++){
		for (int j = 0; j < len - i -1; j++){
			if (*(path+j) > *(path + j+1)){
				temp = *(path + j);
				*(path + j)  = *(path + j + 1);
				*(path + j + 1) = temp;
			}
		}
	}

	for (int k=0; k <len-1; k++){
		cout << *(path + k) << ",";
	}

}

int main(){
	int* path = new int[32];
	// Initializetion seed
	srand(time(nullptr));

	// Zufall zwischen 0 and 100
	for (int i=0; i < 32; i++){
		*(path + i)+ = rand() % 101;
	}

	bubblesort(path, 32);
	delete[] path;
}
