/*
 * Springer.cpp
 *
 *  Created on: 30.03.2022
 *      Author: Yinghan Huang
 */

#include <iostream>
#include <stdlib.h>


/* Since springer move in (2, 1) or (1, 2) in order to represent
the choices of movement in each feld more elegantly expand the
Schachbrett 2 columns and 2 rows outside the rand, so that in each
feld there are 8 actions to choose, the expanded felds  are regarded as
visited*/

/*
int Schachbrett[12][12] = {0};

// num of visted feld
int num_besuched_feld = 0;
// num of allowed pfad
int sum_pfad = 0;

int move[8][2] = {{2,1}, {-2,-1}, {-2, 1}, {2, -1}, {1, 2}, {-1, -2}, {-1, 2}, {1, -2}};
void showbrett();
void Springer(int x, int y);

int main(void){
	for(int i=0; i<12; i++){
		for(int j=0; j<12; j++){
			if(i==0 || i==1 || i==10 || i==11 || j==0 || j==1 || j==10 || j==11){
				Schachbrett[i][j]=-1;
				// ban the expanded felds
			}
		}
	}

	// set the start point
	Schachbrett[2][2] = ++num_besuched_feld;
	std::cout << 1 << std::endl;
	Springer(2, 2);
	return 0;
}

void Springer(int x, int y){

	// x,y is where the springer stand


	for(int i=0; i<8; i++){
		// a,b is the next feld after move[i]
		int a = x + move[i][0];
		int b = y + move[i][1];
		if(Schachbrett[a][b] == 0){
			num_besuched_feld++;
			Schachbrett[a][b] = num_besuched_feld;  // besuched
			if(num_besuched_feld == 64){
					sum_pfad++;
					showbrett();
					return;
			}
			else{
				Springer(a, b);
			}
			// if the last rekursion failed then sign the next step as not besuched
			num_besuched_feld--;
			Schachbrett[a][b] = 0;
		}
	}
}

void showbrett(){
	std::cout << sum_pfad << "th mögliche Lösung" <<std::endl;
	for(int i=2; i<10; i++){
		for(int j=2; j<10; j++){
			std::cout << " " << Schachbrett[i][j];
		}
		std::cout << std::endl;
	}
}
*/

/*
typedef struct{
	int x;           // coord x
	int y;			 // coord y
	int i;			 // action number i
}StackSpringer;
*/
int StackSpringer[100][3] = {0};
int Schachbrett[12][12] = {0};

// num of visted feld
int num_besuched_feld = 1;
// num of allowed pfad

int move[8][2] = {{2,1}, {-2,-1}, {-2, 1}, {2, -1}, {1, 2}, {-1, -2}, {-1, 2}, {1, -2}};
void showbrett();
void Springer(int x, int y);

int main(void){
	for(int i=0; i<12; i++){
		for(int j=0; j<12; j++){
			if(i==0 || i==1 || i==10 || i==11 || j==0 || j==1 || j==10 || j==11){
				Schachbrett[i][j]=-1;
				// ban the expanded felds
			}
		}
	}

	// set the start point
	Springer(2, 2);
	showbrett();
	return 0;
}

void Springer(int x, int y){
	int top=0, i=0;
	int a,b;
	Schachbrett[x][y] = 1;
	StackSpringer[top][0] = StackSpringer[top][1] = 2;
	while(num_besuched_feld<64)
	{
		for(; i<8; i++){
				// a,b is the next feld after move[i]
			int a = x + move[i][0];
			int b = y + move[i][1];
			if(Schachbrett[a][b] == 0){
				break;
			}
		}
		if(i<8){
			Schachbrett[a][b] = ++num_besuched_feld;
			StackSpringer[top][2] = i;
			top++;
			StackSpringer[top][0] = a;
			StackSpringer[top][1] = b;
			x = a;
			y = b;
			i = 0;
		}
		else{
			num_besuched_feld--;
			Schachbrett[x][y] = 0;
			top--;
			x = StackSpringer[top][0];
			y = StackSpringer[top][1];
			i = StackSpringer[top][2];
			i++;
		}
	}
	// x,y is where the springer stand
}

void showbrett(){
	std::cout << "mögliche Lösung" <<std::endl;
	for(int i=2; i<10; i++){
		for(int j=2; j<10; j++){
			std::cout << " " << Schachbrett[i][j];
		}
		std::cout << std::endl;
	}
}
