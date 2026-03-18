//
// Created by NandanRaj on 16-03-2026.
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
        std::cout<<"constructor\n";
    }

    // copy constructor
    MyString(const MyString& other) {
        this->str = new char[std::strlen(other.str)+1];
        std::strcpy(this->str,other.str);
        std::cout<<"copy constructor\n";
    }

    // move constructor
    MyString(MyString&& other) noexcept{
        this->str=other.str;
        other.str=nullptr;
        std::cout<<"Move Constructor\n";
    }


    // destructor
    ~MyString() {
        std::cout<<"Destroying memory at add: "<<static_cast<const void*>(str)<<std::endl;
        delete[] str;
    }

    void print(const char* label) const {
        std::cout<<label<<"-->  String: "<<(str?str:"null.. ")<<" | Add: "<<static_cast<const void*>(str)<<std::endl;
    }

    void safeReset(const char* s) {
        delete [] str;
        str= new char[std::strlen(s) + 1];
        std::strcpy(str,s);
    }
};
int main() {
    MyString s1("hello");
    MyString s2 = std::move(s1);

    s1.print("s1 (moved-from): ");
    s2.print("s2 (moved-to): ");

    // Safe: assign, reset, or destroy moved-from object
    s1.safeReset("reset ok");
    s1.print("s1 (after reset): ");

    // Unsafe: using data pointer directly (may be nullptr)
    // std::cout << s1.data[0];  // Dangerous! Don't do this!

    return 0;
}

