
#include <iostream>
#include <cstdlib>
#include <ctime>
int main()
{

    srand(time(nullptr));
    int n = rand()%10+10;

    printf("n: %d\n",n);
}