//
// Created by NandanRaj on 29-04-2026.
//
#include <cmath>
#include<iostream>
#include<thread>
#include<latch>
std::latch system_ready(4);// Initial count 4

void multi_loder() {
    std::cout << "Loading Shaders...\n";
    std::cout << "Loading Textures...\n";
    std::cout << "Loading Meshes...\n";
    // We finished 3 tasks, so we decrement the latch by 3 at once
    system_ready.count_down(3);
}
void single_loder() {
    std::cout<<"loading connection\n";
    system_ready.count_down();
}

int main(int argc, char *argv[]) {
    std::thread t1(multi_loder);
    std::thread t2(single_loder);

    std::cout << "Waiting for all system to lode\n";
    system_ready.wait();// Blocks here until count_sown become zero
    std::cout << "All 4 systems ready! Game starting...\n";
    t1.join();
    t2.join();
}
