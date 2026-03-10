//
// Created by NandanRaj on 10-03-2026.
//
#include<iostream>
int main() {
    int a=2,b=3;
    auto op = [a,&b](int x) {
        return x*a+b;
    };
    std::cout << "op(5): " << op(5) << std::endl; // uses b=3

    b = 100; // Change b by reference
    std::cout << "op(5) after b=100: " << op(5) << std::endl; // uses b=100
}