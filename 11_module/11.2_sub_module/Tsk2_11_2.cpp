//
// Created by NandanRaj on 08-05-2026.
//
#include <iostream>
int main() {
    int* ptr = nullptr;
    {
        int local = 42;
        ptr = &local;
    } // local goes out of scope, ptr now dangling
    std::cout << *ptr << std::endl; // Access violation/undefined behavior!
    return 0;
}