#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

bool ready = false;
std::mutex mtx;
std::condition_variable cv;

void waiter() {
    std::unique_lock<std::mutex> lock(mtx);

    // wait until ready becomes true
    cv.wait(lock, [] { return ready; });

    std::cout << "[waiter] resumed after signal\n";
}

void signaler() {
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // simulate delay

    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true; // protected write
        std::cout << "[signaler] signal sent\n";
    }

    cv.notify_one(); // notify after unlocking
}

int main() {
    std::thread t1(waiter);
    std::thread t2(signaler);

    t1.join();
    t2.join();

    std::cout << "[main] end\n";
}
