//
// Created by NandanRaj on 23-04-2026.
//

#include<iostream>
#include<thread>
#include <vector>

volatile int counter=0;
/*
*The volatile keyword in C++ tells the compiler that don’t optimize it.”
Normally, the compiler may:
Cache variables in registers
Remove repeated reads (optimization)

But with volatile:
Every read/write must happen from memory
Compiler cannot optimize away accesses
 */

void increment() {
    for (int i = 0; i < 1000; i++) {
        counter++;
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

    // Actual value: As counter is volatile, this will be less than 5000
    std::cout << "Final Counter value = " << counter << std::endl;
}