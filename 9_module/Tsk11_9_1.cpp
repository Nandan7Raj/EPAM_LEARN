//
// Created by NandanRaj on 16-04-2026.
//
#include<iostream>
#include <shared_mutex>
#include<thread>
#include<chrono>
#include <mutex>
#include <vector>

int sharedValue=0;
std::shared_mutex s_mtx;
void reader(int id) {
    for (int i=0;i<5;i++) {
        {
            std::shared_lock<std::shared_mutex> lock(s_mtx);
            std::cout << "[Reader " << id << "] Thread "
                      << std::this_thread::get_id()
                      << " reads value: " << sharedValue << "\n";
        }
        // simulate work outside lock
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

void writer() {
    for (int i=0;i<5;i++){
    {
        std::unique_lock<std::shared_mutex> lock(s_mtx);
        sharedValue++;
        std::cout << "[Writer] Thread "
                      << std::this_thread::get_id()
                      << " updated value to: " << sharedValue << "\n";
    }
    std::this_thread::sleep_for(std::chrono::seconds(2));
}
}

int main() {
    std::vector<std::thread> readerThread;
    readerThread.reserve(5);
for (int i=1;i<5;i++) {
        readerThread.emplace_back(reader,i);
    }
    std::thread writerThread(writer);
    for (auto &thd:readerThread)
        thd.join();
    writerThread.join();

    std::cout<<"MAIN ENDS\n";
}


