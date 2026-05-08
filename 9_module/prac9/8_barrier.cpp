//
// Created by NandanRaj on 29-04-2026.
//
#include <iostream>
#include <barrier>
#include <thread>
#include <vector>
#include <string>


void on_completion() noexcept{
    // 1. Completion function: Runs once every time the barrier is full
    static int phase=1;
    std::cout << "--- Phase " << phase++ << " Complete ---\n";
}
std::barrier sync_point(3, on_completion);

void work(int id) {
    // --- STAGE 1 ---
    std::cout << "Thread " << id << " working on Stage 1...\n";
    sync_point.arrive_and_wait(); // Wait for all 3 to finish Stage 1

    // --- STAGE 2 ---
    std::cout << "Thread " << id << " working on Stage 2...\n";
    sync_point.arrive_and_wait(); // Wait for all 3 to finish Stage 2
};

int main(int argc, char *argv[]) {
    std::vector<std::thread> threads;
    for (int i = 0; i < 3; ++i) threads.emplace_back(work, i);
    for (auto& t : threads) t.join();
    return 0;
}


