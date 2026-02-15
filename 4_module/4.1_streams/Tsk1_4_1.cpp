//
// Created by NandanRaj on 13-02-2026.
//
#include <iostream>
int main() {
    std::string name,city;
    int age;
    std::cout<<"Enter name: ";
    getline(std::cin,name);
    std::cout<<"Enter city: ";
    getline(std::cin,city);
    std::cout<<"Enter age: ";
    std::cin>>age;
    std::cout<<"\nHello "<<name<<" ,you are "<<age<<" and live in "<<city<<"\n";
}