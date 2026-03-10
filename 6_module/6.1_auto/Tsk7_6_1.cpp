//
// Created by NandanRaj on 05-03-2026.
//
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v{1, 2, 3, 4, 5};

    // Const reference range-based for loop
    std::cout << "Elements (const ref): ";
    for (const auto& x : v) {
        std::cout << x << " ";
        // x = 42; // Uncommenting this line causes a compile-time error!
    }
    std::cout << std::endl;

    return 0;
}
