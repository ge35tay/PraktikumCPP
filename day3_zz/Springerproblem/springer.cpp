/**
 * @file springer.cpp
 * @author Yinghan Huang 03728454 and Zhishen Zhang 03736826
 * @brief
 * @version 0.1
 * @date 2022-04-01
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <vector>
using namespace std;

int step_x[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int step_y[8] = {1, 2, 2, 1, -1, -2, -2, -1};

std::vector<std::vector<int> > board(8, std::vector<int>(8, 0));

bool onBoardAndEmpty(int x, int y)
{
    if (x < 8 && x >= 0 && y < 8 && y >= 0 && !board[x][y])
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool springer(int x, int y, int step)
{
    if (step > 64)
    {
        return true;
    }
    for (int i = 0; i < 8; i++)
    {
        int x_next = x + step_x[i];
        int y_next = y + step_y[i];
        if (onBoardAndEmpty(x_next, y_next))
        {
            board[x_next][y_next] = step;
            if (springer(x_next, y_next, step+1))
            {
                return true;
            }
            board[x_next][y_next] = 0; // This is the high light of this solution!!!
        }
    }

    return false;
}

int main()
{

    board[0][0] = 1;
    springer(0, 0, 2);


    std::cout<<"Check the results: "<<std::endl;


    int sum = 0;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            cout <<"\t" <<board[i][j];
            sum+=board[i][j];
        }
        cout << endl;
    }

    std::cout<<"Check if the sum is 2080: "<<std::endl;
    std::cout<<"sum is: "<<sum<<std::endl;
    
    return 0;
}