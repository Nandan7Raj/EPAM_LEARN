//
// Created by NandanRaj on 18-03-2026.
//
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <exception>

int counter = 0;
std::mutex mtx;

void safeIncrement(int ITERS) {
    for (int i = 0; i < ITERS; ++i) {
        std::lock_guard<std::mutex> lock(mtx);
        // Uncomment the following to simulate an exception:
        // if (i == 42) throw std::runtime_error("Oops!");
        ++counter;
        // lock is released automatically, even if exception occurs
    }
}
int main() {
    const int THREADS = 4;
    const int ITERS = 10000;
    std::vector<std::thread> tg;

    for (int i = 0; i < THREADS; ++i)
        tg.emplace_back(safeIncrement, ITERS);

    for (auto& t : tg)
        t.join();

    std::cout << "Final counter value: " << counter << std::endl;
    return 0;
}
