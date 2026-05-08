//
// Created by NandanRaj on 22-04-2026.
//


#include <iostream>
#include <thread>
#include <mutex>

// Shared global counter (not thread-safe)
int counter = 0;
std::mutex mtx;


//increment():
//Each thread increments the shared counter 1000 times.

void increment() {
    for (int i = 0; i < 1000; i++) {
        {
            std::lock_guard<std::mutex> lock(mtx); // locking shared resource
            ++counter;
        }
    }
}

int main() {

    // Initial value of counter
    std::cout << "Initial Counter value = " << counter << std::endl;

    // Creating 5 threads. Each thread increments counter 1000 times.
    std::thread t1(increment);
    std::thread t2(increment);
    std::thread t3(increment);
    std::thread t4(increment);
    std::thread t5(increment);

    // Wait for all threads to complete
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();


    //  Expected value: 5 × 1000  = 5000
    std::cout << "Expected Counter value = 5000" << std::endl;

    // Actual value: Due to thread synchronization, this will be 5000
    std::cout << "Final Counter value = " << counter << std::endl;

    return 0;
}
