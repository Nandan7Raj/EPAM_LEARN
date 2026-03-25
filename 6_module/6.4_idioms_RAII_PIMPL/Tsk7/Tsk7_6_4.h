//
// Created by NandanRaj on 19-03-2026.
//

#ifndef MODULES_EPAM_TSK7_6_4_H
#define MODULES_EPAM_TSK7_6_4_H
#include <memory>

class Widget {
public:
    Widget(const char* name);
    ~Widget();
    Widget(Widget& other)=delete;
    Widget(Widget&& other)=default;
    Widget& operator=(Widget& other)=delete;
    Widget& operator=(Widget&& other)=default;
    void printName() const;
private:
    struct Impl;
    std::unique_ptr<Impl> impl;

};
#endif //MODULES_EPAM_TSK7_6_4_H