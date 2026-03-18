//
// Created by NandanRaj on 16-03-2026.
//
#include<iostream>
#include<cstring>
#include<utility>
class MyString {
public:
    char* str;
    MyString(const char* str) {
        this->str=new char[std::strlen(str)+1];
        std::strcpy(this->str,str);
        std::cout<<"CONSTRUCTOR: "<<"String :"<<this->str<<" @ "<<static_cast<const void*>(this->str)<<std::endl;
    }
    // copy constructor
    MyString(const MyString& other) {
        this->str=new char[std::strlen(other.str)+1];
        std::strcpy(this->str,other.str);
        std::cout<<"COPY CONSTRUCTOR: ""String :"<<this->str<<" copied from @ "<<static_cast<const void*>(other.str)<<" to @ "<<static_cast<const void*>(str)<< std::endl;
    }
    // move constructor
    MyString(MyString&& other) noexcept:str(other.str) {
        other.str=nullptr;
        std::cout<<"MOVE CONSTRUCTOR: "<<"String :"<<this->str<<" @ "<<static_cast<const void*>(this->str)<<"is moved"<<std::endl;

    }
    // // move assignment operator
    // MyString& operator=(MyString&& other) noexcept {
    //     if (this!=&other) {
    //         delete [] str;
    //         this->str=other.str;
    //         other.str=nullptr;
    //         std::cout<<"MOVE ASSIGNMENT: "<<"String :"<<this->str<<" @ "<<static_cast<const void*>(this->str)<<"is moved"<<std::endl;
    //     }
    //     return *this;
    // }

    ~MyString() {
        std::cout << "Destructed " << (str ? str : "null") << " at " << static_cast<const void*>(str) << "\n";
        delete[] str;
    }
    // print method
    void print(const char* tag) const {
        std::cout<<tag<<" --> string: "<<(str?str:" null ")<<" @ "<<static_cast<const void*>(str)<<std::endl;
    }
};
// function to print internal buffer address
void printAddress(MyString&& s) {
    std::cout<<"String: "<<s.str<<" | Internal Buffer address: "<<static_cast<const void*>(s.str)<<std::endl;
}
// template
template <typename T>
void forwardToPrint(T&& str) {
    printAddress(std::forward<T>(str));
}

int main() {
MyString s1("lvalue");
    printAddress(std::move(s1)); // move s1
    s1.print("s1");
    std::cout<<"-------"<<std::endl;

    printAddress(MyString("rvalue"));            // Moves the temp
    std::cout << "--- Forwarding ---" << std::endl;

    forwardToPrint(MyString("temp"));            // Forwards rvalue (calls move)
    forwardToPrint(std::move(s1));               // Forwards rvalue for moved-from s1

    // Uncomment to see the difference when passing lvalue (would not compile if printAddress only takes rvalue)
    // MyString s2("test");
    // forwardToPrint(s2);    // Would cause compilation error unless you accept lvalue
}