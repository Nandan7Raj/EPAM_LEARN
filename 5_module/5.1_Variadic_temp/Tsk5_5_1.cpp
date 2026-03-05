//
// Created by NandanRaj on 02-03-2026.
//
#include<iostream>

void printAll()
{
    std::cout<<std::endl;
}
template<typename...Args>
void printAll(int a,Args...args) {
    std::cout<<a<<" ";
    printAll(args...);
}
int main() {
    printAll(1,2,3);
    printAll(23);
    printAll();

}