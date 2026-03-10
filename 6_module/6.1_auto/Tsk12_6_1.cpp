//
// Created by NandanRaj on 05-03-2026.
//
#include<iostream>
#include <vector>

int main() {
    std::vector<std::vector<int>> mat{{1,2},{3,4}};
    std::cout << "Matrix elements:" << std::endl;
    for (auto& row:mat) {
        std::cout<<"| ";
        for (auto &x:row) {
            std::cout<<x<<" ";
        }
        std::cout<<"|\n";
    }
    return 0;
}
