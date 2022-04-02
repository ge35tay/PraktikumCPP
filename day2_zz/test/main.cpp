/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-01
 * 
 * @copyright Copyright (c) 2022
 * 
 * Answer: 
 * 0: 
 * A ist ein Set, B ist ein subset von A, C ist ein Subset von B
 * Vererbung von A an B ist public
 * Vererbung von B and C ist public
 */

#include "polymorphie.hpp"




int main()
{

    A a = A();
    a.f();
    B b = B();
    b.g();
    C c = C();
    c.g();
    printf("####\n");
    // B b0 = A();
    // b0.g();
    A a1 = B();
    a1.f();
    printf("####\n");
    A a2 = b;
    a2.f();
    printf("####\n");
    A *a3 = &b;
    a3->f();
    return 0;
}