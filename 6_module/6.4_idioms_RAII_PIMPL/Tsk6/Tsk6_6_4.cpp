//
// Created by NandanRaj on 19-03-2026.
//
#include "Tsk6_6_4.h"
#include<iostream>

// struct Impl
struct Widget::Impl {
    std::string name;
};
Widget::Widget():impl(std::make_unique<Impl>()){}
Widget::~Widget() = default;

void Widget::setName(std::string name){
    impl->name=std::move(name);
}
void Widget::printName() {
    std::cout<<"Name: "<<impl->name<<std::endl;
}

