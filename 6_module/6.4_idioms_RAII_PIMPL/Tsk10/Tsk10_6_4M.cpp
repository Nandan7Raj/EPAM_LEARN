//
// Created by NandanRaj on 21-03-2026.
//
#include <iostream>
#include "Tsk10_6_4.h"
int main() {
    {
        NetworkConnection con1("127.0.0.1:8080");
        con1.sendData("Hey! Are you ready?");

        NetworkConnection conn2("192.168.1.5:7000");
        conn2.sendData("Quick check");
    }
    std::cout << "All connections closed  (destructor)." << std::endl;

}