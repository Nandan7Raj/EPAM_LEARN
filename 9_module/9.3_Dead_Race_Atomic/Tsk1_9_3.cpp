//
// Created by NandanRaj on 22-04-2026.
//
#include<iostream>
#include<thread>
#include<chrono>
std::mutex mtx1,mtx2;
void ThreadA() {
    std::lock_guard<std::mutex> lock1(mtx1);
    std::cout<<"Thread A locked mtx1\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout<<"Thread A trying to lock mtx2\n";
    std::lock_guard<std::mutex> lock2(mtx2);
    std::cout<<"Thread A locked mtx2\n";

}

void ThreadB() {
    std::lock_guard<std::mutex> lock1(mtx2);
    std::cout<<"Thread B locked mtx2\n";

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout<<"Thread B trying to lock mtx1\n";
    std::lock_guard<std::mutex> lock2(mtx1);
    std::cout<<"Thread B locked mtx1\n";

}

int main() {
    std::thread tA(ThreadA);
    std::thread tB(ThreadB);
    tA.join();
    tB.join();
    std::cout<<"END OF MAIN\n";
}