//
// Created by NandanRaj on 10-03-2026.
//
#include<iostream>
int main() {
    auto add = [](int a, int b){ return a + b; };
    int result = add(5, 10);
    std::cout << "Sum: " << result << std::endl;
    return 0;
}
