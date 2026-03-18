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
        std::cout<<"constructor\n";
    }

    // copy constructor
    MyString(const MyString& other) {
        this->str = new char[std::strlen(other.str)+1];
        std::strcpy(this->str,other.str);
        std::cout<<"copy constructor\n";
    }

    //copy assignment operator
    MyString& operator=(const MyString& other) {
        if (this!=&other) {
            this->str = new char[std::strlen(other.str)+1];
            std::strcpy(this->str,other.str);
            std::cout<<"copy assignment operator\n";
        }
        return *this;
    }

    // move constructor
    MyString(MyString&& other) noexcept{
        this->str=other.str;
        other.str=nullptr;
        std::cout<<"Move Constructor\n";
    }

    //move assignment operator
    MyString& operator=(MyString&& other) {
        if (this!=&other) {
            this->str=other.str;
            other.str=nullptr;
            std::cout<<"Move assignment operator\n";
        }
        return *this;
    }

    // destructor
    ~MyString() {
        std::cout<<"Destroying memory at add: "<<static_cast<const void*>(str)<<std::endl;
        delete[] str;
    }

    void print(const char* label) const {
        std::cout<<label<<"-->  String: "<<(str?str:"null.. ")<<" | Add: "<<static_cast<const void*>(str)<<std::endl;
    }
};
int main() {
    MyString s1("Nandan");
    // copy constructor
    MyString s2(s1);
    MyString s3("Temp");
    // copy assignment operator
    s3=s2;
    // move constructor
    MyString s4(std::move(s3));

    MyString s5("Temp");
    //move assignment operator
    s5=std::move(s4);
    //Now printing info
    std::cout<<"\nINFO: \n";
    s1.print("S1");
    s2.print("S2");
    s3.print("S3");
    s4.print("s4");
    s5.print("S5");

}