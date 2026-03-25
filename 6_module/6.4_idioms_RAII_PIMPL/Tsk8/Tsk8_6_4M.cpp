//
// Created by NandanRaj on 20-03-2026.
//
#include "Tsk8_6_4.h"

int main() {
    Widget w1;
    w1.setName("PIMPL Tsk 8");
    w1.printData();

    std::cout << "--- copy constructor ---\n";
    Widget w2(w1);
    w2.printData();

    std::cout << "--- copy assignment ---\n";
    Widget w3;
    w3 = w1;
    w3.printData();

    std::cout << "--- move constructor ---\n";
    Widget w4(std::move(w1));
    w4.printData();

    std::cout << "--- move assignment ---\n";
    Widget w5;
    w5 = std::move(w2);
    w5.printData();
    return 0;
}
