//
// Created by NandanRaj on 01-03-2026.
//
#include<iostream>
template<typename...Args>
auto sumAll(Args...args) {
    return (...+args);
}
int main() {
    std::cout<<sumAll(1,2,3.5)<<std::endl;
}