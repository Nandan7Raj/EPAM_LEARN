//
// Created by NandanRaj on 10-03-2026.
//
#include<iostream>
#include<vector>
#include<algorithm>

int main() {
    int factor=2;
    std::vector<int> vec{1,3,5};
    std::for_each(vec.begin(),vec.end(),[factor](int&x){x*=factor;});
    std::cout << "After value-capture lambda (factor=3): ";
    for (auto x : vec) std::cout << x << " ";
    std::cout << std::endl;

    // now changing factor and using reference capture
    factor=5;
    std::for_each(vec.begin(),vec.end(),[&factor](int &x){x*=factor;});
    std::cout << "After reference-capture lambda (factor=10): ";
    for (auto x : vec) std::cout << x << " ";
    std::cout << std::endl;
}