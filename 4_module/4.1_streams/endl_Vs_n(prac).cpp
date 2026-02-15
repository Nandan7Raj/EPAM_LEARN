//
// Created by NandanRaj on 13-02-2026.
//
#include <iostream>
#include <fstream>
#include<thread>
using namespace std;
int main() {
    std::fstream file{"temp.txt"};
    // string s;
    file << "Hello there!";
    this_thread::sleep_for(chrono::milliseconds(2000));
    file<<" ww";
}