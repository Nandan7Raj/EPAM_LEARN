//
// Created by NandanRaj on 10-03-2026.
//
#include<iostream>
struct Add {
    int operator()(int a,int b) const {
        return a+b;
    }
};
    int main() {
        Add add;
        std::cout<<"sum of 2 and 3 : "<<add(2,3)<<std::endl;
        std::cout<<"sum of 5 and 4 : "<<add(4,5)<<std::endl;
    }

