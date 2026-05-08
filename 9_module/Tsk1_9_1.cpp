//
// Created by NandanRaj on 15-04-2026.
//
#include<iostream>
#include<thread>
#include <vector>

void printMessage(const std::string& msg) {
    auto id=std::this_thread::get_id();
    std::cout<<"Thread_id: "<<id<<" is printing msg: "<<msg<<std::endl;
}
int main() {
    std::vector<std::thread> Threads;
    for (int i=0;i<5;i++) {
        Threads.emplace_back(printMessage,"Hello from thread " + std::to_string(i + 1));
    }
    for (auto &thd:Threads)
        thd.join();
    std::cout<<"END OF MAIN FUNCTION\n";
}