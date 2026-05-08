//
// Created by NandanRaj on 17-04-2026.
//

#include<iostream>
#include<thread>
#include<chrono>
#include <mutex>
std::mutex mtx1,mtx2;
void threadA() {

    std::lock(mtx1, mtx2);
    std::cout<<"ThreadA got mutex1\n";
    std::lock_guard<std::mutex> lock1(mtx1,std::adopt_lock);
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    std::cout<<"ThreadA got mutex2\n";
    std::lock_guard<std::mutex> lock2(mtx2,std::adopt_lock);
}
void threadB() {
    std::lock(mtx1,mtx2);
    std::cout<<"ThreadB got mutex2\n";
    std::lock_guard<std::mutex> lock1(mtx2,std::adopt_lock);
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    std::cout<<"ThreadB got mutex1\n";
    std::lock_guard<std::mutex> lock2(mtx1,std::adopt_lock);
}
int main() {
    std::thread t1(threadA);
    std::thread t2(threadB);
    t1.join();
    t2.join();
}