//
// Created by NandanRaj on 05-03-2026.
//
#include<iostream>
#include <vector>
#include<initializer_list>

class Numbers {
    std::vector<int> data;
public:
    Numbers(std::initializer_list<int> list):data(list){};
    void print() const {
        std::cout<<"Numbers: ";
        for (auto x:data)
            std::cout<<x<<" ";
        std::cout<<std::endl;
    }
};
int main() {
    Numbers nums{10,12,1,4,1,5,67};
    nums.print();
    return 0;

}
