//
// Created by NandanRaj on 03-03-2026.
//
#include <iostream>
#include <typeinfo>
template<typename T>
void showType(T t) {
    std::cout << "Value: " << t << "\n";
    std::cout << "Deduced type: " << typeid(T).name() << "\n";
}
int main() {
    showType(10);    // int
    showType(3.14);  // double
    showType("Nandan"); // string
    return 0;
}
