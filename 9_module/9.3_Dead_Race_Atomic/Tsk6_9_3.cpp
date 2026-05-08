//
// Created by NandanRaj on 23-04-2026.
//

#include<iostream>
#include <shared_mutex>
#include<thread>
#include<string>
#include<chrono>
#include <mutex>
std::string sharedStr="Start";
std::shared_mutex rw_mtx;

void Writer() {
    for (int i=1;i<=10;i++) {

        std::unique_lock<std::shared_mutex> lock(rw_mtx);
        sharedStr="Start "+std::to_string(i);
        std::cout<<"[WRITER] string modified to \"Start \""<<i<<std::endl;
    }
    std::this_thread::sleep_for(std::chrono::microseconds(100));
}

void Reader() {
    for (int i=0;i<5;i++) {
        std::shared_lock<std::shared_mutex> lock(rw_mtx);
        std::cout<<"[READER] "<<std::this_thread::get_id()<<" is reading "<<sharedStr<<std::endl;
    }
    std::this_thread::sleep_for(std::chrono::microseconds(100));
}

int main() {
    std::thread writerThread(Writer);

    std::vector<std::thread> readers;
    for (int i = 1; i <= 3; ++i) {
        readers.emplace_back(Reader);
    }

    writerThread.join();
    for (auto &t : readers) {
        t.join();
    }

    std::cout<<"Main ends\n";

}