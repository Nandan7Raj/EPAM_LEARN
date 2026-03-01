//
// Created by NandanRaj on 16-02-2026.
//
#include<iostream>
#include<fstream>
#include<chrono>
#include<iomanip>
#include <thread>

class Logger {
    std::ofstream member;
    public:
    Logger(const std::string& s):member(s+".txt",std::ios::app) {
        if (!member) {
            std::cerr<<"Unable to open output file"<<std::endl;
        }
    }
    void log(const std::string& message) {
        auto now = std::chrono::system_clock::now();

        std::time_t t = std::chrono::system_clock::to_time_t(now);

        member << "["
               << std::put_time(std::localtime(&t), "%Y-%m-%d %H:%M:%S")
               << "] : "
               << message << '\n';
    }
    
};
int main() {
   Logger l("Tsk9");
    l.log("First Msg");
    std::this_thread::sleep_for(std::chrono::seconds(4));
    l.log("Second Msg");
    std::this_thread::sleep_for(std::chrono::seconds(4));
    l.log("Third Msg");

}