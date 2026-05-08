//
// Created by NandanRaj on 29-04-2026.
//
#include<iostream>
#include<thread>
#include<semaphore>
#include <vector>

std::counting_semaphore<2> sem(2);

void worker(int id) {

    sem.acquire();
    std::cout<<"Thread: "<<id<<" got access and working now\n";
    std::this_thread::sleep_for(std::chrono::microseconds(100));
    std::cout<<"Thread: "<<id<<" is done and now releasing\n";
    sem.release();

}

int main(int argc, char *argv[]) {
    std::vector<std::thread> threads;
    for (int i=1;i<=5;i++) {
        threads.emplace_back(worker,i);
    }
    for (auto &t:threads)
        t.join();
    std::cout << "Main Ends\n";
}
