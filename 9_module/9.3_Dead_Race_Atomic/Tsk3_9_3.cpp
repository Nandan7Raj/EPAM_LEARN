//
// Created by NandanRaj on 22-04-2026.
//


#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex m1, m2, m3;

void ThreadA() {
    m1.lock();
    std::cout << "[Thread A] Locked m1\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    m2.lock();
    std::cout << "[Thread A] Locked m2\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    m3.lock();
    std::cout << "[Thread A] Locked m3\n";

    m1.unlock();
    m2.unlock();
    m3.unlock();
}

void ThreadB() {
    m1.lock();
    std::cout << "[Thread B] Locked m1\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    m2.lock();
    std::cout << "[Thread B] Locked m2\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    m3.lock();
    std::cout << "[Thread B] Locked m3\n";

    m1.unlock();
    m2.unlock();
    m3.unlock();
}

void ThreadC() {
    m1.lock();
    std::cout << "[Thread C] Locked m1\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    m2.lock();
    std::cout << "[Thread C] Locked m2\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    m3.lock();
    std::cout << "[Thread C] Locked m3\n";

    m1.unlock();
    m2.unlock();
    m3.unlock();
}

int main() {
    std::thread t1(ThreadA);
    std::thread t2(ThreadB);
    std::thread t3(ThreadC);

    t1.join();
    t2.join();
    t3.join();

    std::cout << "END OF MAIN\n";
}
