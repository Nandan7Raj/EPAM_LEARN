//
// Created by NandanRaj on 05-03-2026.
//
#include<iostream>
int main() {
    int x=10;
    int *ptr=&x;
    auto p=ptr;
    auto& r=x;
    // Modify via reference
    r = 20;
    // Modify via pointer
    *p = 30;
    std::cout<<"x: "<<x<<'\n';
    std::cout<<"*p: "<<*p<<'\n';
    std::cout<<"r: "<<r<<'\n';

}