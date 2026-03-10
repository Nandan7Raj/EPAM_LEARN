//
// Created by NandanRaj on 05-03-2026.
//
#include<iostream>
#include<vector>
#include<initializer_list>
class Numbers {
public:
    std::initializer_list<int> data;
    Numbers(std::initializer_list<int> list):data(list){};
};
int main() {
    Numbers nums{23,34,45,56,67};
    std::cout << "Numbers: ";
    for (auto x : nums.data) { // auto deduces as int
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}