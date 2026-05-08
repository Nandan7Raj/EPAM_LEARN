//
// Created by NandanRaj on 16-04-2026.
//
#include<iostream>
#include<thread>
#include <vector>
std::mutex mtx;

class Logger {
    Logger() {}
    Logger(const Logger&)=delete;
    Logger operator=(const Logger&)=delete;
public:
    static Logger& getInstance() {
        //Since C++11, this is guaranteed:
        //Initialization of function-local static variables is thread-safe
        static Logger l;
        return l;
    }
    void print() const {

        std::cout<<"Address of obj created by thread "<<std::this_thread::get_id()<<" is "<<this<<std::endl;
    }
};

void worker() {
    {
        std::lock_guard<std::mutex> lock(mtx);
        Logger&l = Logger::getInstance();
        l.print();
    }
}

int main() {
    std::vector<std::thread> Threads;
    for (int i=0;i<5;i++) {
        Threads.emplace_back(worker);
    }
    for (auto &thd:Threads)
        thd.join();
    std::cout<<"All are printing same address that shows singleton instance\n";
    std::cout<<"Mian Ends\n";
};