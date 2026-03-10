//
// Created by NandanRaj on 10-03-2026.
//
#include<iostream>
#include<vector>
#include<algorithm>
int main() {
    std::vector<int> v{6,2,9,12,23};
    std::for_each(v.begin(),v.end(),[](int &x){x*=2;});
    std::cout<<"Updated vector: ";
    for (auto&n:v)
        std::cout<<n<<" ";
    std::cout<<std::endl;

}