//
// Created by NandanRaj on 20-03-2026.
//
#include"Tsk8_6_4.h"


#include <iostream>
#include<string>
#include<cstring>

struct  Widget::Impl{
  std::string name;
  char* buffer;
  Impl():buffer(new char[50]) {
    std::cout << "[Impl] Allocated buffer at "
    <<static_cast<void*>(buffer) << std::endl;
  }
  Impl(const Impl& other):name(other.name),buffer(new char[50]){
    std::cout << "[Impl] Copy ctor, buffer at " << static_cast<void*>(buffer) << std::endl;
    std::strcpy(buffer, other.buffer);
  }
  Impl& operator=(const Impl& other) {
    if (this!=&other) {
      delete [] buffer;
      name=other.name;
      std::strcpy(buffer,other.buffer);
    }
    return *this;
  }
  ~Impl() {
    std::cout << "[Impl] Deleting buffer at " << static_cast<void*>(buffer) << std::endl;
    delete [] buffer;
  }
};

Widget::Widget():impl(std::make_unique<Impl>()) {}

Widget::~Widget()=default;

// copy constructor(deep copy)
Widget::Widget(const Widget &other):impl(std::make_unique<Impl>(*other.impl)) {}

// copy assignment
Widget& Widget::operator=(const Widget& other) {
  if (this != &other) {
    *impl = *other.impl;
  }
  return *this;
}

// move constructor
Widget::Widget(Widget &&other) noexcept:impl(std::move(other.impl)) {}
//Above code :: // Calls unique_ptr's Move Constructor


// (BELOW) This WON'T compile because you can't initialize
// a unique_ptr from another via assignment/copy
// Widget::Widget(Widget&& other) noexcept {
//   impl = other.impl;   // ERROR: Copying unique_ptr is forbidden!
//   other.impl = nullptr;
// }

// move assignment
Widget &Widget::operator=(Widget &&other) noexcept {
  if (this != &other) {
    impl = std::move(other.impl);
  }
  return *this;
}

void Widget::setName(const std::string& name) {
  impl->name=name;
  std::strcpy(impl->buffer,name.c_str());
}

void Widget::printData() const {
  std::cout << "Widget name: " << impl->name << ", buffer: " << impl->buffer << std::endl;
}

