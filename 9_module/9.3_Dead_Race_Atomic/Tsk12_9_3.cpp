//
// Created by NandanRaj on 29-04-2026.
//
#include<iostream>
#include<thread>
#include<barrier>
#include <vector>

void on_completion() {
    static int phase=1;
    std::cout<<"All Threads are done with phase "<<phase++<<std::endl;
}
std::barrier barriers{3,on_completion};

void worker(const int id) {
    // --- STAGE 1 ---
    std::cout << "Thread " << id << " working on Stage 1...\n";
    barriers.arrive_and_wait(); // Wait for all 3 to finish Stage 1

    // --- STAGE 2 ---
    std::cout << "Thread " << id << " working on Stage 2...\n";
    barriers.arrive_and_wait(); // Wait for all 3 to finish Stage 2
}

int main(int argc, char *argv[]) {
    std::vector<std::thread> threads;
    for (int i = 0; i < 3; ++i) threads.emplace_back(worker, i);
    for (auto& t : threads) t.join();
    return 0;}
