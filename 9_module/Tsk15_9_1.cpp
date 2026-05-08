//
// Created by NandanRaj on 19-04-2026.
//
#include<iostream>
#include<thread>
#include<future>
#include<chrono>
int worker(std::future<int>& f) {
    int res=f.get();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return res*2;
}
int main() {
    std::promise<int> p;
    std::future<int> fu=p.get_future();
    std::future<int> f=std::async(std::launch::async, worker, std::ref(fu));
    p.set_value(8);
    std::cout<<"Result: "<<f.get();
}