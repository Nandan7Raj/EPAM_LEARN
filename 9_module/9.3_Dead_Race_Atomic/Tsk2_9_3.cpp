//
// Created by NandanRaj on 22-04-2026.
//

#include<iostream>
#include<thread>
#include<chrono>
#include <mutex>
std::mutex mtx1,mtx2;
void ThreadA() {
    std::cout << "[Thread A] Trying to lock mtx1 & mtx2\n";

    // Atomic locking (prevents deadlock)
    std::lock(mtx1, mtx2);

    // Adopt ownership of already locked mutexes
    std::lock_guard<std::mutex> lock1(mtx1, std::adopt_lock);
    std::lock_guard<std::mutex> lock2(mtx2, std::adopt_lock);

    std::cout << "[Thread A] Acquired both locks\n";

    // Simulate work
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "[Thread A] Finished work, releasing locks\n";
}

void ThreadB() {
    std::cout << "[Thread B] Trying to lock mtx1 & mtx2\n";

    std::lock(mtx1, mtx2);

    // Keep order consistent for clarity (not required but good practice)
    std::lock_guard<std::mutex> lock1(mtx1, std::adopt_lock);
    std::lock_guard<std::mutex> lock2(mtx2, std::adopt_lock);

    std::cout << "[Thread B] Acquired both locks\n";

    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "[Thread B] Finished work, releasing locks\n";
}

int main() {

    std::cout << "Starting threads...\n";
    std::thread tA(ThreadA);
    std::thread tB(ThreadB);
    tA.join();
    tB.join();
    std::cout<<"END OF MAIN\n";
}