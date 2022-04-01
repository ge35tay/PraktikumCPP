/*
 * Springer.cpp
 *
 *  Created on: 30.03.2022
 *      Author: Yinghan Huang
 */

#include <iostream>
#include <stdlib.h>
#include <vector>

/* Since springer move in (2, 1) or (1, 2) in order to represent
the choices of movement in each feld more elegantly expand the
Schachbrett 2 columns and 2 rows outside the rand, so that in each
feld there are 8 actions to choose, the expanded felds  are regarded as
visited*/

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
	num_besuched_feld++;
	Schachbrett[3][3] = num_besuched_feld;
	std::cout << 1 << std::endl;
	Springer(3, 3);
	return 0;
}
std::vector<int> showtheremainway(int x, int y){
	int min_reain_way = 9;
	int num_remain_way = 0;
	std::vector<int> maybe_right_next(2);
	for(int k=0; k<8; k++){
		int next_i = x + move[k][0];
		int next_j = y + move[k][1];
		for (int l=0; l<8; l++){
			int next_i_i = next_i + move[l][0];
			int next_j_j = next_j + move[l][1];
			if(Schachbrett[next_i_i][next_j_j] == 0){
				num_remain_way++;
			}
		}
		if (min_reain_way > num_remain_way){
			min_reain_way = num_remain_way;
			maybe_right_next[0] = next_i;
			maybe_right_next[1] = next_j;
		}
	}
	return maybe_right_next;
}

void Springer(int x, int y){

	// x,y is where the springer stand
	std::vector<int> next(2);
	int a_next = 0;
	int b_next = 0;
	//int min_remain_ways = 100;
	for(int i=0; i<8; i++){
		// a,b is the next feld after move[i]
		int a = x + move[i][0];
		int b = y + move[i][1];
		if(Schachbrett[a][b] == 0){
			next = showtheremainway(a, b);
			a_next = next[0];
			b_next = next[1];
			num_besuched_feld++;
			Schachbrett[a][b] = num_besuched_feld;
			if(num_besuched_feld == 64){
				printf("sb");
				sum_pfad++;
				showbrett();
				num_besuched_feld = 0;
				//return;
			}
			else{
				num_besuched_feld++;
				Schachbrett[a][b] = num_besuched_feld;
				Springer(a_next, b_next);
			}
		}


		num_besuched_feld--;
		Schachbrett[a][b] = 0;
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


/*
typedef struct{
	int x;           // coord x
	int y;			 // coord y
	int i;			 // action number i
}StackSpringer;
*/
/*
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
*/
