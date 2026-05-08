//
// Created by NandanRaj on 04-05-2026.
//

#include<iostream>
#include<thread>
#include<shared_mutex>
#include<mutex>
#include<chrono>

std::shared_mutex shrd_mtx;
std::mutex mtx;
int data=0;

void reader() {
    for (int i=1;i<=5;i++)
    {
        std::shared_lock<std::shared_mutex> lock(shrd_mtx);
        std::cout<<"[reader id] "<<i<<" reads data = "<<data<<std::endl;
        std::this_thread::sleep_for(std::chrono::microseconds(100));
    }
}

void writer() {
    for (int i=1;i<=5;i++)
    {
        std::unique_lock<std::mutex> lock(mtx);
        data++;
        std::cout<<"[writer id] "<<i<<" writes data = "<<data<<std::endl;
        std::this_thread::sleep_for(std::chrono::microseconds(250));
    }
}

int main(int argc, char *argv[]) {
    std::vector<std::jthread> readerT;
    std::vector<std::jthread> writerT;
    for (int i=0;i<4;i++) {
        readerT.emplace_back(reader);
    }
    for (int i=0;i<4;i++) {
        writerT.emplace_back(writer);
    }

    std::cout<<"Main Ends";

}
