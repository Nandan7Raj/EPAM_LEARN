//
// Created by NandanRaj on 05-03-2026.
//
#include<iostream>
#include<vector>
int main() {
    std::vector<int> v{1,2,3,4,5};
    for (auto it=v.begin();it!=v.end();++it) {
        std::cout<<*it<<" ";
    }
    std::cout << std::endl;

    return 0;
}