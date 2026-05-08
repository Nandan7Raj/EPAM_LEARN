//
// Created by NandanRaj on 21-04-2026.
//
#include<iostream>
#include<thread>
#include<queue>
#include<mutex>
#include<condition_variable>
std::queue<int> buffer;
std::mutex mtx;
std::condition_variable cv;
bool done = false;

void producer() {
    for (int i=1;i<=20;i++) {
        std::lock_guard<std::mutex> lock(mtx);
        buffer.push(i);
        std::cout<<"Item "<<i<<" is pushed in buffer\n";
        done=true;
    }
    cv.notify_one();
}

void consumer() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);

        cv.wait(lock,[] {
            return !buffer.empty() || done;
        });

        if (!buffer.empty()) {
            int val=buffer.front();
            buffer.pop();
            lock.unlock();
            std::cout << "Consumed: " << val << std::endl;
        }
        else if (done) {
            break;  // exit loop safely
        }
    }
}
int main() {
    std::thread prd_t(producer);
    std::thread con_t(consumer);
    prd_t.join();
    con_t.join();
    std::cout<<"Main Ends\n";
}
