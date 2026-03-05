//
// Created by NandanRaj on 03-03-2026.
//
#include<iostream>
template<typename T=int>// default type of template is int
class Number {
    T value;
public:
    explicit  Number(T v):value(v){}
    void print() {
        std::cout<<value<<std::endl;
    }
};
int main() {
    Number<> n1(100);           // Uses default type int
    Number<double> n2(3.14);    // Uses double

    n1.print();                 // Prints: 100
    n2.print();                 // Prints: 3.14

    return 0;
}
