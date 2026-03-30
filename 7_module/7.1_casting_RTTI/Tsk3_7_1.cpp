//
// Created by NandanRaj on 25-03-2026.
//
#include <iostream>
void ConstModification(const int* ptr) {
    int* modPtr=const_cast<int*>(ptr);
    std::cout<<"[ConstModification func]: modification attempted\n";
    *modPtr=8; // changed value
}
int main() {
    // Unsafe const Modification
    const int x=7;
    ConstModification(&x);//UB, my crash or work
    std::cout<<"When obj itself is declared const\n"
    <<"Value of x after const_cast and update is :"<<x<<std::endl;

    // Safe const modification
    int y=9;
    const int* ptrY=&y;
    ConstModification(ptrY);
    std::cout<<"When obj is not const \n"
    <<"Value of x after const_cast and update is :"<<x<<std::endl;

    return 0;
}