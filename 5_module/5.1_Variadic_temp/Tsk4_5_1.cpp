//
// Created by NandanRaj on 01-03-2026.
//
#include <iostream>
#include<string>

//
// Created by NandanRaj on 01-03-2026.
//
#include <iostream>
#include<string>

void process(int &args) {
    std::cout<<args<<" int Lvalue\n";
}
void process(double &args) {
    std::cout<<args<<" double Lvalue\n";
}
void process(char &args) {
    std::cout<<args<<" char Lvalue\n";
}
void process(std::string &args) {
    std::cout<<args<<" string Lvalue\n";
}
void process(int &&args) {
    std::cout<<args<<" int Rvalue\n";
}
void process(double &&args) {
    std::cout<<args<<" double Rvalue\n";
}
void process(char &&args) {
    std::cout<<args<<" char Rvalue\n";
}
void process(std::string &&args) {
    std::cout<<args<<" string Rvalue\n";
}

template<typename...Args>
void forwardAll(Args&&...args) {
    (process(std::forward<Args>(args)),...);
}
int main() {
    int x=5;
    forwardAll(x,2.5,std::string("hello"),100);
    forwardAll(std::string("temp"), x + 1);
}
void process(int &args) {
    std::cout<<args<<" int Lvalue\n";
}
void process(double &args) {
    std::cout<<args<<" double Lvalue\n";
}
void process(char &args) {
    std::cout<<args<<" char Lvalue\n";
}
void process(std::string &args) {
    std::cout<<args<<" string Lvalue\n";
}
void process(int &&args) {
    std::cout<<args<<" int Rvalue\n";
}
void process(double &&args) {
    std::cout<<args<<" double Rvalue\n";
}
void process(char &&args) {
    std::cout<<args<<" char Rvalue\n";
}
void process(std::string &&args) {
    std::cout<<args<<" string Rvalue\n";
}

template<typename...Args>
void forwardAll(Args&&...args) {
    (process(std::forward<Args>(args)),...);
}
int main() {
    int x=5;
    forwardAll(x,2.5,std::string("hello"),100);
    forwardAll(std::string("temp"), x + 1);
}