//
// Created by NandanRaj on 25-03-2026.
//
#include <iostream>

int main() {
    int a = 10;
    double b = 3.7;
    // c style casting
    double d1=(double)a; // int to double
    int i1= int(b); // double to int

    // c++ casting
    double d2 = static_cast<double>(a);
    int i2 = static_cast<int>(b);

    std::cout << "C-style cast int to double: d1 = " << d1 << std::endl;
    std::cout << "C-style cast double to int: i1 = " << i1 << " (truncates)" << std::endl;
    std::cout << "static_cast int to double: d2 = " << d2 << std::endl;
    std::cout << "static_cast double to int: i2 = " << i2 << " (truncates)" << std::endl;
}