//
// Created by NandanRaj on 19-03-2026.
//

#ifndef TSK8_6_4_H
#define TSK8_6_4_H
#include <memory>
#include<iostream>

class Widget {
    struct Impl;

    std::unique_ptr<Impl> impl;
public:
    Widget();
    ~Widget();
    Widget(const Widget& other); // copy cnstr
    Widget& operator=(const Widget& other); // copy assign
    Widget(Widget&& other) noexcept; // move cnstr
    Widget& operator=(Widget&& other) noexcept; // move assign

    void setName(const std::string& name);
    void printData() const;
};

#endif //MODULES_EPAM_TSK8_6_4_H