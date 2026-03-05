//
// Created by NandanRaj on 03-03-2026.
//
#include<iostream>
template<typename T>
T add(T a,T b) {
    return a+b;
}
int main() {
    std::cout<<"int: 3+6 = "<<add(3,6)<<std::endl;
    std::cout<<"double: 2.3345 + 5.321 = "<<add(2.3345 ,5.321)<<std::endl;
    std::cout<<"float: 5.33 + 6.31 = "<<add(5.33 ,6.31 )<<std::endl;
}