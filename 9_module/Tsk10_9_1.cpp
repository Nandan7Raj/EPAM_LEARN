//
// Created by NandanRaj on 16-04-2026.
//

#include<iostream>
#include <mutex>
#include<thread>
#include <vector>
std::mutex mtx;

class Logger {

    static Logger* instance;
    // Ensures initialization happens only once (thread-safe)
    static std::once_flag initFlag;

    Logger()=default;// Private constructor → prevents direct object creation

public:
    // Delete copy constructor → prevents copying
    Logger(const Logger&) = delete;

    // Delete assignment operator → prevents reassignment
    Logger& operator=(const Logger&) = delete;

    // Static method to access singleton instance
    static Logger& getInstance() {
        // call_once guarantees this block runs ONLY once
        std::call_once(initFlag, []() {
            instance = new Logger();  // create singleton
        });

        return *instance; // return reference to same object
    }

    // Logging function
    void log(const std::string& msg) const {
        std::cout << "[Thread " << std::this_thread::get_id() << "] "
                  << msg
                  << " | Instance Address: " << this
                  << std::endl;
    }
};


// Worker function executed by each thread
void worker(int id) {
    Logger& Logger = Logger::getInstance();
    Logger.log("Hello from worker " + std::to_string(id));
}

int main() {
    std::vector<std::thread> threads;

    for (int i = 1; i <= 4; i++) {
        threads.emplace_back(worker, i);
    }

    for (auto &t : threads) {
        t.join();
    }

    std::cout << "All threads used same Logger instance\n";
}