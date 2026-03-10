//
// Created by NandanRaj on 10-03-2026.
//
#include<iostream>
int main() {
    int counter=0;
    auto next=[counter]()mutable {
        counter++;
        return counter;
    };
    // single functor so counter will be same for all
    std::cout << "next(): " << next() << std::endl; // 1
    std::cout << "next(): " << next() << std::endl; // 2
    std::cout << "next(): " << next() << std::endl; // 3
    std::cout << "Outer counter: " << counter << std::endl; // 0

    return 0;
}

// behind the scene
// #include <iostream>
//
// class __LambdaNext {
// private:
//     int counter;   // captured by value becomes data member
//
// public:
//     // constructor gets captured values
//     __LambdaNext(int c) : counter(c) {}
//
//     // mutable means operator() is NOT const
//     int operator()() {
//         counter++;
//         return counter;
//     }
// };
//
// int main() {
//     int counter = 0;
//
//     __LambdaNext next(counter);   // capture current value of outer counter
//
//     std::cout << "next(): " << next() << std::endl; // 1
//     std::cout << "next(): " << next() << std::endl; // 2
//     std::cout << "next(): " << next() << std::endl; // 3
//
//     std::cout << "Outer counter: " << counter << std::endl; // 0
// }

// This line:
//
// auto next = [counter]() mutable { ... };
//
// does not recreate lambda each call.
//
// It creates lambda object once.