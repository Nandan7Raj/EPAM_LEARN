//
// Created by NandanRaj on 05-03-2026.
//
#include <iostream>
int& funcReturningReference() {
    static int x=8;
    return x;
}
// int& funcReturningReference() {
//     int x=8;
//     return x; // dangling
// }

int main() {
    auto x = funcReturningReference();   // x is an int (copy)
    auto& y = funcReturningReference();  // y is an int& (reference)

    std::cout << "x = " << x << " (address: " << &x << ")" << std::endl;
    std::cout << "y = " << y << " (address: " << &y << ")" << std::endl;

    y = 100; // modifies static int in function
    std::cout << "After y = 100, x = " << x << ", y = " << y << std::endl;

    return 0;
}

