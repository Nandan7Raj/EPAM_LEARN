//
// Created by NandanRaj on 12-03-2026.
//
#include <cstring>
#include<iostream>
class MyString {
    char* str;
public:
    MyString(const char* str) {
        this->str=new char[std::strlen(str)+1];
        std::strcpy(this->str,str);
    }
    // copy constructor
    MyString(const MyString& other) {
        this->str=new char[std::strlen(other.str)+1];
        std::strcpy(this->str,other.str);
    }
    ~MyString() {
        delete[] str;
    }
    void printStr() const {
        std::cout<<"String: "<<str<<" at: "<<static_cast<const void*>(str)<<std::endl;
    }
};
int main() {
    MyString s1("Nandan");
    MyString s2=s1;
    s1.printStr();
    s2.printStr();
}

// 1. The std::cout trap with char*
// Normally, if you pass a pointer to std::cout, it prints
// the memory address. However, std::cout has a special
// built-in overload for character pointers (char*).
//
// When std::cout sees a char* (like your str variable),
// it assumes you want to print a C-style word. It will
// go to that memory address and print every character
// it finds until it hits a null terminator (\0).
//
// std::cout << str outputs: Nandan
//
// 2. The static_cast<const void*> solution
// Because std::cout insists on printing the text of a
// char*, you have to disguise the pointer if you want
// to see the actual memory address.
//
// By casting str to a const void*, you are telling the
// compiler: "Treat this as a generic, raw memory address.
// Forget that it points to characters." When
// std::cout sees a void*, it defaults back to printing the raw hexadecimal memory address.
//
// std::cout << static_cast<const void*>(str) outputs something like: 0x7ffee1b4a0