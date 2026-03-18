//
// Created by NandanRaj on 12-03-2026.
//

#include<iostream>
#include<cstring>

class MyString {
    char* str;
public:

    //constructor
    MyString(const char* str) {
        this->str=new char[std::strlen(str)+1];
        std::strcpy(this->str,str);
        std::cout<<"Constructor\n";
    }

    // copy constructor (Deep copy)
    MyString(const MyString& other) {
        this->str= new char[std::strlen(other.str)+1];
        std::strcpy(this->str,other.str);
        std::cout<<"Copy constructor\n";
    }

    // copy assignment operator
    MyString& operator=(const MyString& other) {
        if (this!=&other){
            delete[] str;
            this->str= new char[std::strlen(other.str)+1];
            std::strcpy(this->str,other.str);
            std::cout<<"Copy assignment operator\n";
        }
        return *this;
    }

    ~MyString() {
        delete[] str;
    }

    void print(const char* lable) {
        std::cout<<lable<<" -->  String: "<<str<<" Add: "<<static_cast<const void*>(str)<<std::endl;
    }
};

int main() {
    MyString s1("Nandan");
    MyString s2=s1;
    s2=s1;
    s1.print("S1");
    s2.print("S2");
}