//
// Created by NandanRaj on 10-03-2026.
//
#include <algorithm>
#include<iostream>
#include<vector>
struct MultiplyBy {
    int factor;
    void operator()(int& x) const{
        x*=factor;
    }
};
int main() {
    std::vector<int> vec{2,3,4,5};
    std::for_each(vec.begin(),vec.end(),MultiplyBy{3});
    std::cout<<"Modified vector: ";
    for (auto & n:vec)
        std::cout<<n<<" ";
    std::cout<<std::endl;
}