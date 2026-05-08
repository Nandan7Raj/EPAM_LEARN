//
// Created by NandanRaj on 16-04-2026.
//
#include<iostream>
#include<thread>
#include <condition_variable>
#include<mutex>
std::mutex mtx;
std::condition_variable cv;
const int MAX = 20;
bool even=false;
void printOdd() {
    for (int i=1;i<=MAX;i+=2) {
        {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock,[] {
                return !even;
            });
            std::cout<<"odd: "<<i<<std::endl;
            even=true;
            cv.notify_one();
        }

    }
}

void printEven() {
    for (int i=2;i<=MAX;i+=2) {
        {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock,[] {
                return even;
            });
            std::cout<<"even: "<<i<<std::endl;
            even=false;
            cv.notify_one();
        }
    }
}
int main() {
    std::thread odd_t(printOdd);
    std::thread even_t(printEven);
    odd_t.join();
    even_t.join();
}