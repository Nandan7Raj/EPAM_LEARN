//
// Created by NandanRaj on 15-04-2026.
//
#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include <optional>
std::optional<int> buffer;
std::mutex mtx;
std::condition_variable cv;

void producer() {
    for (int i=1;i<=10;i++) {
        std::unique_lock<std::mutex> lock(mtx);
        //wait until buffer is  empty (i.e buffer should be empty to continue )
        cv.wait(lock,[] {
            return !buffer.has_value();
        });

        // Produce value
        buffer = i;
        std::cout << "Produced: " << i << "\n";

        // Notify consumer
        cv.notify_one();
    }
}

void consumer() {
    for (int i=1;i<=10;i++) {
        std::unique_lock<std::mutex> lock(mtx);
        //wait until buffer is not empty(i.e buffer should not be empty to continue )
        cv.wait(lock,[] {
            return buffer.has_value();
        });

        // Consume value
        std::cout << "Consumed: " << *buffer << "\n";
        buffer.reset(); // make buffer empty

        // Notify producer
        cv.notify_one();

    }
}


int main() {
    std::thread t1(producer);
    std::thread t2(consumer);

    t1.join();
    t2.join();

    std::cout << "MAIN ENDS\n";
}

