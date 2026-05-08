//
// Created by NandanRaj on 17-04-2026.
//
#include<iostream>
#include<thread>
#include<future>
#include<chrono>
int longComputation() {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return 42;
}
int main() {
    std::future<int> fu=std::async(std::launch::async,longComputation);
    const int result=fu.get();
    std::cout<<"RESULT: "<<result;

}