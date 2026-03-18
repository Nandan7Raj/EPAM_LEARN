//
// Created by NandanRaj on 16-03-2026.
//
#include<iostream>
#include <vector>
#include<utility>
#include <chrono>

class LargeArray {
    std::vector<int> vec;
public:
    LargeArray(size_t n): vec(n,0) {
        std::cout << "Constructed LargeArray with " << n << " elements\n";

    }
    // copy constructor
    LargeArray(const LargeArray& other):vec(other.vec) {
        std::cout << "Copied LargeArray (deep copy)\n";

    }
    // move copy
    LargeArray(LargeArray&& other) noexcept: vec(std::move(other.vec)) {
        std::cout << "Moved LargeArray (shallow/efficient move)\n";
    }

};
int main() {
    const size_t N=1e8;
    LargeArray arr1(N);
    auto start = std::chrono::high_resolution_clock::now();
    LargeArray arr2=arr1; // copy
    auto end=std::chrono::high_resolution_clock::now();
    std::cout << "Copy time duration: "
              << std::chrono::duration<double, std::milli>(end - start).count() << " ms\n";
    start = std::chrono::high_resolution_clock::now();
    LargeArray arr3=std::move(arr1);
    end=std::chrono::high_resolution_clock::now();
    std::cout<<"Move time duration: "
             <<std::chrono::duration<double,std::milli>(end-start).count()<<" ms\n";
}