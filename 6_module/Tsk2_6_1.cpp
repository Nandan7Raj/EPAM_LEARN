//
// Created by NandanRaj on 05-03-2026.
//
#include<iostream>
#include <typeinfo>
int main() {
    auto a=5+2.5;
    auto b=3*1.5f;
    std::cout<<"auto a=5+2.5; type: "<<typeid(a).name()<<", value: "<<a<<std::endl;
    std::cout<<"auto b=3*1.5f;; type: "<<typeid(b).name()<<", value: "<<b<<std::endl;
}