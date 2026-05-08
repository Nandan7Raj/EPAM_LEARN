//
// Created by NandanRaj on 23-04-2026.
//
#include<iostream>
#include<thread>
#include <atomic>
#include <vector>
std::atomic<int> counter =0;

//increment():
//Each thread increments the shared counter 1000 times.

void increment() {
    for (int i = 0; i < 1000; i++) {
        counter++;  //Atomic → No race condition
    }
}

int main() {
    // Initial value of counter
    std::cout << "Initial Counter value = " << counter << std::endl;

    std::vector<std::thread> vec;

    for (int i=0;i<5;i++)
        vec.emplace_back(increment);

    for (auto &thr:vec)
        thr.join();

    //  Expected value: 5 × 1000  = 5000
    std::cout << "Expected Counter value = 5000" << std::endl;

    // Actual value: As counter is atomic, this will be 5000
    std::cout << "Final Counter value = " << counter << std::endl;
}

