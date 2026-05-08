//
// Created by NandanRaj on 15-04-2026.
//
#include<iostream>
#include<thread>
#include<chrono>
void worker() {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout<<"Current Thread id is "<<std::this_thread::get_id()<<std::endl;
    std::cout<<"Work Completed\n";
}
int main() {
    std::thread t1(worker);
    t1.detach();
    std::cout<<"MAIN ENDS\n";
}