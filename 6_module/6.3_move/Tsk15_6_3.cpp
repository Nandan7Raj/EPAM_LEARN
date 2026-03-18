//
// Created by NandanRaj on 17-03-2026.
//
#include<iostream>
#include <memory>
#include<vector>
#include<string>
class ModernResources {
    std::vector<int> vec;
    std::shared_ptr<int> ptr;
    std::string str;
public:
    ModernResources(std::initializer_list<int> d,int val,std::string str):str(std::move(str)),
    vec(d),ptr(std::make_shared<int>(val)) {
        std::cout<<"Constructor: \n";
    }
    void print(const char* tag) const{
        std::cout<<tag<<" "<<str<< std::endl;
        for (int x:vec) // why int &x caused problem
            std::cout<<x<<" ";
        std::cout << " | meta=" << *ptr << std::endl;

    }

};
int main() {
    ModernResources modRes1({2,4,6},5,"Nandan");
    ModernResources modRes2= modRes1;
    ModernResources modRes3({3,4},7,"Raj");
    modRes3 = std::move(modRes1);               // move
    modRes2.print("m2:");
    modRes3.print("m3:");
}