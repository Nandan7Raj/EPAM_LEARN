//
// Created by NandanRaj on 15-04-2026.
//
#include<iostream>
#include <mutex>
#include<thread>
#include <vector>
int counter=0;
std::mutex mtx;
void incrLockGuard() {
    for (int i=0;i<1000;i++) {
        std::lock_guard<std::mutex> lock(mtx)  ;
        ++counter;
    }
}

void incrUniqueLock() {
    for (int i = 0; i < 1000; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        ++counter;
        // Could call lock.unlock(), relock(), etc. here if needed.
        // Demonstrating manual unlock (not needed here, just for learning)
        lock.unlock();

        // Some non-critical work could go here

        lock.lock(); // relock if needed
    }
}

int main() {
    std::thread t_lock(incrLockGuard);
    std::thread t_unique(incrUniqueLock);
    t_lock.join();
    t_unique.join();

    std::cout<<"Counter value: "<<counter<<"\n MAIN ENDS\n";
}