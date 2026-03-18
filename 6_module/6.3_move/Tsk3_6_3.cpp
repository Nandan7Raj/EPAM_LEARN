//
// Created by NandanRaj on 12-03-2026.
//
#include<iostream>
#include<cstring>
class MyString {
    char* str;
public:
    MyString(const char* str) {
        this->str=new char[std::strlen(str)+1];
        std::strcpy(this->str,str);
        std::cout<<"constructor\n";
    }
    // copy constructor
    MyString(const MyString& other) {
        this->str= new char[std::strlen(other.str)+1];
        std::strcpy(this->str,other.str);
        std::cout<<"Copy Constructor\n";
    }

    // Copy Assignment operator
    MyString& operator=(const MyString& other) {
        if (this!=&other) {
            delete[] str;
            this->str=new char[std::strlen(other.str)+1];
            std::strcpy(this->str,other.str);
            std::cout<<"Copy assignment operator\n";
        }
        return *this;
    }
    //If you strictly wanted to, you could make
    //the return type void and skip the return *this;
    //line. s1 = s2; would still work perfectly.
    //But returning *this is the universal C++ standard
    //simply because it prevents breaking the expected
    //chaining behavior.


    // move constructor
    MyString(MyString&& other)  noexcept {
        this->str=other.str;
        other.str=nullptr;
        std::cout<<"Move Constructor\n";
    }

    ~MyString() {
        delete[] str;
    }
    void print(const char* label) const {
        std::cout<<label<<"-->  String: "<<(str?str:"null")<<" Add: "<<static_cast<const void*>(str)<<std::endl;
    }

};
int main() {
    MyString s1("Nandan");
    MyString s2=std::move(s1);
    s1.print("S1");
    s2.print("S2");
}