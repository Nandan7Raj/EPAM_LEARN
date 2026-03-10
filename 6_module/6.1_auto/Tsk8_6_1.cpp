//
// Created by NandanRaj on 05-03-2026.
//
#include <iostream>
#include <vector>
#include <string>


int main() {
    std::vector<std::pair<int,std::string>> v{{1,"Nandan"},{2,"Abhishek"}};
    for (auto &[num,str]:v) {
        std::cout << "num: " << num << ", str: " << str << std::endl;
    }
    return 0;
}
