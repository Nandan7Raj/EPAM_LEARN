//
// Created by NandanRaj on 19-03-2026.
//
#include "Tsk7_6_4.h"
#include <iostream>
#include<cstring>
struct Widget::Impl{
char* name;
    Impl(const char* name) {
        this->name=new char[std::strlen(name)+1];
        std::strcpy(this->name,name);
        std::cout<<"Constructor in Impl : Name: "<<name<<" @ "
        <<static_cast<const void*>(this->name)<<std::endl;
    }
    // destructor
    ~Impl() {
        std::cout<<"DESTRUCTOR OF Impl: freeing memory\n";
        delete [] name;
    }
};

Widget::~Widget() = default;

Widget::Widget(const char* name):impl(std::make_unique<Impl>(name)) {
    std::cout<<"Widget constructor\n";
}


void Widget::printName() const{
    std::cout<<"Name"<<impl->name<<std::endl;
}
