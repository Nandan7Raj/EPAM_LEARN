//
// Created by NandanRaj on 05-03-2026.
//
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v{1, 2, 3, 4, 5};

    // Reference loop to modify elements
    for (auto& x : v) {
        x *= 2; // Double each element
    }

    std::cout << "Modified vector (by reference): ";
    for (auto x : v) { // Value loop, prints contents after modification
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Reset and try value-based loop (does NOT modify elements)
    v = {1, 2, 3, 4, 5};
    for (auto x : v) {
        x *= 2; // Modifies only the local copy, not the vector
    }

    std::cout << "Value-based loop (no modification): ";
    for (auto x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
