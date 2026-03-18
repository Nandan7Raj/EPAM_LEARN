//
// Created by NandanRaj on 14-03-2026.
//
#include<iostream>
#include<cstring>
class MyString {
    char* s;
public:
    MyString(const char* s) {
        this->s=new char[std::strlen(s)+1];
        std::strcpy(this->s,s);
        std::cout<<"constructor\n";
    }
    // copy constructor
    MyString(const MyString& other) {
        this->s=new char[std::strlen(other.s)+1];
        std::strcpy(this->s,other.s);
        std::cout<<"copy constructor: copy from add: "<<static_cast<const void*>(s)<<"to add: "<<static_cast<const void*>(s)<<std::endl;
    }
    // move constructor
    MyString(MyString&& other)  noexcept:s(other.s) {
        other.s=nullptr;
        std::cout<<"move constructor: moved the ownership of string @ add: "<<static_cast<const void*>(s)<<std::endl;
    }
    ~MyString() {
        std::cout<<"DESTRUCTOR: freeing memory @ "<<static_cast<const void*>(s)<<std::endl;
        delete [] s;
    }
    void print(const char* tag) const {
        std::cout<<tag<<"--> string: "<<s<<" @ "<<static_cast<const void*>(s)<<std::endl;
    }

};
MyString makestring() {
    MyString s("Nandan");
    return s;
}
int main() {
    MyString s1=makestring();
    s1.print("s1");

}