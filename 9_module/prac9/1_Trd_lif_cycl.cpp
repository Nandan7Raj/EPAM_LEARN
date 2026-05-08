//
// Created by NandanRaj on 14-04-2026.
//
#include<iostream>
#include<thread>
#include<chrono>

void func(int id,int time) {
    std::cout<<"Thread: "<<id<<" is starting work...\n";
    for (int i=0;i<10;i++) {
        std::cout<<"Func "<<i<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout<<"other thread pause\n";
    std::this_thread::sleep_for(std::chrono::seconds(time)); //
    std::cout<<"Thread: "<<id<<" finished after "<<time<<" sec\n";
}

int main(int argc,char *argv[]) {
    std::cout << "--- START OF MAIN ---\n\n";

    // 1. THE JOIN EXAMPLE (The Waiter)
    std::cout << "Scenario 1: Using JOIN\n";
    std::thread t1(func, 1, 2);
    std::cout << "Main: I just started Thread 1. Now I will wait for it...\n";
    for (int i=0;i<10;i++) {
        std::cout<<"Main (join) "<<i<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

    }
    t1.join(); // Main pauses here

    std::cout << "Main: Thread 1 is done! I can move on.\n\n";

    // 2. THE DETACH EXAMPLE (The Background Worker)
    // std::cout << "Scenario 2: Using DETACH\n";
    // std::thread t2(func, 2,1);
    // t2.detach(); // Main does NOT pause
    // std::this_thread::sleep_for(std::chrono::milliseconds(500));
    //
    // for (int i=0;i<100;i++) {
    //     std::cout<<"Main (detach) "<<i<<std::endl;
    // }
    //
    // //
    // std::cout << "--- END OF MAIN ---\n";
    //
    // // Adding a tiny pause so you can see if the detached thread tries to print
    // // before the whole process shuts down.
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
}