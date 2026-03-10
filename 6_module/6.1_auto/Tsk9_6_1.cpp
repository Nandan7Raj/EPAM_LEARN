//
// Created by NandanRaj on 05-03-2026.
//
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec{1, 2, 3, 4, 5};   // Uniform initialization

    std::cout << "Elements in vec: ";
    for (auto x : vec)
        std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}
