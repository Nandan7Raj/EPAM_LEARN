//
// Created by NandanRaj on 27-02-2026.
//
#include<iostream>
void printAll() {
}
template<typename T,typename ...Args>
void printAll(T first,Args...args )
{

    std::cout<<first<<" ";
    printAll(args...);
}


int main() {
    printAll(1,2.5,"Hello");
    std::cout<<std::endl;
}