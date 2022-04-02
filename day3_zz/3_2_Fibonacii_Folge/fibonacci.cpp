/**
 * @file fibonacci.cpp
 * @author  Yinghan Huang 03728454 and Zhishen Zhang 03736826
 * @brief 
 * @version 0.1
 * @date 2022-04-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <vector>
#include <iostream>


std::vector<int> fibRecursion(int n, std::vector<int> fib){
    if (n<=2){
        return fib;
    }
    fib.insert(fib.begin(),0);
    fib.push_back(0);
    for(int i = 0; i<fib.size()-1; i++){
        fib[i] = fib[i] + fib[i+1];
    }
    fib.pop_back();
    return fibRecursion(n -1 ,fib);
}


int main(){
    //initialize the vector to be {1,1}
    std::vector<int> fib;
    fib.push_back(1);
    fib.push_back(1);


    std::vector<int> result;
    result = fibRecursion(11,fib);
    std::cout<<"check the result"<<std::endl;

    for(int i = 0; i<result.size(); i++){
        std::cout<<result[i]<<" ";
    }
    std::cout<<"\n";
    return 0;
}

