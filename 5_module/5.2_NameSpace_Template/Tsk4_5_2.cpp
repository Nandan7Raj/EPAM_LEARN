//
// Created by NandanRaj on 03-03-2026.
//
#include<iostream>
#include <ranges>

template<typename T>
class Box {
    T value;
public:
   explicit  Box(T v);
    void print() const;
};

template<typename T>
Box<T>::Box(T v):value(v) {}
template<typename  T>
void Box<T>::print() const {
   std::cout<<"Value: "<<value<<std::endl;
}
int main() {
    Box<int> intBox(43);
    Box<std::string> strBox("Nandan");

    intBox.print();
    strBox.print();
    return 0;
}
