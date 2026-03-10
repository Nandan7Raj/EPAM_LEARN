//
// Created by NandanRaj on 05-03-2026.
//
#include<iostream>
#include <vector>

std::vector<int> getNumber() {
    return {12,2,3,4,5,6,7};
}
int main() {
    auto nums=getNumber();
    std::cout << "Returned numbers: ";
    for (const auto &x:nums)
        std::cout<<x<<" ";
    std::cout<<std::endl;
}
