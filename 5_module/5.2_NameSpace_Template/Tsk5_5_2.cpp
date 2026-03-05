//
// Created by NandanRaj on 03-03-2026.
//
#include<iostream>
#include <string>
template<typename T>
class Box {
    T value;
public:
    Box(T v): value(v){}
    void print() const {
        std::cout<<value<<std::endl;
    }
};
template<>
class Box<std::string> {
    std::string value;
public:
    Box(std::string v): value(std::move(v)){}
    void print() const {
        for (auto c:value)
            std::cout<<static_cast<char>(toupper(static_cast<unsigned char>(c)));
        std::cout<<std::endl;

    }
};
int main() {
    Box<std::string> boxStr("hello, Templates!");
    boxStr.print(); // Prints: HELLO, TEMPLATES!
    return 0;
}