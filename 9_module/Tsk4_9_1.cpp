//
// Created by NandanRaj on 15-04-2026.
//
#include<iostream>
#include<thread>
#include <vector>
int counter=0;
std::mutex mtx;
void incrementFunc() {
    for (int i=0;i<1000;i++) {
        std::lock_guard<std::mutex> lock(mtx)  ;
        counter++;
    }
}
int main() {
    std::vector<std::thread> Threads;
    for (int i=0;i<4;i++) {
        Threads.emplace_back(incrementFunc);
    }
    for (auto &thd:Threads)
        thd.join();

    std::cout<<"Counter value: "<<counter<<"\n MAIN ENDS\n";
}
