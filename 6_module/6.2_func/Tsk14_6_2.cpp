//
// Created by NandanRaj on 10-03-2026.
//
#include<iostream>
int main() {
    int counter=0;
    // capturing by value
    auto inc = [counter]() mutable  {
        counter++;
        std::cout<<" Inside lambda after increment: "<<counter<<std::endl;
    };
    inc();
    std::cout<<" Outside lambda after increment: "<<counter<<std::endl;
    // capturing by reference
    auto incRef = [&counter]() mutable  {
        counter++;
        std::cout<<" Inside lambda after increment: "<<counter<<std::endl;
    };
    incRef();
    std::cout<<" Outside lambda after increment: "<<counter<<std::endl;
}