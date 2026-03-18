//
// Created by NandanRaj on 10-03-2026.
//
#include<iostream>
int main(int argc , char *argv[]) {
auto multiply = [](int x,int factor=2) {
    return x*factor;
};
    std::cout<<"One argument: multiply(10): "<<multiply(10)<<std::endl;
    std::cout<<"Two argument: multiply(10,5): "<<multiply(10,5)<<std::endl;
}