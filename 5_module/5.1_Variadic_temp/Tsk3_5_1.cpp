//
// Created by NandanRaj on 01-03-2026.
//
#include<iostream>
template<typename...Args>
auto sumAll(Args...args) {
    return (args+...);
}
// recursive case

int sumAll() { return 0; }

template<typename T, typename... Args>
auto sumAll(T first, Args... args) {
    return first + sumAll(args...);
}

int main() {
    std::cout<<"sum:"<<sumAll(1,2,3.5)<<std::endl;
    std::cout<<"sum:"<<sumAll(1.9,6,3.5)<<std::endl;
    std::cout<<"sum:"<<sumAll(6.9,6.4,3)<<std::endl;
}