/**
 * @file rekursion.cpp
 * @author Yinghan Huang 03728454 and Zhishen Zhang 03736826
 * @brief 
 * @version 0.1
 * @date 2022-04-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

int factorialRec(int n);
int factorialIter(int n);

int main(){

    int n = 5 ; 
    
    std::cout<<factorialIter(n)<<std::endl;
    std::cout<<factorialRec(n)<<std::endl;
    
    return 0;
}


int factorialIter(int n){
    int result = 1;
    for(int i =1;i<=n;i++){
        result *=i;
    }
    return result;
}

int factorialRec(int n){

    if(n==1){
        return n;
    }
    return n*factorialRec(n-1);
}