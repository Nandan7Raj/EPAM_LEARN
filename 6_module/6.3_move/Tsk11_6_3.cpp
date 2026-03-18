//
// Created by NandanRaj on 16-03-2026.
//
#include<iostream>
#include<vector>
#include<cstring>
class MyString {
    char* str;
public:
    MyString(const char* str) {
        this->str=new char[std::strlen(str)+1];
        std::strcpy(this->str,str);
        std::cout<<"Constructor: constructed string: "<<str<<" @ "<<static_cast<const void*>(this->str)<<std::endl;
    }
    // copy constructor
    MyString(const MyString& other) {
        this->str=new char[std::strlen(other.str)+1];
        std::strcpy(this->str,other.str);
        std::cout<<"Copy Constructor: copied string: "
        <<str<<" from @ "<<static_cast<const void*>(other.str)
        <<" to @ "<<static_cast<const void*>(str)<<std::endl;
    }
    // move constructor
    MyString(MyString&& other) noexcept:str(other.str) {
        other.str=nullptr;
        std::cout<<"Move constructor: moved ownership of string: "
        <<str<<" i.e @ "<<static_cast<const void*>(str)<<std::endl;
    }
    // destructor
    ~MyString() {
        std::cout<<"Destructor: freeing string: "<<(str?str:"null")<<" @ "<<static_cast<const void*>(str)<<std::endl;
        delete [] str;
    }
};
int main() {
    std::vector<MyString> vec;
    MyString a("first");
    MyString b("second");

    std::cout << "\n-- push_back(a) (copy): --" << std::endl;
    vec.push_back(a);         // Calls copy constructor

    std::cout << "\n-- push_back(std::move(b)) (move): --" << std::endl;
    vec.push_back(std::move(b)); // Calls move constructor

    std::cout << "\n-- emplace_back(\"temp\"): --" << std::endl;
    vec.emplace_back("temp"); // Constructs in-place (calls direct constructor)

    std::cout << "\n-- End of main (destructors fire) --" << std::endl;
    return 0;
}

// vector creates buffer of double size when get full
// 1->2->4...