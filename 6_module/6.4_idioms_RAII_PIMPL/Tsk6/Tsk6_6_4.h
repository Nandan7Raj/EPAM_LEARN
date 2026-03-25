//
// Created by NandanRaj on 19-03-2026.
//

// #ifndef TSK6_6_4_H
// #define TSK6_6_4_H
#pragma once
#include <memory>
#include <string>

class Widget {
    struct Impl;
    std::unique_ptr<Impl> impl;
public:
    Widget();
    ~Widget();
    Widget(Widget& other)=delete; // as class contain unique ptr
    Widget(Widget&& other)=default;
    Widget& operator=(Widget& other)=delete;
    Widget& operator=(Widget&& other)=default;
    void setName(std::string name);
    void printName();
};

// #endif //MODULES_EPAM_TSK6_6_4_H